/**
 * @file main.cpp
 * @author Noah Melton and Jose Jaime
 * @date 2025-02-20
 * @brief Image Stacker assignment
 * 
 * This program averages 10 noisy images into one final high-quality image.
 */


#include "stacker.h"
#include <string> 
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

/**

This is where we test the functionality of the program. I got some help on this program from Justin Finn as well as some initial help from chatgpt. 

 **/ 


int main()
{
    string image; 
    int numImages;

    stacker stack;
    
    cout << "Please enter the image you wish to stack: ";
    cin >> image;

    cout << "Please enter the number of images: ";
    cin >> numImages;

    cout << "Stacking images:" << endl;

    
    stack.readPPM(image,numImages);
    

 
    stack.writePPM(image);
    return 0;
}
