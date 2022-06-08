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
    
    rcut = 3 * sigma;
    rcut2 = pow(rcut,2);
    
    cout << "program menghitung energi potensial dari nitrogentriflorida" << endl;
    cout << "Masukkan nilai densitas dari nitrogentriflorida (eg. 1.0): ";
    cin >> densitas;

    numb_mol = densitas * (Na / Mr_Nitrogentriflorida) * cm3_to_A3;
    cout << "Masukkan panjang sel simulasi (eg. 5): ";
    cin >> numb_lat;
    N = (pow(numb_lat,3)) * 3;
    volum = (float)N / numb_mol;

    // panjang sel simulasi secara perhitungan
    lx = pow(volum,(1.0/3.0));
    ly = lx;
    lz = lx;
    if(lx < (2*rcut)){
        cout << "sorry ya nilai sel simulasi kamu terlalu besar";
        exit(0);
    } else{
        cout << "panjang sel simulasi baru: " << lx << endl;
    }
    lat = lx / (float)numb_lat;
    
    //deklarasi variabel
    float pi = 3.14;
    
    // deklarasi senyawa nitrogentriflorida
    float Nx[125], Ny[125], Nz[125];
    float F1x[125], F1y[125], F1z[125];
    float F2x[125], F2y[125], F2z[125];
    float F3x[125], F3y[125], F3z[125];
    
    /*      F
            |
            N
           / \
          F   F
     molekul Nitrogentriflorida itu bentuk rigid
    */

    // masukkan nilai untuk setiap variabel NF3
    float rB_Nx = 0.0;
    float rB_Ny = 0.0;
    float rB_Nz = 0.0;

    float rB_F1x = sin(54.7355*pi/180) * 1.470;
    float rB_F1y = 0.0;
    float rB_F1z = cos(54.7355*pi/180) * 1.470;

    float rB_F2x = 0.0;
    float rB_F2y = sin(54.7355*pi/180) * 1.470;
    float rB_F2z = - cos(54.7355*pi/180) * 1.470;

    float rB_F3x = rB_F2x;
    float rB_F3y = - rB_F2y;
    float rB_F3z = rB_F2z;
    
    int counter = 0;
        for(int i = 0; i < numb_lat; i++){ //x
           for(int j = 0; j < numb_lat; j++){ //y
               for(int k = 0; k < numb_lat; k++){ //z 
 
    Nx[counter] = rB_Nx + (i*lat);
    Ny[counter] = rB_Ny + (j*lat);
    Nz[counter] = rB_Nz + (k*lat);
    
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

   // main hitung energi potensial
    A12 = 4.0 * epsilon * pow(sigma,12);
    B6 = 4.0 * epsilon * pow(sigma, 6);

    Ep = 0.0;
    for(int a = 0; a < (N-1); a++){
        for(int b = (0+1); b < N; b++){
            
            dx = Nx[a] - Nx[b];
            dy = Ny[a] - Ny[b];
            dz = Nz[a] - Nz[b];

            dx = dx - round(dx/lx) * lx;
            dy = dy - round(dy/ly) * ly;
            dz = dz - round(dz/lz) * lz;

            rij = pow(dx,2) + pow(dy,2) + pow(dz,2);
            if(rij < rcut2){
                rij6 = pow(rij,3);
                rij12 = pow(rij6,2);
                Ep = (A12/rij12) - (B6/rij6);
                Ep_LJ = (A12/rij12) - (B6/rij6);
                Ep += Ep_LJ;
            }
        }
    }

    cout << "Energi potensial dari senyawa nitrogentriflorida ruah: " \
         << Ep/(float)N << "kJ/mol";

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("nitrogentriflorida-ep.xyz");
    file << N << "\n" << endl;

    int Nw = N/4;

    // iterasi dalam output array
    for (int m = 0; m < Nw; m++){
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
