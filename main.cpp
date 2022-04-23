#include <vector>
#include <iostream>
using namespace std;

const int NO_ELEGIDO = -1;        

void Generar(int &nivel, vector<int> &solucion, vector<vector<bool>> &apto, vector<bool> &seleccionados){
    int num_averias = seleccionados.size();
    int i = solucion[nivel];
    do{
        i++;
    } while (i < num_averias && seleccionados[i] && apto[nivel][i]);    // Busco el primero no seleccionado delante del actual y que el mecánico pueda reparar
    if (i == num_averias)                                               // Si no quedan, siempre se quedará el 0
        solucion[nivel] = 0;
    else{                                                               // Si queda alguna avería, se asigna la encontrada
        solucion[nivel] = i;                                            // Asigno el seleccionado
        seleccionados[i] = true;                                        // Lo marco como avería ya asignada
    }            
}

bool Solucion(int nivel, vector<int> &solucion){
    return nivel == solucion.size();                            // Compruebo si he asginado todos los mecánicos
}

int Valor(vector<int> &solucion){
    int averias_asignadas = 0;                                  // Guarda el número de averías que tienen un mecánico
    for (int i = 0; i < solucion.size(); i++)                   // Recorre todas los mecánicos buscando los que tengan averías
        if (solucion[i] == 1)
            averias_asignadas++;
    return averias_asignadas;                                           
}

bool Criterio(int nivel, vector<int> &solucion){
    return nivel < solucion.size();                             // Compruebo si me queda algún mecánico por comprobar
}

bool MasHermanos(int nivel, vector<int> &solucion, vector<vector<bool>> &apto, vector<bool> &seleccionados){
    int num_averias = seleccionados.size();
    if (solucion[nivel] == 0)                                               // Si es el final, seguro que no hay más hermanos
        return false;
    unsigned i = solucion[nivel];
    do {
        i++;
    } while(i < num_averias && (seleccionados[i] || !apto[nivel][i]));     // Busco el primero no seleccionado y que sea apto para ese mecánico
    return i < num_averias;
}

void Retroceder(int &nivel, vector<int> &solucion, vector<bool> &seleccionados){
    seleccionados[solucion[nivel]] = false;                     // Quito la avería como elegida
    solucion[nivel] = NO_ELEGIDO;                               // Lo pongo como no elegido
    nivel--;                                                    // Subo de nivel
}

void Backtracking(vector<int> &solucion, vector<vector<bool>> &apto, vector<bool> &seleccionados, int averias, int mecanicos){
    int nivel = 0;
    for (int i = 0; i < mecanicos; i++)
        solucion[i] = NO_ELEGIDO;
    int max_av_actuales = 0;
    vector<int> SOA(mecanicos);                        
    while (nivel >= 0){
        Generar(nivel, solucion, apto, seleccionados);
        if (Solucion(nivel, solucion) && Valor(solucion) > max_av_actuales){
            max_av_actuales = Valor(solucion);
            SOA = solucion;
        }
        if(Criterio(nivel, solucion)){
            nivel++;
        } else {
            while (!MasHermanos(nivel, solucion, apto, seleccionados) && nivel >= 0){
                Retroceder(nivel,solucion, seleccionados);
            }
        }
    }
}

int main(){
    int casos;
    cin >> casos;
    for (int c = 1; c <= casos; c++){
        int mecanicos;                                                      // Número de mecánicos que hay
        int averias;                                                        // Número de averías que hay 
        cin >> mecanicos >> averias;            
        vector<vector<bool>> apto(mecanicos);                               // Array que determina si un mecánico puede o no reparar una avería
        vector<int> solucion(mecanicos);                                    // Array de la solución
        vector<bool> seleccionados(averias, false);                         // Array donde puedo ver si una avería ya ha sido asignada o no
        for(int i = 0; i < mecanicos; i++){                                 // Rellena la matriz
		    for(int j = 0; j < averias; j++){
                int apto_int;                                               // Variable auxiliar para guardar el valor booleano en forma de entero
			    cin >> apto_int;				                            // Lectura del valor booleano en forma de entero
                if (apto_int == 1)                                          // Asignación del valor correspondiente a la matriz
                    apto[i][j] = true;
                else
                    apto[i][j] = false;
		}
        Backtracking(solucion, apto, seleccionados, averias, mecanicos);    // Ejecuto el algoritmo de Backtracking
	}
}
