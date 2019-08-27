#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

int main()
{
    //图像的载入和显示
    Mat girl=imread("/home/pxx/Documents/opencv/ch3/picture_blending/girl.jpg");
    if(!girl.data)
        cout<<"no input!";
    namedWindow("【1】动漫图");
    imshow("【1】动漫图",girl);
    cout<<"girl height:"<<girl.rows<<" girl width:"<<girl.cols<<endl;

    //图像混合
   Mat image=imread("/home/pxx/Documents/opencv/ch3/picture_blending/dota.jpg");
   Mat logo=imread("/home/pxx/Documents/opencv/ch3/picture_blending/dota_logo.jpg");
   namedWindow("【2】原画图");
   imshow("【2】原画图",image);
    namedWindow("【3】logo图");
    imshow("【3】logo图",logo);
    //定义一个Mat类型，用于存放图像的ROI
    Mat imageROI;
    imageROI=image(Rect(200,350,logo.cols,logo.rows));
    //将logo加到原图上
    addWeighted(imageROI,0.5,logo,0.3,0.,imageROI);
    //显示结果
   // namedWindow("【4】原画＋logo图");
    imshow("【4】原画+logo图",image);

    //图像的输出
    imwrite("由imwrite生成的图片.jpg",image);
    waitKey(0);
    return 0;
}