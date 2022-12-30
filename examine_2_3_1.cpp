#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void drawLIne(Mat &img,vector<Vec2f>lines,double rows,double cols,Scalar scalar,int n)
{
    Point pt1,pt2;
        for(size_t i=0;i<lines.size();++i){
            float rho=lines[i][0];//直线距离坐标原点的距离
            float theta=lines[i][1];//直线过坐标原点垂线与x轴夹角
            double a=cos(theta);//夹角的余弦值
            double b=sin(theta);//夹角的正弦值
            double x0=a*rho,y0=b*rho;//直线与坐标原点垂线的交点
            double length=max(rows,cols);//图像高宽的最大值

            //计算直线上的一点
            pt1.x=cvRound(x0+length*(-b));
            pt1.y=cvRound(y0+length*(a));
            //计算直线上另一点
            pt2.x=cvRound(x0-length*(-b));
            pt2.y=cvRound(y0-length*(a));
            //两点绘制一条直线
            line(img,pt1,pt2,scalar,n);
    }
}

int main()
{
    Mat img = imread("D:/board.jpg");
    Mat img_gray;
    Mat img_hsv;

    cvtColor(img,img_gray, COLOR_BGR2GRAY);
    cvtColor(img,img_hsv, COLOR_BGR2HSV);

    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    imshow("rgb", img);
    imshow("gray", img_gray);
    imshow("hsv", img_hsv);

    Mat dstImage, edge, grayImage;
    dstImage.create(img.size(), img.type());
    cvtColor(img, grayImage, COLOR_BGR2GRAY);
    blur(grayImage, edge, Size(3, 3));
    Canny(edge, edge, 3, 9, 3);
    imshow("by", edge);

    vector<Vec2f>lines;
    HoughLines(edge,lines,1,CV_PI/100,150,0,0);

    Mat zx;
    img.copyTo(zx);
    drawLIne(zx,lines,edge.rows,edge.cols,Scalar(255),2);
    imshow("zx",zx);

    waitKey(0);

    return 0;
}
