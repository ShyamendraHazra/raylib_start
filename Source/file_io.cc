#include <iostream>
#include <fstream>
#include <string>
#include <file_io.h>

int write_file(std::string file_name, std::string file_content, std::ios::openmode mode) {
    
    if(!(file_name.length() > 0)) {
        std::cout << "file path is empty!" << std::endl;
        return 1;

    } else if (!(file_content.length() > 0)) {

        std::cout << "No content given" << std::endl;
        return 1;

    }
    
    std::fstream file;

    file.open(file_name, mode);

    if(!file.is_open()) {

        return 1;

    }

    file << file_content;

    std::cout << "Wrote " << file_content.length() << " characters to " << file_name << std::endl; 

    file.close();

    return 0;
    
}