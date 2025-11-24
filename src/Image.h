#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

// A struct represents a single pixel's color
struct Pixel {
    unsigned char r; // Red (0-255)
    unsigned char g; // Green (0-255)
    unsigned char b; // Blue (0-255)
};

class Image {
public:
    int width;
    int height;
    std::vector<Pixel> pixels;

    Image(int w, int h);
    bool savePPM(const std::string& filename);
    void setPixel(int x, int y, int r, int g, int b);
    
    // NEW: Add this line
    void invertColors(); 
};

#endif