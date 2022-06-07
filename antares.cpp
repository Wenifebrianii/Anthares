%%writefile senyawa-nitrogentriflorida.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
  //deklarasi variabel
  float pi = 3.14;
  Int counter = 0;

    // deklarasi senyawa nitrogentriflorida
    float Nx[125], Ny[125], Nz[125];
    float F1x[125], F1y[125], F1z[125];
    float F2x[125], F2y[125], F2z[125];
    float F3x[125], F3y[125], F3z[125];

    // masukkan nilai untuk setiap variabel NF3
    float rB_Nx = 0.0;
    float rB_Ny = 0.0;
    float rB_Nz = 0.0;

    float rB_F1x = sin(55.2*pi/180) * 1.373;
    float rB_F1y = 0.0;
    float rB_F1z = cos(55.2*pi/180) * 1.373;

    float rB_F2x = 0.0;
    float rB_F2y = sin(55.2*pi/180) * 1.373;
    float rB_F2z = - cos(55.2*pi/180) * 1.373;

    float rB_F3x = 0.0;
    float rB_F3y = - rB_F2y;
    float rB_F3z = rB_F2z;
    
    // iterasi untuk setiap senyawa nitrogentriflorida
    for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
    for(int k = 0; k < 5; k++){
