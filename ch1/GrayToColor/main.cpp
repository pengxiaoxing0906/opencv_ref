#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char**argv)
{
    Mat srcImage=imread("/home/pxx/Documents/GrayToColor/电缆.bmp",0);
    Mat dstImage(srcImage.size(),CV_8UC3);
    unsigned  char grayValue;
    imshow("【原图】电缆",srcImage);
    int rowNumber=dstImage.rows;//行数
    int colNumber=dstImage.cols;//列数
    for(int i=0;i<rowNumber;i++)
    {
        for(int j=0;j<colNumber;j++)
        {
            grayValue=srcImage.at<uchar>(i,j); //获取每个像素点的灰度值
            Vec3b& pixel = dstImage.at<Vec3b>(i,j);

            if(grayValue<=63)
            {
                pixel[0]=255;  //B
                pixel[1]=254-4*grayValue;  //G
                pixel[2]=0;  //R
            }
            else if((grayValue>63)&&(grayValue<=127))
            {
                pixel[0]=510-4*grayValue;
                pixel[1]=4*grayValue-254;
                pixel[2]=0;
            }
            else if((grayValue>127)&&(grayValue<=191))
            {
                pixel[0]=0;
                pixel[1]=255;
                pixel[2]=4*grayValue-510;
            }
            else if(grayValue>191)
            {
                pixel[0]=0;
                pixel[1]=1022-4*grayValue;
                pixel[2]=255;
            }

        }
    }
    imshow("【彩色图】",dstImage);
    waitKey(0);
    return 0;
}