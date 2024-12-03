#ifndef __ZKEY__
#define __ZKEY__

#include <array>
#include <fstream>
#include <stdexcept>
#include <iostream>

class ZKey {
public:
    static constexpr size_t KEY_SIZE = 1000;

    ZKey() {
        try {
            const char* filename = "bin/zobristkey";
            // std::cout << "Attempting to read Zobrist keys from: " << filename << std::endl;
            
            // Open file in binary mode
            std::ifstream file(filename, std::ios::binary);
            if (!file) {
                throw std::runtime_error("Failed to open zobristkey file");
            }

            // Read the entire file at once
            if (!file.read(reinterpret_cast<char*>(keys.data()), 
                          KEY_SIZE * sizeof(unsigned long))) {
                throw std::runtime_error("Failed to read zobristkey file");
            }

            file.close();
            // std::cout << "Successfully read Zobrist keys" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error initializing ZKey: " << e.what() << std::endl;
            throw; // Re-throw the exception after logging
        }
    }

    // Const access operator
    unsigned long operator[](size_t i) const {
        if (i >= KEY_SIZE) {
            throw std::out_of_range("ZKey index out of range");
        }
        return keys[i];
    }

private:
    std::array<unsigned long, KEY_SIZE> keys;
};

#endif // __ZKEY__
