#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
bool ROI_AddImage();
bool LinearBlending();
bool ROI_LinearBlending();
int main(int argc,char **argv)
{
    if(ROI_AddImage()&&LinearBlending()&&ROI_LinearBlending())
    {
        cout<<"运行成功";
    }
   waitKey(0);
    return 0;
}
bool ROI_AddImage()
{
    //【1】读入图像
    Mat srcImage1=imread("./dota.jpg");
    Mat logoImage=imread("./dota_logo.jpg");
    if(!srcImage1.data)
    {
        cout<<"dota.jpg loaded fail"<<endl;
        return 1;
    }
    if(!logoImage.data)
    {
        cout<<"logo.jpg loaded fail "<<endl;
        return 1;
    }
    //【2】定义一个Mat类型并给其设定ROI区域
    Mat imageROI=srcImage1(Rect(0,0,logoImage.cols,logoImage.rows));
    //【3】加载掩膜（必须是灰度图）
    Mat mask=imread("./dota_logo.jpg",0);
    //【4】将掩膜复制到ROI
    logoImage.copyTo(imageROI,mask);
    //【5】显示结果
    imshow("[1]利用ROI实现图像叠加示例窗口",srcImage1);
    return true;
}
bool LinearBlending()
{
//[0]定义一些局部变量
double alphavalue=0.5;
double betavalue;
Mat dstImage;
//[1]读取图像（两幅图片需为同样的类型和尺寸）
Mat srcImage2=imread("./mogu.jpg");
Mat srcImage3=imread("./rain.jpg");
    if(!srcImage2.data)
    {
        cout<<"mogo.jpg loaded fail"<<endl;
        return 1;
    }
    if(!srcImage3.data)
    {
        cout<<" rain.jpg loaded fail"<<endl;
        return 1;
    }
//[2]进行图像混合加权操作
betavalue=(1.0-alphavalue);
    addWeighted(srcImage2,alphavalue,srcImage3,betavalue,0.0,dstImage);
//【3】创建并显示原图窗口
imshow("[2]线性混合示例窗口【原图】",srcImage2);
imshow("[3]线性混合示例窗口【效果图】",dstImage);
    return true;
}
bool ROI_LinearBlending()
{
    //[1]读取图像
    Mat srcImage4=imread("dota_pa.jpg",1);
    Mat logoImage=imread("dota_logo.jpg");
    if(!srcImage4.data)
    {
        cout<<"loaded fail"<<endl;
        return 1;
    }
    if(!logoImage.data)
    {
        cout<<"loaded fail"<<endl;
        return 1;
    }
    //[2]定义一个Mat类型并给其设定ROI区域
    Mat imageROI=srcImage4(Rect(0,0,logoImage.cols,logoImage.rows));
  //  Mat imageROI=srcImage4(Range(0,0+logoImage.rows),Range(0,0+logoImage.cols));
    //[3]将logo加到原图上
    addWeighted(imageROI,0.5,logoImage,0.3,0.0,imageROI);
    //[4]显示结果
    imshow("[4]区域线性图像混合示例窗口",srcImage4);
    return true;

}