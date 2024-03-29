#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector> //当数组来理解

using namespace std;
using namespace cv;

void createAlphaMat(Mat &mat);
int main(int argc,char**argv)
{
    //创建带ALPHA通道的Mat
    Mat mat(480,640,CV_8UC4);
    createAlphaMat(mat);
    vector<int>compression_params; //创建一个数组
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    try {
        imwrite("透明Alapha值图.png",mat,compression_params);
        imshow("生成的png图",mat);
        fprintf(stdout,"lll\n");
        waitKey(0);
    }
    catch (runtime_error&ex)
    {
        fprintf(stderr,"图像转换成PNG格式发生错误：%s\n",ex.what());
        return  1;
    }


    return 1;
}
void createAlphaMat(Mat &mat)
{
    for(int i=0;i<mat.rows;++i)
    {
        for(int j=0;j<mat.rows;++j)
        {
            Vec4b&rgba=mat.at<Vec4b>(i,j);
            rgba[0]=UCHAR_MAX;
            rgba[1]=saturate_cast<uchar>((float(mat.cols-j))/((float)mat.cols*UCHAR_MAX));
            rgba[2]=saturate_cast<uchar>((float(mat.rows-j))/((float)mat.rows*UCHAR_MAX));
            rgba[3]=saturate_cast<uchar>(0.5*(rgba[1]+rgba[2]));
        }
    }
}