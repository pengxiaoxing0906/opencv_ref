#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc,char**argv)
{
    Mat A,B;//仅创建信息头
    A=imread("/home/pxx/Documents/opencv/ch4/Mat/hcy.jpg",CV_LOAD_IMAGE_COLOR);//为矩阵开辟空间
    Mat C(A);//调用赋值构造函数
    B=A;//赋值运算符
    Mat D,E;
    D=A.clone();
    A.copyTo(E);
    imshow("小可爱",A);
    waitKey(6000);

    //显式创建Mat对象的七种方法
    //[1]使用构造函数
    Mat M(2,2,CV_8UC3,Scalar(0,0,255));
    cout<<"M:"<<endl<<M<<endl;
    //[4]利用create（）函数
    Mat N;
    N.create(2,2,CV_8UC(2));
    cout<<"N:"<<endl<<N<<endl;
    //[5]Matlab的初始化方式
    Mat O=Mat::eye(2,2,CV_8U);
    cout<<"o:"<<endl<<O<<endl;
    //[6]逗号分隔式初始化函数
    Mat P=(Mat_<double>(3,3)<<0,-1,0,-1,2,3,1,2,3);
    cout<<"P:"<<endl<<P<<endl;

    //opencv中格式化输出方法
    Mat r(3,3,CV_8UC3);
    randu(r,Scalar::all(0),Scalar::all(255));
    //[1]opencv默认风格
    cout<<"r (opencv)默认风格："<<r<<endl;
    //[2]Python风格
    cout<<"r (python)风格："<<format(r,Formatter::FMT_PYTHON)<<endl;
    //[3]逗号分隔风格
    cout<<"r (逗号分隔风格)："<<format(r,Formatter::FMT_CSV)<<endl;
    //[4]Numpy风格
    cout<<"r (Numpy)风格："<<format(r,Formatter::FMT_NUMPY)<<endl;
    //[5]C语言风格
    cout<<"r C语言风格："<<format(r,Formatter::FMT_C)<<endl;


    //输出其他常用结构
    //[1]定义和输出二维点
    Point2f p(6,2);
    cout<<"[二维点]p="<<p<<";\n"<<endl;
    //[2]定义和输出三维点
    Point3f p1(1,1,1);
    cout<<"[三维点]p1="<<p1<<";\n"<<endl;
    //[3]定义和输出基于Mat类的std::vector
    vector<float>v;
    v.push_back(3);
    v.push_back(5);
    cout<<"[基于Mat的vector]shortvec="<<Mat(v)<<";\n"<<endl;


    return 0;
}