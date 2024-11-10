#include <raylib.h>
#include <iostream>
#include <cmath>
#include <string>
#include <hex_to_rgb.h>

Color hexToRGBA(std::string hex) {
    Color rgba;
     
    if(hex.length() != 6) {
        exit(EXIT_FAILURE);
    } else {
        std::string red = hex.substr(0,2); 
        std::string green = hex.substr(2,2); 
        std::string blue = hex.substr(4,2); 


        rgba.r = hexToDeci(red);
        rgba.g = hexToDeci(green);
        rgba.b = hexToDeci(blue);
        rgba.a = 255;

    }

    return rgba;
}

int8_t hexToDeci(std::string hex) {

    int8_t hex_length = hex.length();
    int8_t decimal = 0;
    
    if(hex_length > 2) {

        std::cout << "Hex value More than supported length (2) given" << std::endl;
        exit(EXIT_FAILURE);

    }

    for(int i = 0; i < hex_length; i++) {
        int8_t exponent = hex_length - (1 + i);
        
        if (hex[i] >= '0' && hex[i] <= '9') {
            
            int multiplier = (int)(hex[i] - '0');
            decimal += multiplier * pow(16, exponent);
        
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            hex[i] -= 'A';
            hex[i] += 10;
            int16_t multiplier = (int16_t) (hex[i]);
            decimal += multiplier * pow(16, exponent);

        } else if(hex[i] >= 'a' && hex[i] <= 'f') {

            hex[i] -= 'a';
            hex[i] += 10;
            int16_t multiplier = (int16_t) hex[i];
            decimal += multiplier * pow(16, exponent);
        } else {
            std::cout << "Invalid hex value!!" << std::endl;
        }
    }

    return decimal;
}