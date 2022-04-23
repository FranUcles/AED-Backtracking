#include <vector>
#include "main.cpp"
using namespace std;

void Generar(int &nivel, vector<int> &solucion){
    int i = nivel;
    while (seleccionados[i]){
        i++;
    }
    solucion[i] = true;
}