#include <iostream>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

#define  WINDOW_NAME "【线性混合示例】"

const int g_nMaxAlphaValue=100; //Alpha值的最大值
int g_nAlphaValueSlider;//滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat g_srcimage1;
Mat g_srcimage2;
Mat g_dstimage;


//--------【响应滑动条的回调函数on_Trackbar()】-----//
void on_Trackbar(int,void*)
{
    //求当前Alpha相对于最大值的比例
    g_dAlphaValue=(double)g_nAlphaValueSlider/g_nMaxAlphaValue;
    //Beta值为1减去alpha值
    g_dBetaValue=(1.0-g_dAlphaValue);

    //根据Alpha和Beta值进行线性混合
    addWeighted(g_srcimage1,g_dAlphaValue,g_srcimage2,g_dBetaValue,0.0,g_dstimage);
    //显示效果图
    imshow(WINDOW_NAME,g_dstimage);
}








int main(int argc,char**argv)
{
    g_srcimage1=imread("/home/pxx/Documents/opencv/ch3/createTrackbar_function/1.jpg");
    g_srcimage2=imread("/home/pxx/Documents/opencv/ch3/createTrackbar_function/2.jpg");


    //设置滑动条初始位置20
    g_nAlphaValueSlider=20;
    //创建窗体
    namedWindow(WINDOW_NAME,1);
    //在创建的窗体中创建一个滑动条控件
    char TrackbarName[50];
    sprintf(TrackbarName,"透明值 %d",g_nMaxAlphaValue);
    createTrackbar(TrackbarName,WINDOW_NAME,&g_nAlphaValueSlider,g_nMaxAlphaValue,on_Trackbar);
    //结果在回调函数中显示
    on_Trackbar(g_nAlphaValueSlider,0);
    waitKey(0);
    return 0;
}