#include <iostream>

using namespace std;

int divisores(int k);

int main() {
    int numero, divs, casos, i;
    cout << "Ingresa el numero de casos ";
    cin >> casos;
    for ( i = 0; i < casos; i++){
        cout << "Ingresa el numero ";
        cin >> numero ;
        divs = divisores(numero);
        cout << "El número de divisores pares de " << numero << " es: " << divs << endl;
    }
    return 0;
}

int divisores(int k) {
    int count = 0;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0 && i % 2 == 0) {
            count++;
        }
    }
    return count;
}