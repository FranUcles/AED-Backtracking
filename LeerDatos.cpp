#include <vector>
#include <fstream>

using namespace std;


/* todo esto es en el main

	ifstream entrada ("entrada.txt", ifstream::in); // abrimos el fichero
	entrada >> casos;								//leemos el numero de casos

*/
//en el main esto va metido en el bucle despues de haber leido el numero de casos
void LeerDatos(vector<vector<bool>> &capacidades, int &mecanicos, int &averias, ifstream &entrada){
	
	entrada >> mecanicos >> averias;					//numero de mecanicos y de averias
	
	for(int i=0; i<mecanicos; i++){
		for(int j=0; j<averias; j++){
			entrada >> capacidades[i][j];				//llenamos la matriz
		}
	}
}

/*al final del main

	etrada.close();								//cerramos el fichero
*/