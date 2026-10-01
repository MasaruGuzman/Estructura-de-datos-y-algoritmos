// This program performs 3 different types of sorting algorithms to a vector, 
// and then uses 2 different types of search methods to find specific values.
// Juan Masaru Guzman Azano A01643073
// Last modification: 08/09/2026
#include <iostream>
#include <vector>

// Esta funcion recibe un vector de datos y lo ordena usando el algoritmo de burbuja.
// Complejidad:
// Mejor caso: O(n) cuando el vector ya est� ordenado.
// Peor caso: O(n^2) cuando el vector est� en orden inverso.
// Argumentos: std::vector<T>& data: un vector de datos tipo T que se desea ordenar.
// Salidas: void, el vector se ordena en su lugar.
template <typename T>
void ordenaBurbuja(std::vector<T>& data) {
    bool swapped = true;
    for (int pass = 0; pass < data.size() - 1 && swapped; pass++) {
        swapped = false;
        for (int j = 0; j < data.size() - 1 - pass; j++) {
            if (data[j + 1] < data[j]) {
                T tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                swapped = true;
            }
        }
    }
}

// Esta funcion recibe un vector de datos y lo ordena usando el algoritmo de selecci�n.
// Complejidad:
// Mejor caso: O(n^2) cuando el vector ya est� ordenado.
// Peor caso: O(n^2) cuando el vector est� en orden inverso. 
// Esto significa que es el mismo caso para este algoritmo.
// Argumentos: std::vector<T>& data: un vector de datos tipo T que se desea ordenar.
// Salidas: void, el vector se ordena en su lugar.
template <typename T>
void ordenaSeleccion(std::vector<T>& data) {
    for (int i = 0; i < data.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T tmp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = tmp;
        }
    }
}

// Esta funcion recibe un vector de datos y lo ordena usando el algoritmo de inserci�n.
// Complejidad:
// Mejor caso: O(n) cuando el vector ya est� ordenado.
// Peor caso: O(n^2) cuando el vector est� en orden inverso.
// Argumentos: std::vector<T>& data: un vector de datos tipo T que se desea ordenar.
// Salidas: void, el vector se ordena en su lugar.
template <typename T>
void ordenaInsercion(std::vector<T>& data) {
    for (int i = 1; i < data.size(); i++) {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Esta funcion recibe un vector de datos y un punto de b�squeda que tiene que encontrar, 
// emplea el m�todo de b�squeda secuencial para encontrar el punto de b�squeda.
// Complejidad:
// Mejor caso: O(1) cuando el elemento est� en la primera posici�n del vector.
// Peor caso: O(n) cuando el elemento est� en la �ltima posici�n del vector o no est� presente.
// Argumentos: 
// std::vector<T>& data: el vector de datos tipo T en el que se desea buscar.
// const T& target: el elemento que se desea encontrar dentro del vector.
// Salidas: 
// i: el �ndice del elemento encontrado en caso de que se encuentre en el vector.
// -1: en caso de que el elemento no se encuentre dentro del vector.
template <typename T>
int busqSecuencial(const std::vector<T>& data, const T& target) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

// Esta funcion recibe un vector de datos ordenado ascendentemente y un punto de b�squeda que tiene que encontrar, 
// emplea el m�todo de b�squeda binaria para encontrar el punto de b�squeda.
// Complejidad:
// Mejor caso: O(1) cuando el elemento esta en la primera posici�n del vector que se analiza.
// Peor caso: O(log n) cuando se requieren varias iteraciones o el elemento no est� presente en el vector.
// Argumentos: 
// std::vector<T>& data: el vector de datos tipo T en el que se desea buscar.
// const T& target: el elemento que se desea encontrar dentro del vector.
// Salidas: 
// i: el �ndice del elemento encontrado en caso de que se encuentre en el vector.
// -1: en caso de que el elemento no se encuentre dentro del vector.
template <typename T>  
int busqBinaria(const std::vector<T>& data, const T& target) {
    int min = 0;
    int max = static_cast<int>(data.size()) - 1; 

    while (min <= max) {
        int avg = min + (max - min) / 2;

        if (target == data[avg]) {
            return avg;
        }
        else if (target < data[avg]) {
            max = avg - 1;
        }   
        else {
            min = avg + 1;
        }
    }
    return -1;
}


int main() {
    std::vector<int> data = {29 ,10 ,14 ,37 ,10 ,5 ,22 ,18};

    std::vector<int> dataBurbuja = data;
    std::vector<int> dataSeleccion = data;
    std::vector<int> dataInsercion = data;

    ordenaBurbuja(dataBurbuja);
    ordenaSeleccion(dataSeleccion);
    ordenaInsercion(dataInsercion);

    int sequentialBubbleFound = busqSecuencial(dataBurbuja, 22);
    int binaryBubbleFound = busqBinaria(dataBurbuja, 22);

    int sequentialSeleccionFound = busqSecuencial(dataSeleccion, 22);
    int binarySeleccionFound = busqBinaria(dataSeleccion, 22);

    int binaryInsertionFound = busqBinaria(dataInsercion, 22);
    int sequentialInsertionFound = busqSecuencial(dataInsercion, 22);

    std::cout << "data burbuja: ";
    for (const int& value : dataBurbuja) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "data seleccion: ";
    for (const int& value : dataSeleccion) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "data insercion: ";
    for (const int& value : dataInsercion) {
    std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "\n";

    std::cout << "Bubble data: " << "\n";
    std::cout << dataBurbuja[binaryBubbleFound] << " found at index: " << binaryBubbleFound << ", using binary search.\n";
    std::cout << dataBurbuja[sequentialBubbleFound] << " found at index: " << sequentialBubbleFound << ", using sequential search.\n\n";

    std::cout << "Selection data: " << "\n";

    std::cout << dataSeleccion[binarySeleccionFound] << " found at index: " << binarySeleccionFound << ", using binary search.\n";
    std::cout << dataSeleccion[sequentialSeleccionFound] << " found at index: " << sequentialSeleccionFound << ", using sequential search.\n\n";

    std::cout << "Insertion data: " << "\n";
    std::cout << dataInsercion[binaryInsertionFound] << " found at index: " << binaryInsertionFound << ", using binary search.\n";
    std::cout << dataInsercion[sequentialInsertionFound] << " found at index: " << sequentialInsertionFound << ", using sequential search.\n";  

    return 0;
}

