#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture capture("D:/preview.mp4");

    if(!capture.isOpened())
    {
        cout<<"Error opening video stream or file"<<endl;
        return -1;
    }

    Mat frame;

    double fps;
    char string[10];
    namedWindow("FPS");
    double t = 0;
    while(1)
    {
        t = (double)getTickCount();
        if (waitKey(50) == 30)
        {
            break;
        }
        if (capture.isOpened())
        {
            capture >> frame;

            t = ((double)getTickCount() - t) / getTickFrequency();
            fps = 1.0 / t;
            sprintf(string, "%.2f", fps);
            std::string fpsString("");
            fpsString += string;
            putText(frame,fpsString,Point(10, 30), FONT_HERSHEY_SIMPLEX,1,Scalar(0, 255, 0));
            imshow("FPS", frame);
        }
    }
}
