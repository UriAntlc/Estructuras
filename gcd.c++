#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

char consiciones(const vector<int> &matriz, int k);

int main() {
    vector<int> matriz;
    int elementos;
    cout << "Cuantos elementos desea que tenga el vector ";
    cin >> elementos;
    for (int i = 0; i < elementos; i++){
        cout << "Ingrese el numero ";
        // revisar
        cin >> matriz[i];
    } 
    int k = matriz.size();
    char resultado = consiciones(matriz, k);
    cout << "El resultado es: " << resultado << endl;

    return 0;
}

char consiciones(const std::vector<int>& matriz, int k) {
    int n = matriz.size();
    if (n == 0) {
        return 'N';
    }
    unordered_set<int> unicos(matriz.begin(), matriz.end());
    if (unicos.size() != n) {
        return 'N';
    }
    for (int i = 0; i < n; i++) {
        int producto = 1;
        for (int j = i; j < n; j++) {
            producto *= matriz[j];
            if (producto % k == 0) {
                return 'N';
            }
        }
    }
    return 'S';
}