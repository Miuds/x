#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("D:/RM.png");

    if(img.empty())
    {
        cout << "can't read this image!" << endl;
        return 0;
    }

    imshow("image", img);

    namedWindow("hsv调节", WINDOW_AUTOSIZE);
    imshow("hsv调节", img);

    waitKey(0);

    return 0;
}
