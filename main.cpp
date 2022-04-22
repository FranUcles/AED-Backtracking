#include <vector>
using namespace std;

void Generar(int &nivel, vector<int> &solucion){

}

bool Solucion(int nivel, vector<int> &solucion){

}

int Valor(vector<int> &solucion){
    int ocupados = 0;                                   // Guarda el número de mecánicos con una avería
    int i = 0;
    while (i < solucion.size() && solucion[i] != -1) {  // Recorro solo hasta el punto donde no se haya asignado
        if (solucion[i] > 0)                            // Contabiliza si ese mecánico tiene un trabajo
            ocupados++;
        i++;
    }
    return ocupados;                                    // Devuelvo los mecánicos ocupados
}

bool Criterio(int nivel, vector<int> &solucion){

}

bool MasHermanos(int nivel, vector<int> &solucion){

}

void Retroceder(int &nivel, vector<int> &solucion){

}

void Backtracking(vector<int> &solucion){

}

int main(){

}
