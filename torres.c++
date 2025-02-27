#include <iostream>
using namespace std;

int main() {
    int casos, total, caminos, torres;
    int i,j;
    cout << "Numero de casos ";
    cin >> casos;
    for ( i = 0; i < casos; i++) {
        total =1;
        cout << "Numero de torres ";
        cin >> torres;
    for ( j = 1; j < torres; j++) {
        cout << "Numero de caminos ";
        cin >> caminos;
        total = (total * caminos) % 1234567;
    }
    cout << "total ";
    cout << total << endl;
    }
    return 0;
}