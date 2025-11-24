#include <iostream>
#include "Image.h"

int main() {
    std::cout << "Toshiba Image Processor: Starting..." << std::endl;

    int w = 256;
    int h = 256;
    Image img(w, h);

    // 1. Generate Base Pattern
    std::cout << "Generating Gradient..." << std::endl;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            img.setPixel(x, y, x % 255, y % 255, 128);
        }
    }
    img.savePPM("original.ppm");

    // 2. Apply Processing
    std::cout << "Applying Filters..." << std::endl;
    img.invertColors();

    // 3. Save Result
    img.savePPM("inverted.ppm");

    std::cout << "Processing Complete. Check 'inverted.ppm'." << std::endl;
    return 0;
}