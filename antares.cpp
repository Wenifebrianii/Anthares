%%writefile senyawa-nitrogentriflorida.cpp

#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

float densitas;         /*densitas ini memiliki satuan g cm^-3
                          dan ini harus diinput dari user */
// converter dari nilai cm^-3 ke A^3
float cm3_to_A3 = 1.0E-24;
float numb_mol;
float Na = 6.022E23;                        // bilangan avogadro
float Mr_nitrogentriflorida = 71.0;         // massa relatif dari nitrogentriflorida
int numb_lat;                               // panjang sel simulasi
int N;                                      // jumlah molekul
float volum;                                // volume dari molekul nitrogentriflorida
float lx, ly, lz;                           // panjang sel simulasi terhitung 
float lat;                                  // jarak antar molekul nitrogentriflorida

// variabel perhitungan energi potensial
float sigma = 2.725;                        // satuan (A)
float epsilon = 3.725;                      // satuan (kj/mol)
float rij, rcut, rcut2;
float Ep, Ep_LJ, A12, B6;
float rij6, rij12;
float dx, dy, dz;

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
 
    Nx[counter] = rB_Nx + (i*3.01);
    Ny[counter] = rB_Ny + (j*3.01);
    Nz[counter] = rB_Nz + (k*3.01);
    
    F1x[counter] = Nx[counter] + rB_F1x;
    F1y[counter] = Ny[counter] + rB_F1y;
    F1z[counter] = Nz[counter] + rB_F1z;

    F2x[counter] = Nx[counter] + rB_F2x;
    F2y[counter] = Ny[counter] + rB_F2y;
    F2z[counter] = Nz[counter] + rB_F2z;

F3x[counter] = Nx[counter] + rB_F3x;
    F3y[counter] = Ny[counter] + rB_F3y;
    F3z[counter] = Nz[counter] + rB_F3z;
    counter += 1;
    }
    }
    }

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("nitrogentriflorida-ruah.xyz");
    int N = 125*4;
    file << N << "\n" << endl;

    // iterasi dalam output array
    for (int m = 0; m < 125; m++){
    file << setw(4) << "N" << setw(4) << " "\
         << fixed << setprecision(4) << Nx[m] << setw(4) << " "\
         << fixed << setprecision(4) << Ny[m] << setw(4) << " "\
         << fixed << setprecision(4) << Nz[m] << "\n";

    file << setw(4) << "F" << setw(4) << " "\
         << fixed << setprecision(4) << F1x[m] << setw(4) << " "\
         << fixed << setprecision(4) << F1y[m] << setw(4) << " "\
         << fixed << setprecision(4) << F1z[m] << "\n";

    file << setw(4) << "F" << setw(4) << " "\
         << fixed << setprecision(4) << F2x[m] << setw(4) << " "\
         << fixed << setprecision(4) << F2y[m] << setw(4) << " "\
         << fixed << setprecision(4) << F2z[m] << "\n";
 
    file << setw(4) << "F" << setw(4) << " "\
         << fixed << setprecision(4) << F3x[m] << setw(4) << " "\
         << fixed << setprecision(4) << F3y[m] << setw(4) << " "\
         << fixed << setprecision(4) << F3z[m] << "\n";
    }

    file.close();

    cout << "program selesai!";

    return 0;
}
