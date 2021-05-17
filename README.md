# BackgroundMattingTool
## 1.介绍

随手开发的一个一键抠图换背景的小程序。用户需要提供背景图片，就能够一键抠出前景。目前主要设计用来给证件照更换背景，可以用鼠标选择背景颜色，对渐变色背景也能有比较好的适应性。该抠图方法基于[BackgroundMattingV2](https://github.com/PeterL1n/BackgroundMattingV2).

![window](https://github.com/LuyaooChen/BackgroundMattingTool/blob/main/window.gif)

### 2.依赖

Qt5, test on 5.15.2

OpenCV, test on 3.4.13

libtorch, test on 1.8.1 cpu version

CUDA(optional), 如果你想跑GPU版本的libtorch,但我没有测试

## 3.安装与使用方法

**最简单的方法: 直接下载本仓库发布的release,解压即用. 依赖已打包在内.**

### 3.1从源码安装
1. 安装上述依赖

2. 从本仓库下载源码

3. 编译

4. **将weights文件夹和imgs文件夹移至可执行文件所在目录下**

5. 运行

使用方法我都在ui上提示出来了.

## 4.注意事项
1. imgs文件夹中是预设的待更换背景,你也可以添加或更换成其他的,并修改相应代码.
2. CPU版本似乎不支持半精度运算,所以本仓库使用的是fp32版本的权重文件.如果你想使用其他版本的权重文件,可去原仓库下载.
3. 未在极端大小的的图片上进行测试,过大的图片可能导致爆内存.测试约4k分辨率的图片峰值内存占用2G多.
4. 按下抠图键时,若cpu版本可能略有卡顿,请耐心等一下. 本想把网络推理这部分放到子线程中,以不阻塞ui. 但是,我在QThread的run方法中进行张量运算时,某些操作会导致libtorch抛出异常,如.toTensor(). 未知原因.

## 5.参考

[BackgroundMattingV2](https://github.com/PeterL1n/BackgroundMattingV2) 
