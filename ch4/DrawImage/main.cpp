#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define WINDOW_NAME1 "【绘制图1】"
//#define WINDOW_NAME2 "【绘制图2】"
#define  WINDOW_WIDTH 600  //定义窗口大小的宏


void DrawEllipse(Mat img,double angle);
void DrawFilledCircle(Mat img,Point center);
//void DrawPolygon(Mat img);
//void DrawLine(Mat img,Point start,Point end);

int main(int argc,char**argv)
{
    //创建空白的Mat图像
    Mat autoImage=Mat::zeros(WINDOW_WIDTH,WINDOW_WIDTH,CV_8UC3);
    Mat rookImage=Mat::zeros(WINDOW_WIDTH,WINDOW_WIDTH,CV_8UC3);

    //[1.1]绘制椭圆
    DrawEllipse(autoImage,90);
    DrawEllipse(autoImage,0);
    DrawEllipse(autoImage,45);
    DrawEllipse(autoImage,-45);
    DrawEllipse(autoImage,30);
    DrawEllipse(autoImage,-30);
    DrawEllipse(autoImage,60);
    DrawEllipse(autoImage,-60);

    //[1.2]绘制圆心
    DrawFilledCircle(autoImage,Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2));

    imshow(WINDOW_NAME1,autoImage);

waitKey(0);
    return 0;
}
void DrawEllipse(Mat img,double angle)
{
    int thickness=2;
    int lineType=8;
    ellipse(img,Point(WINDOW_WIDTH/2,WINDOW_WIDTH/2),
            Size(WINDOW_WIDTH/4,WINDOW_WIDTH/16),
            angle,0,360,Scalar(225,129,0),
            thickness,
            lineType);
}
void DrawFilledCircle(Mat img,Point center)
{
    int thickness=-1;
    int lineType=8;
    circle(img,center,WINDOW_WIDTH/32,Scalar(0,0,225),thickness,lineType);
}

//void DrawPolygon(Mat img)
//void DrawLine(Mat img,Point start,Point end)