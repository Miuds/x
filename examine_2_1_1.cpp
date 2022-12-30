#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("D:/RM.png");
    Mat img_gray;

    cvtColor(img,img_gray, COLOR_BGR2GRAY);

    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    imshow("image", img);
    imshow("gray", img_gray);

    Mat out;

    GaussianBlur(img, out, Size(3 , 3), 3, 3);


    imshow("Gaussian Blur Image",out);
    Mat binary;

    threshold(img_gray, binary, 60, 255, THRESH_BINARY);

    imshow("binary",binary);

    waitKey(0);

    return 0;
}

