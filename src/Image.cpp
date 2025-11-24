#include "Image.h"
#include <fstream>
#include <iostream>

// Constructor implementation
Image::Image(int w, int h) : width(w), height(h) {
    // Resize the vector to hold all pixels (Width * Height)
    pixels.resize(width * height);
}

// Helper to set a pixel's color safely
void Image::setPixel(int x, int y, int r, int g, int b) {
    // Convert 2D (x,y) coordinates to 1D index
    int index = y * width + x; 
    pixels[index].r = (unsigned char)r;
    pixels[index].g = (unsigned char)g;
    pixels[index].b = (unsigned char)b;
}

// Save to PPM format (P3 ASCII)
bool Image::savePPM(const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    // 1. Write the Header
    // P3 = ASCII color format
    // width height = dimensions
    // 255 = max color value
    file << "P3\n" << width << " " << height << "\n255\n";

    // 2. Write the Pixel Data
    for (const auto& p : pixels) {
        // Cast to int so it writes numbers "255" not characters
        file << (int)p.r << " " << (int)p.g << " " << (int)p.b << " ";
        file << "\n"; // Newline for readability
    }

    file.close();
    std::cout << "Image saved to " << filename << std::endl;
    return true;
}

// Inverts the colors of the image (Negative filter)
void Image::invertColors() {
    // Iterate through the raw memory vector
    // This is efficient: O(N) complexity where N is total pixels
    for (auto& p : pixels) {
        p.r = 255 - p.r;
        p.g = 255 - p.g;
        p.b = 255 - p.b;
    }
    std::cout << "Filter Applied: Invert Colors" << std::endl;
}