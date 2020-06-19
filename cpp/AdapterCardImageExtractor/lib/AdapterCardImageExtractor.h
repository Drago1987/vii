/*
Extracts the players cards from an image
*/
#include <string>
#include <vector>
#include <iostream>
#include <opencv4/opencv2/gapi/opencv_includes.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <unordered_map>
#include <iostream>
#include <stdlib.h>

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc.hpp>


#ifndef ADAPTER_CARDIMAGEEXTRACTOR_H
#define ADAPTER_CARDIMAGEEXTRACTOR_H

/**
    * Extracts the cards from the image
*/
class AdapterCardImageExtractor
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
    AdapterCardImageExtractor();
    //AdapterCardImageExtractor(std::vector< std::string> filenames);
    ~AdapterCardImageExtractor();

/**
    * Loads one image and stores it into the private member variable image_container
    * 
    * @param  {std::vector< std::string>} filename  : path to the file
    * @return {None}
*/
    void load_image(std::string filename);

/**
    * Loads one image and stores it into the private member variable image_container
    * 
    * @param  {std::vector< std::string>} filename  : path to the file
    * @return {None}
*/
    cv::Mat get_main_player_hand(cv::Mat main_image);

/**
    * Loads one image and stores it into the private member variable image_container
    * 
    * @param  {std::vector< std::string>} filename  : path to the file
    * @return {None}
*/
    std::unordered_map<std::string, unsigned int> identify_main_player_cards(cv::Mat main_player_hand);
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
    void convert_image_to_hsv();
/**
    * Description of API
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {returnType***}                   : 
*/
    void get_version();
/**
    * Returns the image_container
    * 
    * @return {std::vector<cv::Mat>}                   : 
*/
    std::vector<cv::Mat> get_image_container();

/**
    * Expects an index to extract the card.
    * Returns a unordered_map<string,unsigned int>.
    * string represents the type of the card.
    * int represents the value of the card.
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {map<string,unsigned int>}        : extracted_card
*/
    std::unordered_map<std::string, unsigned int> extract_card(unsigned int idx);

/**
    * Expects an index to extract the card.
    * Returns a map<string,unsigned int>.
    * string represents the type of the card.
    * int represents the value of the card.
    * 
    * @param  {type1} var1                      : 
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {map<string,unsigned int>} extracted_card  : Extracted card
*/
    std::string get_image_type(cv::Mat image_instance);

/**
    * Expects an image instance.
    * Returns the value of the card as an unsigned int.
    * 
    * @param  {cv::Mat} image_instance          : Instance of the image
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {unsigned int}        : image_number
*/
    unsigned int get_image_number(cv::Mat image_instance);

/**
    * Expects an image instance.
    * Returns the value of the card as an unsigned int.
    * 
    * @param  {cv::Mat} image_instance          : Instance of the image
    * @param  {int*(*)()} f1                    : 
    * @param  {type2** [class2Name:: var]} var2 : 
    * @return {unsigned int}        : image_number
*/
    std::string find_card_type(cv::Mat img, cv::Mat templ,std::string path_mask, bool use_mask=false);

    private:
    std::vector<cv::Mat> image_container;
    std::vector< std::string> images_loaded;
    int max_Trackbar = 5;
};
#endif //ADAPTER_CARDIMAGEEXTRACTOR_H
