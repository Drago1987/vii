#include "AdapterCardImageExtractor.h"

namespace acie
{
    const char* image_window = "Source Image";
    const char* result_window = "Result window";
    int match_method;
    static void MatchingMethod(int, void* );
} // namespace acie


//#include <opencv2/imgcodecs.hpp>


// AdapterCardImageExtractor::AdapterCardImageExtractor(std::vector< const std::string> filenames)
// : images_loaded(filenames)
// {
// }

AdapterCardImageExtractor::AdapterCardImageExtractor()
{
}

AdapterCardImageExtractor::~AdapterCardImageExtractor()
{
}

void AdapterCardImageExtractor::load_image(std::string filename){
    try
    {
        image_container.push_back(cv::imread(filename.c_str(), cv::IMREAD_COLOR));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "An unexpected error occured when loading the image" << '\n';
    }
    
    
}

void AdapterCardImageExtractor::get_version(){

    std::cout << "Done" << std::endl;

}

std::unordered_map<std::string, unsigned int> AdapterCardImageExtractor::extract_card(unsigned int idx){
    if (image_container.empty())
    {
        throw std::runtime_error("Image container is empty");
    }
    if (image_container.size() < idx)
    {
        throw std::runtime_error("Index exceeds size of image container");
    }
    auto image_instance= image_container[idx];
    auto image_type= this->get_image_type(image_instance);
    auto image_number= this->get_image_number(image_instance);
    std::unordered_map<std::string, unsigned int> map_instance{
        {image_type,image_number}
    };
    return map_instance;
}

std::string AdapterCardImageExtractor::get_image_type(cv::Mat image_instance){

    return "Hearts";//Spades, Hearts, Diamonds, and Clubs
}

cv::Mat AdapterCardImageExtractor::get_main_player_hand(cv::Mat main_image){
    cv::Mat main_player_hand;
    return main_player_hand;
}

std::unordered_map<std::string, unsigned int> AdapterCardImageExtractor::identify_main_player_cards(cv::Mat main_player_hand){
    return {{"Hearts", 0x10},{"Spades",0x09}};
}

//TODO: write unite test
std::string AdapterCardImageExtractor::find_card_type(cv::Mat img, cv::Mat templ,std::string path_mask, bool use_mask){
    cv::Mat mask;
    if(use_mask==true) {
        mask = cv::imread( path_mask, cv::IMREAD_COLOR );
    }
    if(img.empty() || templ.empty() || mask.empty())
    {
        std::cout << "Can't read one of the images" << std::endl;//Add logger
    }
    cv::namedWindow( acie::image_window, cv::WINDOW_AUTOSIZE );
    cv::namedWindow( acie::result_window, cv::WINDOW_AUTOSIZE );
    const char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
    cv::createTrackbar( trackbar_label, acie::image_window, &acie::match_method, max_Trackbar,acie::MatchingMethod );
    acie::MatchingMethod( 0, 0 );
    cv::waitKey(0);
    return "";
}



unsigned int AdapterCardImageExtractor::get_image_number(cv::Mat image_instance){
    return 12;
}

void AdapterCardImageExtractor::convert_image_to_hsv(){
    // auto & itr_hsv= hsv_container.begin()
    // for(auto idx_image : get_image_container() ){
    //     cv::cvtColor( itr_hsv, hsv_base, COLOR_BGR2HSV );
    //     itr_hsv++;
    // }

}

// void AdapterCardImageExtractor::show_image(){
//     cv::String windowName = "The Guitar"; //Name of the window
//     cv::namedWindow(windowName); // Create a window
//     cv::imshow(windowName, image_container[0]); // Show our image inside the created window.
//     cv::waitKey(0); // Wait for any keystroke in the window
//     cv::destroyWindow(windowName); //destroy the created window
// }

std::vector<cv::Mat> AdapterCardImageExtractor::get_image_container(){
    return image_container;
}

//not using a mask
//TODO: write unite test
static void acie::MatchingMethod(int, void* )
{
    cv::Mat img; cv::Mat templ;cv::Mat mask;
    cv::Mat img_display;
    cv::Mat result;
    img.copyTo( img_display );
    int result_cols =  img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;
    result.create( result_rows, result_cols, CV_32FC1 );
    bool method_accepts_mask = (cv::TM_SQDIFF == acie::match_method || acie::match_method == cv::TM_CCORR_NORMED);
    if ( !(mask.empty()) && method_accepts_mask){
        cv::matchTemplate( img, templ, result, acie::match_method, mask);
    }else{
        matchTemplate( img, templ, result, acie::match_method);
    }
    cv::normalize( result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );
    double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
    cv::Point matchLoc;
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );
    if( acie::match_method  == cv::TM_SQDIFF || acie::match_method == cv::TM_SQDIFF_NORMED ){
        matchLoc = minLoc;
    }
    else{
        matchLoc = maxLoc;
    }
    cv::rectangle( img_display, matchLoc, cv::Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), cv::Scalar::all(0), 2, 8, 0 );
    cv::rectangle( result, matchLoc, cv::Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), cv::Scalar::all(0), 2, 8, 0 );
    cv::imshow( acie::image_window, img_display );
    cv::imshow( acie::result_window, result );
    return;
}
