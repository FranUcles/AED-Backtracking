#include <vector>
#include <iostream>
using namespace std;

const int NO_ELEGIDA = -1;        

void Generar(int &nivel, vector<int> &solucion, vector<vector<bool>> &apto, vector<bool> &seleccionados){
    if (solucion[nivel] > 0)                                                                // Si la avería ya tenía un mecánico
        seleccionados[solucion[nivel] - 1] = false;                                         // quitarlo de los seleccionados, pues se puede coger otra vez
    int num_mecanicos = seleccionados.size();
    int i = (solucion[nivel] == -1 ? -1 : solucion[nivel] - 1);
    do {
        i++;
    } while (i < num_mecanicos && (seleccionados[i] || !apto[i][nivel]));                   // Busco el primero no seleccionado delante del actual y que el mecánico pueda reparar
    if (i == num_mecanicos)                                                                 // Si no quedan, siempre se quedará el 0
        solucion[nivel] = 0;
    else{                                                                                   // Si queda alguna avería, se asigna la encontrada
        solucion[nivel] = i + 1;                                                            // Asigno el seleccionado
        seleccionados[i] = true;                                                            // Lo marco como avería ya asignada
    }            
}

bool Solucion(int nivel, vector<int> &solucion){
    return nivel == solucion.size() - 1;                                                    // Compruebo si he asginado todos los mecánicos
}

int Valor(vector<int> &solucion){
    int averias_asignadas = 0;                                                              // Guarda el número de averías que tienen un mecánico
    for (int i = 0; i < solucion.size(); i++)                                               // Recorre todas las averías buscando las que tengan mecánico
        if (solucion[i] > 0)
            averias_asignadas++;
    return averias_asignadas;                                           
}

bool Criterio(int nivel, vector<int> &solucion, int max_valor_actual, int mecanicos){
    if (nivel == solucion.size() - 1)                                                       // Compruebo si me queda algún mecánico por comprobar
        return false;
    if (max_valor_actual == mecanicos)                                                      // Si la solución ya es la óptima, no importan las otras soluciones
        return false;
    int restantes = solucion.size() - nivel - 1;                                            // Número de averías por elegir
    int valor = Valor(solucion);                                                            // Número de averías elegidas actualmente
    return max_valor_actual < restantes + valor;                                            // Devuelvo si se puede mejorar la mejor solución
}

bool MasHermanos(int nivel, vector<int> &solucion, vector<vector<bool>> &apto, vector<bool> &seleccionados){
    int num_mecanicos= seleccionados.size();
    if (solucion[nivel] == 0)                                                               // Si es el final, seguro que no hay más hermanos
        return false;
    unsigned i = solucion[nivel] - 1;                   
    do {
        i++;
    } while(i < num_mecanicos && (seleccionados[i] || !apto[i][nivel]));                    // Busco el primero no seleccionado y que sea apto para ese mecánico
    return i < num_mecanicos;
}

void Retroceder(int &nivel, vector<int> &solucion, vector<bool> &seleccionados){
    if (solucion[nivel] != 0)                                                               // Quito el mecanico como elegido
        seleccionados[solucion[nivel] - 1] = false;                                         // en caso de ser alguno    
    solucion[nivel] = NO_ELEGIDA;                                                           // Lo pongo como no elegido
    nivel--;                                                                                // Subo de nivel
}

void Backtracking(vector<int> &solucion, vector<vector<bool>> &apto, vector<bool> &seleccionados, int averias, int mecanicos){
    int nivel = 0;                                                                          // Inicializo el nivel
    for (int i = 0; i < averias; i++)                                                       // Inicializo la solución
        solucion[i] = NO_ELEGIDA;                                                           // ...
    int max_av_actuales = 0;                                                                // Inicializo el máximo de la soluciones
    vector<int> SOA(averias);                                                               // Creo el vector de la mejor solución
    while (nivel >= 0){
        Generar(nivel, solucion, apto, seleccionados);                                      // Genero el siguiente nodo
        if (Solucion(nivel, solucion) && Valor(solucion) > max_av_actuales){                // Compruebo si es solución y si el valor es mayor
            max_av_actuales = Valor(solucion);                                              // Actualizo el máximo valor actual
            SOA = solucion;                                                                 // Actualizo la solución óptima actual
        }
        if(Criterio(nivel, solucion, max_av_actuales, mecanicos)){                          // Si se puede llegar a una solución, se baja un nivel
            nivel++;
        } else {                                                                            
            while (!MasHermanos(nivel, solucion, apto, seleccionados) && nivel >= 0){       // Compruebo si quedán otras opciones en ese nivel
                Retroceder(nivel,solucion, seleccionados);                                  // Subo de nivel
            }
        }
    }
    solucion = SOA;                                                                         // Elijo la solución como la mejor solución
}

int main(){
    int casos;
    cin >> casos;
    cout << casos << endl;
    for (int c = 1; c <= casos; c++){
        int mecanicos;                                                                      // Número de mecánicos que hay
        int averias;                                                                        // Número de averías que hay 
        cin >> mecanicos >> averias;
        vector<bool> seleccionados(mecanicos);            
        vector<vector<bool>> apto(mecanicos, vector<bool>(averias));                        // Array que determina si un mecánico puede o no reparar una avería
        vector<int> solucion(averias);                                                      // Array de la solución
        for(int i = 0; i < mecanicos; i++){                                                 // Rellena la matriz
		    for(int j = 0; j < averias; j++){
                int apto_int;                                                               // Variable auxiliar para guardar el valor booleano en forma de entero
			    cin >> apto_int;				                                            // Lectura del valor booleano en forma de entero
                if (apto_int == 1)                                                          // Asignación del valor correspondiente a la matriz
                    apto[i][j] = true;
                else
                    apto[i][j] = false;
		    }
        }
        Backtracking(solucion, apto, seleccionados, averias, mecanicos);                    // Ejecuto el algoritmo de Backtracking
        int arregladas = Valor(solucion);                                                   // Calculo cuantas averías hay arregladas
        cout << arregladas << endl;                                                         // Imprimo el valor de la solución
        for (int i = 0; i < averias - 1; i++)                                               // Imprimo la solución
            cout << solucion[i] << " ";
        cout << solucion[averias - 1] << endl;
	}
}
