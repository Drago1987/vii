#include <iostream>
#include "CaptureImage.h"
#include <boost/log/trivial.hpp>



int main(int argc, char **argv){
    CaptureImage* instance_cardImageExtractor= new CaptureImage();
    std::cout << "Hello World" << std::endl;
    std::cout << "Compiler version is" << __cplusplus << std::endl;

    return 0;
}