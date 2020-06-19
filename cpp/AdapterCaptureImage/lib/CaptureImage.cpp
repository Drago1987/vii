#include "CaptureImage.h"


CaptureImage::CaptureImage()
{
    const std::string filename="test.jpg";
    int Width = 0;
    int Height = 0;
    int Bpp = 0;
    std::vector<std::uint8_t> Pixels;

    take_screenshot(Pixels, Width, Height, Bpp);

    if (Width && Height)
    {
        cv::Mat save_img = cv::Mat(Height, Width, Bpp > 24 ? CV_8UC4 : CV_8UC3, &Pixels[0]);
        if(save_img.empty())
        {
            vii::LoggerError() << "Something is wrong with the webcam, could not get frame.";
            std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
        }
        cv::imwrite(filename, save_img);
    }
}

CaptureImage::~CaptureImage()
{
}

void CaptureImage::take_screenshot(std::vector<uint8_t>& Pixels, int& Width, int& Height, int& BitsPerPixel){
    Display* display = XOpenDisplay(nullptr);
    Window root = DefaultRootWindow(display);

    XWindowAttributes attributes = {0};
    XGetWindowAttributes(display, root, &attributes);

    Width = attributes.width;
    Height = attributes.height;

    XImage* img = XGetImage(display, root, 0, 0 , Width, Height, AllPlanes, ZPixmap);
    BitsPerPixel = img->bits_per_pixel;
    Pixels.resize(Width * Height * 4);

    memcpy(&Pixels[0], img->data, Pixels.size());

    XDestroyImage(img);
    XCloseDisplay(display);
}

void CaptureImage::update(){
}