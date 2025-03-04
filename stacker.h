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

#include <iostream>
#include <string>
#include <fstream>
#include <vector>



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

  bool readPPM(const string& filename) {

    ifstream file(filename);
    if(!file) {
      cerr << "Could not open the file!" << endl; 
    return false; 
  
    } 
      file >> magic_number;
      if(magic_number != "P3") {
      cerr << "ERROR" << endl;
      return false; 
      }
      
      file >> width;
      file >> height;
      file >> max_color;

      pixels.clear(); 
      for(int i = 0; i < width * height; i++) {
        pixel p; 
	file >> p.red >> p.green >> p.blue;
        pixels.push_back(p);
      }
      
      return true; 

    }

  bool writePPM(const string& filename) {

    
    ofstream file(filename);
    if(!file) {

      cerr << "Error, could not open file" << endl;
      return false; 
      
    }


    file << magic_number << "\n" << endl;
    file << width << " " << height << "\n" << max_color << "\n"; 

    for(const auto& p : pixels) {

      file << p.red << " " << p.green << " " << p.blue << "\n"; 
    }
    
    return true;
  }
}; 

#endif
