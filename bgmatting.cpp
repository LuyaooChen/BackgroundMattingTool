#include "bgmatting.h"
#include <iostream>
#include <QDebug>

BgMatting::BgMatting(const std::string& dev, float backbone_scale, int refine_sample_pixels) :
    device(dev), backbone_scale(backbone_scale), refine_sample_pixels(refine_sample_pixels), is_loaded(false)
{}

void BgMatting::load(const std::string& path)
{
    model = torch::jit::load(path);
    model.setattr("backbone_scale", backbone_scale);
    model.setattr("refine_mode", "sampling");
    model.setattr("refine_sample_pixels", refine_sample_pixels);
    model.to(device);
    model.eval();

    is_loaded=true;
}

bool BgMatting::is_valid()
{
    return is_loaded;
}

void BgMatting::setBackboneScale(float value)
{
    if(backbone_scale==value) return;
    backbone_scale=value;
    model.setattr("backbone_scale", backbone_scale);
}

void BgMatting::setRefineSamplePixels(int value)
{
    if(refine_sample_pixels==value) return;
    refine_sample_pixels=value;
    model.setattr("refine_sample_pixels", refine_sample_pixels);
}

// 在调用之前应该检查is_valid
torch::Tensor BgMatting::forward(const cv::Mat img, const cv::Mat bg)
{
    auto precision = torch::kFloat32;
    auto imgTensor = torch::from_blob(img.data,{1,img.rows,img.cols,3},torch::kU8);
    auto bgTensor = torch::from_blob(bg.data,{1,bg.rows,bg.cols,3},torch::kU8);

    imgTensor = imgTensor.permute({0, 3, 1, 2}).to(device).to(precision).div(255.0);
    bgTensor = bgTensor.permute({0, 3, 1, 2}).to(device).to(precision).div(255.0);
    auto outputs = model.forward({imgTensor, bgTensor}).toTuple()->elements();
    auto phaTensor = outputs[0].toTensor().squeeze().detach().to(torch::kCPU);
    return phaTensor;

    //输出了奇怪的东西
    //auto fgrTensor = outputs[1].toTensor().squeeze().detach();
    //fgrTensor = fgrTensor.permute({1,2,0}).mul(255).clamp(0, 255).to(torch::kU8).to(torch::kCPU);
    //qDebug()<<fgrTensor.sizes()[0]<<fgrTensor.sizes()[1];
    //cv::Mat fgr(fgrTensor.sizes()[0], fgrTensor.sizes()[1], CV_8UC3);
    //std::memcpy(fgr.data, fgrTensor.data_ptr(), sizeof(torch::kU8)*fgrTensor.numel());
    //return fgr;

//    cv::Mat ret(phaTensor.sizes()[0],phaTensor.sizes()[1],CV_32FC1);  //本想返回mat类型，但这里这样转换会导致图片被截断。还未知原因。
//    std::memcpy(ret.data,phaTensor.data_ptr(),sizeof(torch::kFloat)*phaTensor.numel());
//    return ret;
}

cv::Mat BgMatting::imgBlend(const cv::Mat &new_bg, const cv::Mat &src, const torch::Tensor &pha)
{
    CV_Assert(new_bg.channels()==3 && src.channels()==3);
    cv::Mat bg_ = new_bg.clone();
    cv::Mat fg_ = src.clone();
//    cv::Mat pha_ = pha.clone();

    torch::Tensor bgTensor = torch::from_blob(bg_.data, {bg_.rows, bg_.cols, 3}, torch::kU8).to(torch::kFloat32);
    torch::Tensor fgTensor = torch::from_blob(fg_.data, {fg_.rows, fg_.cols, 3}, torch::kU8).to(torch::kFloat32);
//    torch::Tensor phaTensor = torch::from_blob(pha_.data, {pha_.rows, pha_.cols, 1}, torch::kFloat32);
    torch::Tensor pha_ = pha.clone().unsqueeze(2);
    torch::Tensor comTensor = fgTensor.multiply(pha_) + bgTensor.multiply(1-pha_); 
    comTensor = comTensor.clamp(0,255).to(torch::kU8);
    cv::Mat com(comTensor.sizes()[0], comTensor.sizes()[1], CV_8UC3);
    std::memcpy(com.data, comTensor.data_ptr(), sizeof(torch::kU8)*comTensor.numel()); 
    return com; //composite
}

////将0~1的浮点型转化为放大k倍的整型。
cv::Mat BgMatting::denormalize(torch::Tensor m, const int k)
{
    m = m.mul(k).clamp(0,k).to(torch::kU8);
    cv::Mat ret(m.sizes()[0], m.sizes()[1], CV_8UC1);
    std::memcpy(ret.data, m.data_ptr(), sizeof(torch::kU8)*m.numel());
    return ret;
}
