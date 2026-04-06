#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

// bubble sort
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

//funçãodividir
int particionar(vector<int>& v, int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;
    return i + 1;
}

//Quick sort 
void quickSort(vector<int>& v, int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particionar(v, inicio, fim);
        quickSort(v, inicio, posicaoPivo - 1);
        quickSort(v, posicaoPivo + 1, fim);
    }
}

int main() {
    vector<int> numeros;
    ifstream arquivo("arq.txt");


    int num;
    while (arquivo >> num) {
        numeros.push_back(num);
    }

    arquivo.close();


    double somaBubble = 0;
    double somaQuick = 0;
    cout << "Algoritmo: Bubble Sort" << endl;
    for (int i = 0; i < 5; i++) {
        vector<int> copia = numeros;
        auto inicio = high_resolution_clock::now();
        bubbleSort(copia);
        auto fim = high_resolution_clock::now();
        double tempo = duration<double>(fim - inicio).count();
        somaBubble += tempo;
        cout << "Execucao " << i + 1 << ": " << tempo << "s" << endl;
    }

    double mediaBubble = somaBubble / 5;
    cout << "Media: " << mediaBubble << "s" << endl << endl;

    cout << "Algoritmo: Quick Sort" << endl;
    for (int i = 0; i < 5; i++) {
        vector<int> copia = numeros;
        auto inicio = high_resolution_clock::now();
        quickSort(copia, 0, copia.size() - 1);
        auto fim = high_resolution_clock::now();
        double tempo = duration<double>(fim - inicio).count();
        somaQuick += tempo;
        cout << "Execucao " << i + 1 << ": " << tempo << "s" << endl;
    }

    double mediaQuick = somaQuick / 5;
    cout << "Media: " << mediaQuick << "s" << endl;
    vector<int> ordenado = numeros;
    quickSort(ordenado, 0, ordenado.size() - 1);
    ofstream saida("arq-ordenado.txt");


    for (int i = 0; i < ordenado.size(); i++) {
        saida << ordenado[i];
        if (i < ordenado.size() - 1) {
            saida << " ";
        }
    }
    saida.close();
    system("pause");
    return 0;
}