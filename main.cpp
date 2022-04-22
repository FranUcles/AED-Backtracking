#include <vector>
using namespace std;

const int NO_ELEGIDO = -1;
const int NUM_AVERIAS = 10;

void Generar(int &nivel, vector<int> &solucion){

}

bool Solucion(int nivel, vector<int> &solucion){

}

int Valor(vector<int> &solucion){
    int ocupados = 0;                                           // Guarda el número de mecánicos con una avería
    unsigned i = 0;
    while (i < solucion.size() && solucion[i] != NO_ELEGIDO) {  // Recorro solo hasta el punto donde no se haya asignado
        if (solucion[i] > 0)                                    // Contabiliza si ese mecánico tiene un trabajo
            ocupados++;
        i++;
    }
    return ocupados;                                            // Devuelvo los mecánicos ocupados
}

bool Criterio(int nivel, vector<int> &solucion){
    return nivel < solucion.size();                             // Compruebo si me queda algún mecánico por comprobar
}

bool MasHermanos(int nivel, vector<int> &solucion){
    if (solucion[nivel] == NUM_AVERIAS)                         // Si es el final, seguro que no hay más hermanos
        return false;
    int seleccionados = 0;                                      // Guardo el número de seleccionados menores que solucion[nivel]
    for (int i = 0; i < nivel; i++){
        if(solucion[i] > solucion[nivel])                       // Si es mayor que solucion[nivel] lo añado
            seleccionados++;
        i++;
    }
    return seleccionados < (NUM_AVERIAS - solucion[nivel]);     // Comparo, si hay menos seleccionados mayores que solucion[nivel] que posibles, sí hay hermanos
}

void Retroceder(int &nivel, vector<int> &solucion){
    solucion[nivel] = NO_ELEGIDO;                               // Lo pongo como no elegido
    nivel--;                                                    // Subo de nivel
}

void Backtracking(vector<int> &solucion){

}

int main(){
    
}
