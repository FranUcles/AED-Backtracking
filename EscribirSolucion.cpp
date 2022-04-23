#include <vector>
#include <fstream>
#include "main.cpp"
#include <iostream>
using namespace std;
/*escribir en el main
    cin << casos;            //escribimos el numero de resultados que vamos a mostrar
*/
//todo esto va dentro del bucle de casos
void EscribirSolucion(vector<bool> &seleccionados, vector<int> &solucion, int averias){
    cout << Valor;              //no se como esto no da error pero no me deja pasarle el parametro
    for (int i=0; i<averias; i++){
        if(solucion[i]<=0) cout << 0;
        else cout << solucion[i];
    }
    cout<<endl;
}




/**
 * si no me equivoco hay que imprimir el resultado de la funcion "valor", pero me sale un error rarisimo sobre referencia nula
    cout << Valor(seleccionados);                                                                       //imprimir numero de averias arregladas   
 * 
 */