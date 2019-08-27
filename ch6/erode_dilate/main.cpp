//=======图像的腐蚀与膨胀　腐蚀是暗的区域变得更多　膨胀是亮的区域变得更多=====/

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


Mat srcImage,dstImage;
int TrackbarNUmber=0;//0表示腐蚀erode,1表示膨胀dilate
int StructElementSize=3;//结构元素（内核矩阵）的尺寸

void Process();
void on_TrackbarNUmberChange(int, void*);
void on_ElementSizeChange(int,void*);

int main(int argc,char**argv)
{
    //读取图片错误检查显示
    srcImage=imread(argv[1]);
    if(!srcImage.data)
    {
        printf("picture loaded fail! \n");
        return 1;
    }
    imshow("原图",srcImage);


    //初次腐蚀
    namedWindow("效果图");
    Mat element=getStructuringElement(MORPH_RECT,Size(2*StructElementSize+1,2*StructElementSize+1),Point(StructElementSize,StructElementSize));
    erode(srcImage,dstImage,element);
    imshow("效果图",dstImage);

    //创建轨迹条
    createTrackbar("腐蚀/膨胀","效果图",&TrackbarNUmber,1,on_TrackbarNUmberChange);
    createTrackbar("内核尺寸","效果图",&StructElementSize,21,on_ElementSizeChange);

    while(char(waitKey(0))!='q'){}
    return 0;
}
void Process()
{
    Mat element=getStructuringElement(MORPH_RECT,Size(2*StructElementSize+1,2*StructElementSize+1),Point(StructElementSize,StructElementSize));
    if(TrackbarNUmber==0)
    {
        erode(srcImage,dstImage,element);
    }
    else
    {
        dilate(srcImage,dstImage,element);
    }

    imshow("效果图",dstImage);
}
void on_TrackbarNUmberChange(int, void*)
{
    Process();
}
void on_ElementSizeChange(int,void*)
{
    Process();
}
