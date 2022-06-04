%%writefile senyawa-nitrogentriflorida.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main(){
  //deklarasi variabel
  float pi = 3.14;

    // deklarasi senyawa nitrogentriflorida
    float Nx, Ny, Nz;
    float F1x, F1y, F1z;
    float F2x, F2y, F2z;
    float F3x, F3y, F3z;

    // masukkan nilai untuk setiap variabel NF3
    Nx = Ny = Nz = 0.0;

    F1x = sin(55.2*pi/180) * 1.373;
    F1y = 0.0;
    F1z = cos(55.2*pi/180) * 1.373;

    F2x = 0.0;
    F2y = sin(55.2*pi/180) * 1.373;
    F2z = - cos(55.2*pi/180) * 1.373;

    F3x = 0.0;
    F3y = - F2y;
    F3z = F2z;

// memasukkan nilai tersebut ke dalam File
    ofstream file;
    file.open("nitrogentriflorida.xyz");
    file << "4\n" << endl;
    file << setw(4) << "N" << setw(4) << " "\
    << fixed << setprecision(4) << Nx << setw(4) << " "\
    << fixed << setprecision(4) << Ny << setw(4) << " "\
    << fixed << setprecision(4) << Nz << "\n";

    file << setw(4) << "F" << setw(4) << " "\
    << fixed << setprecision(4) << F1x << setw(4) << " "\
    << fixed << setprecision(4) << F1y << setw(4) << " "\
    << fixed << setprecision(4) << F1z << "\n";

    file << setw(4) << "F" << setw(4) << " "\
    << fixed << setprecision(4) << F2x << setw(4) << " "\
    << fixed << setprecision(4) << F2y << setw(4) << " "\
    << fixed << setprecision(4) << F2z << "\n";
  
    file << setw(4) << "F" << setw(4) << " "\
    << fixed << setprecision(4) << F3x << setw(4) << " "\
    << fixed << setprecision(4) << F3y << setw(4) << " "\
    << fixed << setprecision(4) << F3z << "\n";


    file.close();

    cout << "program selesai!";

    return 0;
}
