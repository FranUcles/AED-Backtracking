#include <vector>
using namespace std;

const int NO_ELEGIDO = -1;
const int NUM_AVERIAS = 10;
vector<bool> seleccionados(NUM_AVERIAS,false);                  // Array donde puedo ver si una avería ya ha sido asignada o no

void Generar(int &nivel, vector<int> &solucion){

}

bool Solucion(int nivel, vector<int> &solucion){

}

int Valor(vector<int> &solucion){
    int averias_asignadas = 0;                                  // Guarda el número de averías que tienen un mecánico
    for (int i = 0; i < NUM_AVERIAS; i++)                       // Recorre todas las averías, buscando la que estén asignadas
        if (seleccionados[i])
            averias_asignadas++;
    return averias_asignadas;                                           
}

bool Criterio(int nivel, vector<int> &solucion){
    return nivel < solucion.size();                             // Compruebo si me queda algún mecánico por comprobar
}

bool MasHermanos(int nivel, vector<int> &solucion){
    if (solucion[nivel] == NUM_AVERIAS)                         // Si es el final, seguro que no hay más hermanos
        return false;
    unsigned i = solucion[nivel];
    while(i < NUM_AVERIAS && seleccionados[i])                  // Busco el primero no seleecionado
        i++;
    return i < NUM_AVERIAS;
}

void Retroceder(int &nivel, vector<int> &solucion){
    seleccionados[solucion[nivel]] = false;                     // Quito la avería como elegida
    solucion[nivel] = NO_ELEGIDO;                               // Lo pongo como no elegido
    nivel--;                                                    // Subo de nivel
}

void Backtracking(vector<int> &solucion){

}

int main(){
    
}
