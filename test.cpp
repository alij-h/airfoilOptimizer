#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include "GA.h"

using namespace std;

struct Point {
    float x, y;
};
float getBezier(double t, float p0, float p1, float p2, float p3, float p4, float p5) {
    float invT = 1.0f - t;
    
    return  1 * powf(invT, 5) * p0 +
            5 * powf(invT, 4) * t * p1 +
            10 * powf(invT, 3) * powf(t, 2) * p2 +
            10 * powf(invT, 2) * powf(t, 3) * p3 +
            5 * invT * powf(t, 4) * p4 +
            1 * powf(t, 5) * p5;
}

std::vector<Point> BezierToDat(BezierPoint chromosome[2][6], int numofPoints){
    std::vector<Point> coords;

    for(int i = 0  ; i<2; i++){
        int start, end, step;
        if (i == 0) {
            start = numofPoints;
            end = 0;
            step = -1;
        } else {
            start = 1;
            end = numofPoints;
            step = 1;
}
            for (int p = start; (step > 0) ? (p <= end) : (p >= end); p += step) {
                double t = double(p) / numofPoints;
                Point a;
                a.x = getBezier(t, 0 , chromosome[i][1].x, chromosome[i][2].x, 
                    chromosome[i][3].x, chromosome[i][4].x, 1);
                a.y = getBezier(t, chromosome[i][0].y , chromosome[i][1].y, 
                    chromosome[i][2].y, chromosome[i][3].y, chromosome[i][4].y, 
                    chromosome[i][5].y);
                coords.push_back(a);
            }
        return coords;
    }
};

void PointsToFile (std::vector<Point> Points){
    
};

int main(){

    string input;
    string outputfilename = "polarTEST3.txt";
    cout<<"what airfoil would you like to test? (input naca number)"<<endl;
    cin>>input;
    ofstream outfile("input.txt");
    outfile <<"NACA "<<input <<endl;
    outfile <<"PANE" <<endl;
    outfile << "OPER" <<endl;
    outfile << "VISC 500000" <<endl;
    outfile << "PACC" <<endl;
    outfile << outputfilename <<endl;
    outfile << "\n";
    outfile << "ASEQ -5 15 1" << endl;
    outfile << "\n";
    outfile << "QUIT" <<endl;

    outfile.close();

   system("C:\\Users\\alehu\\XFOIL\\xfoil.exe < input.txt");
   ifstream outputFile(outputfilename);
   if (!outputFile.is_open()){
    cerr <<"ERROR OPENING FILE" << endl;
   }
 
   int result = remove("polarTEST2.txt");
   if (result == 0 ) {  
    cout <<"File deleted sucessfully.\n";
   } else {
    cout << "Failed to delete file.\n";
   }
}