#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "【程序窗口】"

//全局函数声明
void on_MouseHandle(int event,int x,int y,int flags,void*param);
void DrawRectangle(cv::Mat &img,cv::Rect box);


//全局变量的声明
Rect g_rectangle;//声明一个矩形变量
bool g_bDrawingBox= false;//是否进行绘制
RNG g_rng(12345);//产生随机数
int main(int argc,char**argv)
{
   //【1】准备参数
  // g_rectangle=Rect(-1,-1,0,0);
   Mat srcImage=imread("/home/pxx/Documents/opencv/ch3/SetMouseCallback/1.jpg");
   //imshow("原图",srcImage);
   Mat tempImage;
   srcImage.copyTo(tempImage);
   // g_rectangle=Rect(-1,-1,0,0);
  srcImage=Scalar::all(0);//设置所有通道数为零
  //【2】设置鼠标操作回调函数
  namedWindow(WINDOW_NAME);
  setMouseCallback(WINDOW_NAME,on_MouseHandle,(void*)&srcImage);
  //【3】程序主循环，当进行绘制的标识符为真时，进行绘制
 while (1)
  {
      srcImage.copyTo(tempImage);
     if(g_bDrawingBox)
         DrawRectangle(tempImage,g_rectangle);
      imshow(WINDOW_NAME,tempImage);
      if(waitKey(10)==27)
          break;
  }
    return 0;
}

void on_MouseHandle(int event,int x,int y,int flags,void*param)
{
    Mat&image=*(cv::Mat*)param;
    switch(event)
    {
        //鼠标移动消息
        case EVENT_MOUSEMOVE:
        {
            if(g_bDrawingBox)
            {
                g_rectangle.width=x-g_rectangle.x;
                g_rectangle.height=y-g_rectangle.y;
            }
            break;
        }
        //左键按下消息
        case EVENT_MBUTTONDOWN:
        {
            g_bDrawingBox=true;
            g_rectangle=Rect(x,y,0,0);//记录起始点
        }
        break;
        //左键抬起消息
        case EVENT_LBUTTONUP:
        {
            g_bDrawingBox=false;
            //对宽度和高度小于0的处理
            if(g_rectangle.width<0)
            {
                g_rectangle.x+=g_rectangle.width;
                g_rectangle.width*=-1;
            }
            if(g_rectangle.height<0)
            {
                g_rectangle.y+=g_rectangle.height;
                g_rectangle.height*=-1;
            }
            //调用函数进行绘制
            DrawRectangle(image,g_rectangle);
        }
        break;

    }
}

//自定义的矩形绘制函数
void DrawRectangle(cv::Mat &img,cv::Rect box)
{
    rectangle(img,box.tl(),box.br(),Scalar(g_rng.uniform(0,255),g_rng.uniform(0,255),g_rng.uniform(0,255)));
}
