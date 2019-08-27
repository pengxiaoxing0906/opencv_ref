#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
using namespace std;
using namespace cv;


int main() {
   //初始化
   FileStorage fs("test.yaml",FileStorage::WRITE);

   //开始写入文件
   fs<<"framecount"<<5;
   time_t rawtime;
   time(&rawtime);
   //fs<<"calibrationdate:";
   //fs<< asctime(localtime(&rawtime));
    fs << "calibrationDate" << asctime(localtime(&rawtime));
   Mat K=(Mat_<double>(3,3)<<1000,0,320,0,1000,240,0,0,1); //内参
   Mat distCoeffs=(Mat_<double>(5,1)<<0.1,0.01,-0,001,0,0);//畸变系数
   fs<<"K"<<K<<"distCoeffs"<<distCoeffs;
   // fs << "cameraMatrix" << K << "distCoeffs" << distCoeffs;
   fs<<"features"<<"[";
   for(int i=0;i<3;i++)
   {
       int x=rand()%640;
       int y=rand()%480;
       uchar lbp=rand()%256;

       fs<<"{:"<<"x"<<x<<"y"<<y;
       fs<<"lbp"<<"[:";
       //fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
       for(int j=0;j<8;j++)
       {
           fs<<((lbp>>j)&1);
       }
       fs<<"]";
       fs<<"}";
   }
   fs<<"]";
   fs.release();
   printf("文件读写完毕");
   getchar();

    return 0;
}