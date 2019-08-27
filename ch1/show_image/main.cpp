/*图像腐蚀 图像模糊 canny边缘检测*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
    //载入原图
    Mat srcImage=imread("/home/pxx/Documents/opencv/ch1/show_image/1.jpg");
    //显示原图
    imshow("【原图】腐蚀操作",srcImage);
    //进行腐蚀操作
    Mat element=getStructuringElement(MORPH_RECT,Size(15,15));
    Mat dstImage1;
    erode(srcImage,dstImage1,element);
    //显示效果图
    imshow("【效果图】腐蚀操作",dstImage1);

    //进行均值滤波操作
    Mat dstImage2;
    blur(srcImage,dstImage2,Size(7,7));
    //显示效果图
    imshow("【效果图】均值滤波",dstImage2);


    //canny边缘检测
    Mat edge,grayImage;//参数定义
    //【1】原图转成灰度图
    cvtColor(srcImage,grayImage,CV_BGR2GRAY);
    //【2】先使用3×3内核来降噪
    blur(grayImage,edge,Size(3,3));
    //【3】运行canny算子
    Canny(edge,edge,3,9,3);
    //【4】显示效果图
    imshow("【效果图】Canny边缘检测",edge);




    waitKey(0); //等待任意键按下
    return  0;
}