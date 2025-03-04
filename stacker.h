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

  void readPPM(const string& filename,int fileAmount) {

    int i = 0; 
    while(fileAmount > 0) {


      ostringstream ss;                                                         
      ss << setw(3) << setfill('0') << i;                                       
      string numberStr = ss.str();                                              
      string image = filename + "/" + filename + "_" + numberStr + ".ppm"; 

    ifstream file; 
    file.open(filename);
    if(!file) {
      cerr << "Could not open the file!" << endl; 
    return; 
  
    }


   
      file >> magic_number;
      if(magic_number != "P3") {
      cerr << "ERROR" << endl;
      return; 
      }
      
      file >> width;
      file >> height;
      file >> max_color;

      pixels.resize(height * width); 
      for(int i = 0; i < width * height; i++) {
        pixel p; 
	file >> p.red >> p.green >> p.blue;
        pixels[i].red += p.red;
	pixels[i].green += p.green;
	pixels[i].blue += p.blue;
      }
      
    }

    i++;
    fileAmount--;
  }

  void writePPM(const string& filename) {

    
    ofstream file;
    file.open(filename); 
    if(!file) {

      cerr << "Error, could not open file" << endl;
      return; 
      
    }


    file << magic_number << "\n" << endl;
    file << width << " " << height << "\n" << max_color << "\n"; 

    for(const auto& p : pixels) {

      file << p.red << " " << p.green << " " << p.blue << "\n"; 
    }

   
  }
  
}; 

#endif
