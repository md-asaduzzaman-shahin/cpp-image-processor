#include "Image.h"
#include <iostream>

// Define these ONLY in the .cpp file, never in .h
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image.h"
#include "../include/stb_image_write.h"

Image::Image() : width(0), height(0), channels(0) {}

Image::Image(int w, int h, int c) : width(w), height(h), channels(c) {
    data.resize(w * h * c);
}

bool Image::load(const std::string& filename) {
    // raw pointer to data loaded by the library
    unsigned char* imgData = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    
    if (imgData == nullptr) {
        std::cerr << "Failed to load image: " << filename << std::endl;
        return false;
    }

    // Copy data to our safe vector
    // This is a "buffer copy" operation - common in firmware
    data.assign(imgData, imgData + (width * height * channels));
    
    // Free the raw memory from the library
    stbi_image_free(imgData);
    
    std::cout << "Loaded " << filename << " (" << width << "x" << height << " - " << channels << " channels)" << std::endl;
    return true;
}

bool Image::save(const std::string& filename) {
    // Detect extension to decide format
    const char* ext = strrchr(filename.c_str(), '.');
    
    int success = 0;
    if (!ext) { return false; }

    if (strcmp(ext, ".png") == 0) {
        success = stbi_write_png(filename.c_str(), width, height, channels, data.data(), width * channels);
    } else if (strcmp(ext, ".jpg") == 0) {
        success = stbi_write_jpg(filename.c_str(), width, height, channels, data.data(), 100);
    }
    
    return success != 0;
}

// Convert RGB to Grayscale (Critical for Scanning)
void Image::toGrayscale() {
    if (channels < 3) {
        std::cout << "Image is already grayscale!" << std::endl;
        return;
    }

    std::vector<uint8_t> grayData;
    grayData.reserve(width * height);

    // Loop through pixels stepping by 'channels'
    for (size_t i = 0; i < data.size(); i += channels) {
        // Standard Luminosity Formula: 0.21 R + 0.72 G + 0.07 B
        int r = data[i];
        int g = data[i+1];
        int b = data[i+2];
        
        uint8_t gray = (uint8_t)(0.2126f * r + 0.7152f * g + 0.0722f * b);
        grayData.push_back(gray);
    }

    // Update the object state
    data = grayData;
    channels = 1; // Now we are 1 channel
    std::cout << "Converted to Grayscale." << std::endl;
}