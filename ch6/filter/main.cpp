#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


Mat g_srcImage,g_dstImage1,g_dstImage2,g_dstImage3,g_dstImage4,g_dstImage5;
int g_nBoxFilterValue=3;//方框滤波参数值
int g_nMeanFilterValue=3;//均值滤波参数
int g_nGaussianBlurValue=3;//高斯滤波参数值
int g_nMedianBlurValue=10;//中值滤波参数值
int g_nBilateralFilterValue=10;//双边滤波


static void on_BoxFilter(int ,void*);
static void on_MeanFilter(int,void*);
static void on_GaussianBlur(int,void*);
static void on_MedianBlur(int,void*);
static void on_BilateralFilter(int,void*);

int main(int argc,char**argv)
{
   g_srcImage=imread(argv[1],1);
   if(!g_srcImage.data)
   {
       cout<<"图片读取失败！"<<endl;
       return 1;
   }
   g_dstImage1=g_srcImage.clone();
   g_dstImage2=g_srcImage.clone();
   g_dstImage3=g_srcImage.clone();
    g_dstImage4=g_srcImage.clone();
    g_dstImage5=g_srcImage.clone();
   imshow("原图",g_srcImage);

   //=======方框滤波============
   namedWindow("方框滤波",1);
   createTrackbar("内核值：　","方框滤波",&g_nBoxFilterValue,40,on_BoxFilter);
   on_BoxFilter(g_nBoxFilterValue,0);


   //======均值滤波=========
   namedWindow("均值滤波",1);
   createTrackbar("内核值：","均值滤波",&g_nMeanFilterValue,40,on_MeanFilter);
   on_MeanFilter(g_nMeanFilterValue,0);


   //======高斯滤波=======
   namedWindow("高斯滤波",1);
   createTrackbar("内核值：","高斯滤波",&g_nGaussianBlurValue,40,on_GaussianBlur);
   on_GaussianBlur(g_nGaussianBlurValue,0);

    //======中值滤波=======
    namedWindow("中值滤波",1);
    createTrackbar("内核值：","中值滤波",&g_nMedianBlurValue,40,on_MedianBlur);
    on_GaussianBlur(g_nMedianBlurValue,0);

    //======双边滤波=======
    namedWindow("双边滤波",1);
    createTrackbar("内核值：","双边滤波",&g_nBilateralFilterValue,40,on_BilateralFilter);
    on_GaussianBlur(g_nBilateralFilterValue,0);


   while(char(waitKey(1))!='q'){}

    return 0;
}
static void on_BoxFilter(int,void*)
{
    boxFilter(g_srcImage,g_dstImage1,-1,Size(g_nBoxFilterValue+1,g_nBoxFilterValue+1));
    imshow("方框滤波",g_dstImage1);
}

static void on_MeanFilter(int,void*)
{
    blur(g_srcImage,g_dstImage2,Size(g_nMeanFilterValue+1,g_nMeanFilterValue+1),Point(-1,-1));
    imshow("均值滤波",g_dstImage2);
}

static void on_GaussianBlur(int,void*)
{
    GaussianBlur(g_srcImage,g_dstImage3,Size(g_nGaussianBlurValue*2+1,g_nGaussianBlurValue*2+1),0,0);
    imshow("高斯滤波",g_dstImage3);
}

static void on_MedianBlur(int,void*)
{
    medianBlur(g_srcImage,g_dstImage4,g_nMedianBlurValue*2+1);
    imshow("中值滤波",g_dstImage4);
}
static void on_BilateralFilter(int,void*)
{
    bilateralFilter(g_srcImage,g_dstImage5,g_nBilateralFilterValue,g_nBilateralFilterValue*2,g_nBilateralFilterValue/2);
    imshow("双边滤波",g_dstImage5);
}