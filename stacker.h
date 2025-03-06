/**
 * @file stacker.h
 * @author Noah Melton and Jose Jaime
 * @date 2025-02-20
 * @brief Header file for the stacker class
 * 
 * Header file for the stacker class
 */


#ifndef STACKER_H
#define STACKER_H
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


//a basic struct- I got some help on this from chatgpt and Justin Finn at the STEM lab

struct pixel {

  int red;
  int green;
  int blue;
};



/**
 * this is the stacker class which allows us to perform image stacking
 *
 * @class stacker stacker.h "Pathfinding-Pioneers/stacker.h"
 * @brief This is where we have the methods that make image stacking possible
 *
 */
class stacker {

public:
  string magic_number;
  int width;
  int height;
  int max_color;
 
  vector <pixel> pixels;

  stacker();
  
/**
 * This is the function that reads in the image pixel data. 
 *
 * @param const string& filename The name of the file that is to be read and used by the function. 
 * @param int fileAmount The number of images to be stacked. 
 * @pre This function must be passed a valid image with the correct formatting in order for it to work. 
 * @return void No return type, this function just writes to a file. 
 * @post 
 * 
 */

  // I got help on this function and the write ppm function from Justin Finn and chatgpt.
  
  void readPPM(const string& filename,int fileAmount);

  

/**
 * This is the function that writes the proper data (averaged pixel values) to a new file, which will be the finished image file. 
 *
 * @param const string& filename the name of the file to be stacked
 * @pre This function requires a name for the output file. 
 * @return void This function doesn't return anything. Instead, it creates a file that stores the pixel information for the finished image. 
 * @post A new file is created with all of the necessary pixel data to display a nice, clean image. 
 * 
 */
  void writePPM(const string& filename);

    
   
  
}; 

#endif
