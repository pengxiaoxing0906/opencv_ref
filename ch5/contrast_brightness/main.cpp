
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static  void on_ContrastandBright(int,void*); //回调函数

int g_nContrastValue;//对比度值
int g_nBrightValue;//亮度值
Mat g_srcImage,g_dstImage;

int main(int argc,char**argv)
{
    //[1]读入图像
    g_srcImage=imread("./1.jpg");
    if(!g_srcImage.data)
    {
        cout<<"图片加载失败"<<endl;
        return 1;
    }
    //g_dstImage=Mat::zeros(g_srcImage.size(),g_srcImage.type());

    g_dstImage.create(g_srcImage.rows,g_srcImage.cols,g_srcImage.type());//与上一条被注释掉的语句的作用相同，创建和源图同规模同类型的黑图
    imshow("目标图",g_dstImage);
    //[2]设定对比度和初值
    g_nContrastValue=60;
    g_nBrightValue=60;
    //[3]创建效果图窗口
    namedWindow("效果图窗口",1);
    //[4]创建轨迹条
    createTrackbar("对比度","效果图窗口",&g_nContrastValue,300,on_ContrastandBright);
    createTrackbar("亮度","效果图窗口",&g_nBrightValue,200,on_ContrastandBright);
    //[5]进行回调函数初始化
    on_ContrastandBright(g_nContrastValue,0);
    on_ContrastandBright(g_nBrightValue,0);
    //[6]按下q键时，程序退出
    while (char(waitKey(1))!='q')
    {}
    return 0;
}

static  void on_ContrastandBright(int,void*)
{
    //创建窗口
    namedWindow("原始图窗口",1);
    //计算g_dstImage(i,j)=a*g_srcImage(i,j)+b
    for(int y=0;y<g_srcImage.rows;y++)
    {
        for(int x=0;x<g_srcImage.cols;x++)
        {
            for(int c=0;c<3;c++)
            {
               // g_dstImage.at<Vec3b(y,x)[c] = saturate_cast<uchar>( (g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y,x)[c])+g_nBrightValue);
                g_dstImage.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (g_nContrastValue*0.01)*( g_srcImage.at<Vec3b>(y,x)[c] ) + g_nBrightValue );
            }

        }
    }
    imshow("原始图窗口",g_srcImage);
    imshow("效果图窗口",g_dstImage);
}