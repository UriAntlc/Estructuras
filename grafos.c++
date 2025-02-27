//Lomas Castillo Uriel
//Hernandez Zamora Alejandro
//Maldonado Romero Daniel

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;
const int tam = 10;

void buscar(vector<vector<int> >& matriz, int visitados[tam], int nodoInicial, int nodoFinal);

vector<vector<int> > leerMatrizDesdeCSV(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int> > matriz;
    if (archivo) {
        string linea;

        while (getline(archivo, linea)) {
            vector<int> fila;
            stringstream ss(linea);
            string valor;
            while (getline(ss, valor, ',')) {
                fila.push_back(stoi(valor));
            }
            matriz.push_back(fila);
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
    }
    return matriz;
}
    
int main() {
    string nombreArchivo = "grafo.csv";
    vector<vector<int> > matriz = leerMatrizDesdeCSV(nombreArchivo);

    int visitados[tam] = {0};
    int nodoInicial, nodoFinal;

    cout << "Ingrese el nodo inicial: ";
    cin >> nodoInicial;

    cout << "Ingrese el nodo final: ";
    cin >> nodoFinal;

    cout << "El recorrido desde el nodo " << nodoInicial << " hasta el nodo " << nodoFinal << " es: ";
    buscar(matriz, visitados, nodoInicial, nodoFinal);
    cout << endl;

    return 0;
}

void buscar(vector<vector<int> >& matriz, int visitados[tam], int nodoInicial, int nodoFinal) {
    visitados[nodoInicial] = 1;
    cout << nodoInicial << " ";

    if (nodoInicial == nodoFinal) {
        return;
    }

    for (int i = 0; i < tam; ++i) {
        if (matriz[nodoInicial][i] == 1 && !visitados[i]) {
            buscar(matriz, visitados, i, nodoFinal);
            if (visitados[nodoFinal] == 1) {
                return;
            }
        }
    }
}