#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <cstdint> // For uint8_t (standard byte type)

class Image {
public:
    int width;
    int height;
    int channels; // 3 for RGB, 1 for Grayscale, 4 for PNG (Alpha)
    
    // We use a flat vector of bytes. 
    // Size = width * height * channels
    std::vector<uint8_t> data; 

    // Constructors
    Image();
    Image(int w, int h, int c);

    // Load/Save functions
    bool load(const std::string& filename);
    bool save(const std::string& filename);

    // Basic processing (We will add advanced stuff later)
    void toGrayscale();
};

#endif