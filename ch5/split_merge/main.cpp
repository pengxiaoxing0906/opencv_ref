#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

bool MultiChannelBlending();

int main(int argc ,char**argv)
{
    if(MultiChannelBlending())
    {
        cout<<"运行成功";
    }
    waitKey(0);
    return 0;
}

bool MultiChannelBlending()
{
    //[0]定义相关变量
    Mat srcImage;
    Mat logoImage;
    vector<Mat>channels;

    /*蓝色通道部分*/
    Mat imageBlueChannel;
    //[1]读入图像
    logoImage=imread("./dota_logo.jpg",0);
    srcImage=imread("./dota_jugg.jpg");
    if(!logoImage.data)
    {
        cout<<"dota_logo1.jpg loaded fail "<<endl;
        return 1;
    }
   // imshow("logo图",logoImage);
    // imshow("原图",srcImage);
    if(!srcImage.data)
    {
        cout<<"dota1.jpg loaded fail "<<endl;
        return 1;
    }
    //【2】把一个3通道图像转换成3个单通道图像
    split(srcImage,channels);
    //[3]将原图的蓝色通道引用返回给imageBlueChannel
    imageBlueChannel=channels.at(0);
    //[4]将原图的蓝色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageBlueChannel1中
    addWeighted(imageBlueChannel(Rect(500,250,logoImage.cols,logoImage.rows)),0.5,logoImage,0.5,0.0,imageBlueChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
    //[5]将三个单通道重新合并成一个三通道
    merge(channels,srcImage);
    //【6】显示效果图
    imshow("[1]游戏原画+logo蓝色通道",srcImage);
    //waitKey(0);


    /*绿色通道部分*/
    Mat imageGreenChannel;
    //[1]读入图像
    logoImage=imread("./dota_logo.jpg",0);
    srcImage=imread("./dota_jugg.jpg");
    if(!logoImage.data)
    {
        cout<<"dota_logo2 loaded fail "<<endl;
        return 1;
    }
    if(!srcImage.data)
    {
        cout<<"dota2 loaded fail "<<endl;
        return 1;
    }
    //【2】把一个3通道图像转换成3个单通道图像
    split(srcImage,channels);
    //[3]将原图的绿色通道引用返回给imageBlueChannel
    imageGreenChannel=channels.at(1);
    //[4]将原图的绿色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageBlueChannel1中
    addWeighted(imageGreenChannel(Rect(500,250,logoImage.cols,logoImage.rows)),0.5,logoImage,0.5,0.0,imageGreenChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
    //[5]将三个单通道重新合并成一个三通道
    merge(channels,srcImage);
    //【6】显示效果图
    imshow("[1]游戏原画+logo绿色通道",srcImage);
   // waitKey(0);


    /*红色通道部分*/
    Mat imageRedChannel;
    //[1]读入图像
    logoImage=imread("./dota_logo.jpg",0);
    srcImage=imread("./dota_jugg.jpg");
    if(!logoImage.data)
    {
        cout<<"dota logo3 loaded fail "<<endl;
        return 1;
    }
    if(!srcImage.data)
    {
        cout<<"dota 3 loaded fail "<<endl;
        return 1;
    }
    //【2】把一个3通道图像转换成3个单通道图像
    split(srcImage,channels);
    //[3]将原图的红色通道引用返回给imageBlueChannel
    imageRedChannel=channels.at(2);
    //[4]将原图的红色通道的（500,250）坐标处右下方的一块区域和logo图进行加权操作，将得到的混合结果存到imageBlueChannel1中
    addWeighted(imageRedChannel(Rect(500,250,logoImage.cols,logoImage.rows)),0.5,logoImage,0.5,0.0,imageRedChannel(Rect(500,250,logoImage.cols,logoImage.rows)));
    //[5]将三个单通道重新合并成一个三通道
    merge(channels,srcImage);
    //【6】显示效果图
    imshow("[1]游戏原画+logo红色通道",srcImage);
   // waitKey(0);

    return true;

}