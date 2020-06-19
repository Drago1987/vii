#include <iostream>
#include "AdapterCardImageExtractor.h"
#include <boost/log/trivial.hpp>



int main(int argc, char **argv){
    AdapterCardImageExtractor* instance_cardImageExtractor= new AdapterCardImageExtractor();
    instance_cardImageExtractor->get_version();
    std::string filename{"./cpp/AdapterCardImageExtractor/images/step8_1447109970617_tcm1488-264382.jpg"};
    instance_cardImageExtractor->load_image(filename);
    auto image_container=instance_cardImageExtractor->get_image_container();
    std::cout << "Size is " << std::to_string(image_container.size()) << "\n";

    //Add a wrapper around the logger.
    BOOST_LOG_TRIVIAL(info) << "Logger for this project";

    cv::String windowName = "The Guitar"; //Name of the window
    cv::namedWindow(windowName); // Create a window
    cv::imshow(windowName, image_container[0]); // Show our image inside the created window.
    cv::waitKey(0); // Wait for any keystroke in the window
    cv::destroyWindow(windowName); //destroy the created window
    

    

    std::cout << "Hello World" << std::endl;
    std::cout << "Compiler version is" << __cplusplus << std::endl;

    return 0;
}