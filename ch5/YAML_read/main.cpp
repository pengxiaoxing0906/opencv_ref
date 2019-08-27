#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
using namespace std;
using namespace cv;

int main() {
   //初始化
   FileStorage fs2("test.yaml",FileStorage::READ);
   int framecount=(int)fs2["framecount"];
   string date;
   fs2["calibrationDate"]>>date;
   Mat cameraMatrix2,disCoeffs2;
   fs2["K"]>>cameraMatrix2;
   fs2["distCoeffs"]>>disCoeffs2;
   cout<<"framecount"<<framecount<<endl;
   cout<<"calibration date: "<<date<<endl;
   cout<<"camera matrix: "<<cameraMatrix2<<endl;

   FileNode features=fs2["features"];
   FileNodeIterator it=features.begin(),it_end=features.end();
   int idx=0;
   std::vector<uchar>lbpval;
   //使用FIleNodeIterator遍历序列
   for(;it!=it_end;++it,idx++)
   {
       cout<<"feature# "<<idx<<": ";
       cout<<"x="<<(int)(*it)["x"]<<",y="<<(int)(*it)["y"]<<",lbp:(";
       (*it)["lbp"]>>lbpval;
       for(int i=0;i<(int)lbpval.size();i++)
           cout<<" "<<(int)lbpval[i];
       cout<<")"<<endl;
   }
   fs2.release();
   printf("文件读取完毕");
   getchar();

    return 0;
}