#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;



cv::Mat rotate(cv::Mat src, double angle)
{
    // Mat object for output image file
    cv::Mat dst;
    // defining point with respect to which to rotate
    cv::Point2f pt(src.cols/2., src.rows/2.);
    // Mat object for storing after rotation
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);
    // apply an affine transformation to image.
    cv::warpAffine(src, dst, r, cv::Size(src.cols, src.rows));
    //returning Mat object for output image file
    return dst;
}

int main()
{
    // Load the three fragment images as grayscale — do not change these lines
    cv::Mat frag_a = cv::imread("./assets/fragment_a.png", cv::IMREAD_GRAYSCALE);
    cv::Mat frag_b = cv::imread("./assets/fragment_b.png", cv::IMREAD_GRAYSCALE);

    cv::Mat img3 = cv::imread("./assets/fragment_b.png");
    // obtaining the image dimensions
    int height1=img3.size().height;
    int width1=img3.size().width;

    // displaying these images
    cv::imshow("just image", img3);
    cv::waitKey(0);


    cv::Mat frag_c = cv::imread("./assets/fragment_c.png", cv::IMREAD_GRAYSCALE);

    cv::Mat img = cv::imread("./assets/fragment_c.png");
    cv::Mat img2;
    // obtaining the image dimensions
    int height=img.size().height;
    int width=img.size().width;

    img2 = rotate(img, 180);
    // displaying these images
    cv::imshow("vertically flipped image", img2);
    cv::waitKey(0);


    if (frag_a.empty() || frag_b.empty() || frag_c.empty()) {
        cerr << "Could not load one or more fragment images from ./assets/\n";
        return -1;
    }

    
    // TODO: reverse the charm on each fragment, merge the recovered channels
    // into a single BGR image, save it as ./assets/memory_restored.png,
    // and print the number of non-zero pixels in the result.
    cv::Mat s1, s2, s3;
    union mat1; 
    union mat2;
    union mat3;
    mat1.convertTo(s1, CV_32S);
    mat2.convertTo(s2, CV_32S);
    mat3.convertTo(s3, CV_32S);
    cv::Mat sum32 = s1 + s2 + s3;
    cv::Mat masked;
    cv::bitwise_and(sum32, cv::Scalar(0xFF), masked);
    cv::Mat result_A;
    masked.convertTo(result_A, CV_8U);

    return 0;
}
