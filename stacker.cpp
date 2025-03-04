/**
 * @file stacker.cpp
 * @author Noah Melton and Jose Jaime
 * @date 2025-02-20
 * @brief Implementation of the stacker class
 * 
 * Implementation of the stacker class
 */


#include "stacker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


stacker::stacker() {

  magic_number = 0;
  width = 0;
  height = 0;
  max_color = ""; 
}

bool stacker::readPPM(const string& filename) {

  ifstream file(filename); 
  if(!file) {
    cerr << "error, could not open file" << endl;
    return false; 
  }

  file >> magic_number;
  if(magic_number != "P3") {
    cerr << "ERROR" << endl;
    return false

}
  file >> width >> height >> max_color;

  pixels.clear();
  for(int i = 0; i < width * height; i++) {
  pixel p;
  file >> p.red >> p.green >> p.blue
    pixels.push_back(p);
    }
  return true;
}

