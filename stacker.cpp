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





/**
 * This is the constructor for the stacker class. 
 *
 * @pre N/A
 * @post Initializes the stacker class
 * 
 */
stacker::stacker() {

  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0; 
}



/**
 * This is the file which reads the data from the images before stacking. Then it takes that data, and modifies it so that the output file can have the averages pixel values. 
 *
 * @param const string& filename the name of the file 
 * @param int fileAmount the number of times the image is to be stacked
 * @pre This requires a valid image to pull data from. 
 * @return void This function doesn't have a return type-instead it just reads in the data from the images so that they can be stacked. 
 * @post The file is populated with the data that will be vital for the writePPM funciton. 
 * 
 */
void stacker::readPPM(const string& filename,int fileAmount) {

  int temp = fileAmount; 
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

    cout << temp; 
    for(int i = 0; i < height * width; i++) {

      pixels[i].red = pixels[i].red / temp;
      pixels[i].green = pixels[i].green / temp;
      pixels[i].blue = pixels[i].blue / temp; 

    }
    
    cout << "Stacking Succeeded." << endl;
    cout << "Output written to: " << filename << ".ppm" << endl;

}


/**
 * This is the function which writes the final image data to a file so that the clean image can be displayed. 
 *
 * @param const string& filename the name of the file
 * @pre the name of the file
 * @return void This function does not return anything, instead it makes a new file which holds the image data of the clean image. 
 * @post A new file is made which holds the averaged values of the pixels. The result is a clean image. 
 * 
 */
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
