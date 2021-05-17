#ifndef BGMATTING_H
#define BGMATTING_H

#undef slots    //qt的宏会与libtorch中的slots函数冲突
#include <torch/torch.h>
#include <torch/script.h>
#define slots Q_SLOTS
#include <opencv2/opencv.hpp>

class BgMatting
{
public:
    BgMatting(const std::string& dev="cpu", float backbone_scale=0.25, int refine_sample_pixels=80000);
    void load(const std::string& path);
    at::Tensor forward(const cv::Mat img, const cv::Mat bg);
    bool is_valid();
    void setBackboneScale(float value);
    void setRefineSamplePixels(int value);
    cv::Mat imgBlend(const cv::Mat& new_bg, const cv::Mat& src, const torch::Tensor &pha);
    cv::Mat denormalize(torch::Tensor m, const int k);
    torch::Tensor getpha() const;

private:
    torch::jit::Module model;
    torch::Device device;

    float backbone_scale;
    int refine_sample_pixels;

    bool is_loaded;
};

#endif // BGMATTING_H
