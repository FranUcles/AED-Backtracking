#include <vector>
#include <iostream>
#include "main.cpp"

using namespace std;

void Backtracking (vector<vector<bool>> capacidades, vector<int> &solucion, int averias){
    int nivel = 1;

    for (int i=0; i<averias;i++){
        solucion[i]=-1;
    }

    int max_av_actuales = 0;
    vector<int> SOA;                        //no se si es necesario iniciliazar el vector

    while (nivel!=0){
        Generar(nivel, solucion);
        if (Solucion(nivel, solucion) && Valor(solucion)>max_av_actuales){
            max_av_actuales = Valor(solucion);
            SOA = solucion;
        }
        if(Criterio(nivel, solucion)){
            nivel ++;
        } else {
            while (!MasHermanos(nivel, solucion) && nivel>0){
                Retroceder(nivel,solucion);
            }
        }
    }
}