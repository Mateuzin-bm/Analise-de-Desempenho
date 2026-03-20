#include <iostream>
using namespace std;

int main() {
    int N;
    do {
        cout << "Digite um numero: ";
        cin >> N;
        if (cin.fail() || N <= 0) {
            cout << "Entrada invalida! Tente novamente.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (N <= 0);
    cout << "\nValor de N: " << N << endl;
    cout << "Numeros primos: ";
    int contador = 0;

    for (int i = 2; i <= N; i++) {
        int ehPrimo = 1;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                ehPrimo = 0;
                break;
            }
        }

        if (ehPrimo == 1) {
            if (contador > 0) {
                cout << " - ";
            }
            cout << i;
            contador++;
        }
    }
    
    cout << "\nQuantidade de numeros primos: " << contador << endl;
    system("pause");
    return 0;
}