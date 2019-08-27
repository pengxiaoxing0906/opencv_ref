/*本程序介绍三种遍历图像的方式，分别是用指针访问像素、用迭代器操作像素、动态地址计算，另外涉及到颜色空间缩减*/


#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

void colcorReduce1(Mat& inputImage,Mat& outputImage, int div);
void colcorReduce2(Mat& inputImage,Mat& outputImage, int div);
void colcorReduce3(Mat& inputImage,Mat& outputImage, int div);
int main()
{
    //[1]创建原始图并显示
    Mat srcImage=imread("./1.jpg");
    if(!srcImage.data)
    {
        cout<<"图片读取失败"<<endl;
        return 1;
    }
    imshow("[原始图]",srcImage);
    //[2]按原始图的参数规格来创建效果图
    Mat dstImage;
    dstImage.create(srcImage.rows,srcImage.cols,srcImage.type());
    //imshow("目标图",dstImage);
    //[3]记录起始时间
    double t0= static_cast<double>(getTickCount());
    //[4]调用颜色空间缩减函数
       // colcorReduce1(srcImage, dstImage, 32);
        //colcorReduce2(srcImage, dstImage, 32);
        colcorReduce3(srcImage, dstImage, 32);
        //[5]计算运行时间并输出
        double t1 = static_cast<double>(getTickCount());
        double time_used = (t1 - t0) / getTickFrequency();
        cout<<"time used:"<<time_used<<endl;
    //【6】显示效果图
    imshow("[效果图]",dstImage);


    waitKey(0);
    return 0;
}

/*void colcorReduce1(Mat& inputImage,Mat& outputImage, int div)
{
  //参数准备
  outputImage=inputImage.clone();
  int rowNumber=outputImage.rows;//行数
  int colNumber=outputImage.cols*outputImage.channels();//列数×通道数=每一行元素的个数
  //双重循环，遍历所有的像素值
  for(int i=0;i<rowNumber;i++)
  {
      uchar*data=outputImage.ptr<uchar>(i); //获取第i行的首地址
      for(int j=0;j<colNumber;j++)
      {
          data[j]=data[j]/div*div+div/2;
      }
  }

}
void colcorReduce2(Mat& inputImage,Mat& outputImage, int div)
{
    //参数准备
    outputImage=inputImage.clone();
    //获取迭代器
    Mat_<Vec3b>::iterator it=outputImage.begin<Vec3b>(); //初始位置的迭代器
    Mat_<Vec3b>::iterator itend=outputImage.end<Vec3b>(); //终止位置的迭代器
    //存取彩色图像像素
    for(;it!=itend;++it)
    {
        (*it)[0]=(*it)[0]/div*div+div/2;
        (*it)[1]=(*it)[1]/div*div+div/2;
        (*it)[2]=(*it)[2]/div*div+div/2;

    }

}*/
void colcorReduce3(Mat& inputImage,Mat& outputImage, int div)
{
    //参数准备
    outputImage=inputImage.clone();
    int rowNumber=outputImage.rows;
    int colNumber=outputImage.cols;
    //获取彩色图像像素
    for(int i=0;i<rowNumber;i++)
    {
        for(int j=0;j<colNumber;j++)
        {
            outputImage.at<Vec3b>(i,j)[0]=outputImage.at<Vec3b>(i,j)[0]/div*div+div/2;//蓝色通道
            outputImage.at<Vec3b>(i,j)[1]=outputImage.at<Vec3b>(i,j)[1]/div*div+div/2;//绿色通道
            outputImage.at<Vec3b>(i,j)[2]=outputImage.at<Vec3b>(i,j)[2]/div*div+div/2; //红色通道

        }
    }

}
