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

  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0; 
}

void stacker::readPPM(const string& filename,int fileAmount) {

    int i = 1; 
    while(fileAmount > 0) {


      ostringstream ss;                                                         
      ss << setw(3) << setfill('0') << i;                                       
      string numberStr = ss.str();                                              
      string image = "./" +  filename  + "/" + filename + "_" + numberStr + ".ppm"; 

    ifstream file; 
    file.open(image);
    if(!file) {
      cerr << "Could not open the file!" << endl; 
    return; 
  
    }
   
      file >> magic_number;
      if(magic_number != "P3") {
	cout << magic_number; 
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

      fileAmount--;
      i++;

      cout << image << endl;
      
    }
    cout << "Stacking Succeeded." << endl;
    cout << "Output written to: " << filename << ".ppm" << endl;
   }
void stacker::writePPM(const string& filename) {

    
    ofstream file;
    file.open(filename + ".ppm"); 
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
 
