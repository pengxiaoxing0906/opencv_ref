#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;
using namespace std;


int main() {
    //【1】读入视频
    VideoCapture cap("/home/pxx/Documents/opencv/ch1/video/1.avi");
    Mat edges;
    if(!cap.isOpened())
        return 0 ;

    double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);  //帧宽度
    double height=cap.get(CV_CAP_PROP_FRAME_HEIGHT);//帧高度
    int frameRate = cap.get(CV_CAP_PROP_FPS);  //帧率 x frames/s
    int totalFrames = cap.get(CV_CAP_PROP_FRAME_COUNT); //总帧数

    cout<<"宽度是："<<width<<endl;
    cout<<"高度是："<<height<<endl;
    cout<<"帧率是："<<frameRate<<endl;
    cout<<"视频总帧数是："<<totalFrames<<endl;



    //【2】循环显示每一帧
    while(1)
    {
        //【1】读入图像
        Mat frame;//用于存储每一帧的图像
        cap>>frame; //读取当前帧
        //【2】将原图转化为灰度图像
        cvtColor(frame,edges,COLOR_BGR2GRAY);
        //【3】使用3×3内核来降噪
        blur(edges,edges,Size(7,7));//进行模糊
        //【4】进行canny边缘检测并显示
        Canny(edges,edges,0,30,3);
        imshow("被canny边缘检测后的视频",edges);
        //若视频播放完成，退出循环
       // if(frame.empty())
         //   break;
        if(waitKey(30)>0)
            break;//延时30ms
    }
    return 0;
}