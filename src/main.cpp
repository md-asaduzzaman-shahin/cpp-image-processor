#include "Image.h"
#include <iostream>

int main(int argc, char** argv) {
    // Simple CLI check
    if (argc < 2) {
        std::cout << "Usage: ./image_tool <input_file>" << std::endl;
        return 1;
    }

    Image img;
    if (img.load(argv[1])) {
        // Simulate a scanner pass: Convert to Grayscale
        img.toGrayscale();
        
        // Save as a new PNG
        if (img.save("scanned_doc.png")) {
            std::cout << "Success! Saved as scanned_doc.png" << std::endl;
        } else {
            std::cerr << "Failed to save." << std::endl;
        }
    }
    return 0;
}