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
Point BezierToDat(Point a, BezierPoint chromosome[2][6]){
    for(float t = 0;t<1.0f;t+= 0.01f){
        float t1 = pow(1,5)*(chromosome[0][5]-(5*bp[4])+(10*bp))
        a.x = ((1.0-t)^5);
        a.y = 
    };
};
void Bezier

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