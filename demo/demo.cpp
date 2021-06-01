#include<iostream>
#include "utils.h"
#include "Specs.h"
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv ){
    if ( argc != 3 )
    {
        std::cout<<"usage: DisplayImage.out <Image_Path> <Spec_file>"<<std::endl;
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    Specs resizeSpecs;
    std::string parsePass="../data/spec.txt";
    std::tuple<int, int> resizespec=resizeSpecs.parseFromFile(argv[2]);
    Mat img1(resizespec.second, resizespec.first, CV_8UC3, Scalar(10, 100, 150)); //mock image

    // resizeSpecs.parseFromFile(parsePass);
    // resizeSpecs.parseFromFile();

    // resizeSpecs.donothing();

    Mat outImg;
    

    // cv::resize(image, outImg, cv::Size(), 0.5, 0.5); // to be replaced by width and height from  class function return

    cv::resize(argv[1], outImg, img1.size());

    // imwrite("./resized.jpg", outImg);
    // namedWindow("Display Image", WINDOW_AUTOSIZE );
    namedWindow("Display outImage", WINDOW_AUTOSIZE );
    // imshow("Display Image", image);
    imshow("Display outImage", outImg);
    
    waitKey(0);
    return 0;
}