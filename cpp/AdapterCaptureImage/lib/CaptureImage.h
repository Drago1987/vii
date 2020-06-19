/*
Extracts the players cards from an image
*/
#include "opencv4/opencv2/stitching.hpp"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <cstdint>
#include <cstring>
#include <vector>

#include <opencv4/opencv2/gapi/opencv_includes.hpp>
#include "opencv2/opencv.hpp"

#include "LoggerError.hpp"

#ifndef CAPTURE_IMAGE_HPP
#define CAPTURE_IMAGE_HPP

/**
    * Extracts the cards from the image
*/
class CaptureImage
{
    public:
/**
    * [static] class1Name 
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {returnType***}                   : 
*/
    CaptureImage();
    ~CaptureImage();

/**
    * Loads one image and stores it into the private member variable image_container
    * 
    * @param  {std::vector< std::string>} filename  : path to the file
    * @return {None}
*/
    void take_screenshot(std::vector<uint8_t>& Pixels, int& Width, int& Height, int& BitsPerPixel);
/**
    * Displays a specific image
    * 
    * @param  {std::vector< std::string>} filename  : path to the file
    * @return {None}
*/
    //void show_image(std::string filename);
/**
    * Description of API
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {returnType***}                   : 
*/
    void convert_image_to_hsv(){};
/**
    * Description of API
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {returnType***}                   : 
*/
    void get_version(){};

/**
    * Description of API
    * Observer must be inheritated and here implemented
    * Clarification how to send the data, via pips, sockets, etc.
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {returnType***}                   : 
*/
    void update(){};



    private:
    std::vector<cv::Mat> image_container;
    std::vector< std::string> images_loaded;
};
#endif //CAPTURE_IMAGE_HPP
