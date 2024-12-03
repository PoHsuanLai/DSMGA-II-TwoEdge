#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

#define SIZE (1000)

int main() {
    std::cout << "Zobrist keys are " << sizeof(unsigned long)*8 << " bits.\n";
    
    // Generate keys using simple random
    std::vector<unsigned long> keys(SIZE);
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; ++i) {
        keys[i] = ((unsigned long)rand() << 32) | rand();
    }
    
    std::cout << SIZE << " keys are generated.\n";
    
    // Write to file using basic file operations
    const char* filename = "bin/zobristkey";
    std::cout << "Writing to file: " << filename << std::endl;
    
    // Create bin directory using system command
    #ifdef _WIN32
        system("if not exist bin mkdir bin");
    #else
        system("mkdir -p bin");
    #endif
    
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return 1;
    }
    
    outFile.write(reinterpret_cast<const char*>(keys.data()), 
                  SIZE * sizeof(unsigned long));
    
    if (!outFile) {
        std::cerr << "Error: Failed to write to file: " << filename << std::endl;
        return 1;
    }
    
    outFile.close();
    std::cout << "Done!\n";
    
    return 0;
}
