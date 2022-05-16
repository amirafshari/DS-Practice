#include <iostream>

//opencv
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// ZBAR
#include <zbar.h>

using namespace std;
using namespace cv;
using namespace zbar;


#define LOG(x) std::cout << x << std::endl




int main() {
    // read image
    Mat img = imread("obj.jpg", IMREAD_GRAYSCALE);

    // ZBAR
    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
    Image image(img.cols, img.rows, "Y800", img.data, img.cols * img.rows);
    int n = scanner.scan(image);

    for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
    {
    cout << n << endl;
    cout << symbol->get_type_name() << endl;
    cout << symbol->get_data() << endl;
    }
    
    /*
    // variables
    int num = 8;
    const char* amir = "Amir";
    // pointers
    int* ptr = &num;
    *ptr = 10;
    // print out
    std::cout << "Hello World!" << std::endl;
    // call the functions
    LOG(num);
    // get the type of the variable 
    std::cout << typeid(amir).name() << std::endl;
    */
}