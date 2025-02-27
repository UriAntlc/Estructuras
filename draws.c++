#include <iostream>

using namespace std;

int maximumDraws(int n);

int main() {
    int casos, color;
    cout << "Numero de casos ";
    cin >> casos;
    for (int i = 0; i < casos; i++) {
        cin >> color;
        int result = maximumDraws(color);
        cout << result << endl;
    }
    return 0;
}

int maximumDraws(int n) {
    return n + 1;
}