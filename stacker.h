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

struct pixel {

  int red;
  int green;
  int blue;
};
  
class stacker {

public:
  string magic_number;
  int width;
  int height;
  int max_color;
 
  vector <pixel> pixels;

  stacker();
  
  /*
  stacker(){
    width = 0;
    height = 0;
    max_color = 0;
    magic_number = ""; 
  }

  **/
  void readPPM(const string& filename,int fileAmount);

  void writePPM(const string& filename);

    
   
  
}; 

#endif
