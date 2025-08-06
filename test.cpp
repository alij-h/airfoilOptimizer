#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

double getCord( double x , double t){
    double y = 5*t * ((0.2969*sqrt(x))-(0.1260*x)-(0.3516*(x*x))+(0.2843*(x*x*x))-(0.1015*(x*x*x*x)));
    return y;
} 

int main(){


    string input;
    cout<<"what airfoil would you like to test? (input naca number)"<<endl;
    cin>>input;
    ofstream outfile("input.txt");
    outfile <<"NACA "<<input <<endl;
    outfile << "OPER" <<endl;
    outfile << "VISC 500000" <<endl;
    outfile << "PACC" <<endl;
    outfile << "polarTEST.txt" <<endl;
    outfile << "\n";
    outfile << "ALFA 5" <<endl;
    outfile << "QUIT" <<endl;

    outfile.close();

   system("C:\\Users\\alehu\\XFOIL\\xfoil.exe < input.txt");
   ifstream outputFile("polarTEST.txt");
   if (!outputFile.is_open()){
    cerr <<"ERROR OPENING FILE" << endl;
   }
   string line;
   int linenum;
   double alpha, cl, cd, cdp, cm, top_xtr, bot_xtr;
   while (getline(outputFile, line)){
        if (linenum == 13){
            istringstream iss(line);
            iss >> alpha >> cl >> cd >> cdp >> cm >> top_xtr >> bot_xtr;

        }
        linenum++;
   }

   int result = remove("C:\\Users\\alehu\\Desktop\\AirfoilOptimizer\\polarTEST.txt");
   if (result == 0 ) {
    cout <<"File deleted sucessfully.\n";
   } else {
    cout << "Failed to delete file.\n";
   }

   cout<<"----------------------------------"<<endl;
   cout<<"AIRFOIL DEBUG"<<endl;
   cout<<"----------------------------------"<<endl;
   cout<<"alpha: "<<alpha<<endl;
   cout<<"cl: "<<cl<<endl;
   cout<<"cd: "<<cd<<endl;
   cout<<"cdp: "<<cdp<<endl;
   cout<<"cm: "<<cm<<endl;
   cout<<"top_xtr: "<<top_xtr<<endl;
   cout<<"bot_xtr: "<<bot_xtr<<endl;
}