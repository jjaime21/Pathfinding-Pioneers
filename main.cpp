/**
 * @file main.cpp
 * @author Noah Melton and Jose Jaime
 * @date 2025-02-20
 * @brief Image Stacker assignment
 * 
 * This program averages 10 noisy images into one final high-quality image.
 */



#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;


void readPPM(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open " << filename << endl;
        return;
    }

    string magic_number;
    file >> magic_number;
    if (magic_number != "P3") {
        cerr << "Error: " << filename << " is not a PPM P3 file." << endl;
        return;
    }

    int width, height, max_color;
    file >> width >> height >> max_color;

    cout << width << height << max_color;
}

int main()
{
    string image; 
    int numImages;

    cout << "Please enter the image you wish to stack: ";
    cin >> image;

    cout << "Please enter the number of images: ";
    cin >> numImages;

    cout << "Stacking images:" << endl;

    vector<string> filenames;
    
    
    for (int i = 1; i <= numImages; i++) {
      ostringstream ss;
      ss << setw(3) << setfill('0') << i;
      string numberStr = ss.str(); 
        string filename = image + "/" + image + "_" + numberStr + ".ppm";
        filenames.push_back(filename);
        cout << "     " << filename << endl;
    }

    for (const auto& filename : filenames) {
        readPPM(filename);
    }

    /*
    ofstream image;
    image.open("test.ppm");

    if (image.is_open())
    {
        image << "P3" << endl;
        image << "250 250" << endl;
        image << "255" << endl;

        for (int y = 0; y < 250; y++)
        {
            for (int x = 0; x < 250; x++)
            {
                image << (x * y) % 255 << " " << x << " " << x << endl;
            }
        }
    }



    

    */

    return 0;
}
