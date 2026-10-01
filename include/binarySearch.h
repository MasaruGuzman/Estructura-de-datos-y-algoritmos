/* 
This file implements the Binary Search algorithm using templates
*/
#pragma once
// Recomendado emplear vectores siempre 
#include <vector>

/*
A template for BinarySearch function.
args: 
    data: A vector with the data
    target: The item that we want to find 
returns
    The position of the target element
*/

template <typename T> // T is a template, which is any data which I haven't defined
// that I want to pass to this.

int binarySearch(const std::vector<T> &data, const T &target) {
    // min, max, avg, are indices
    int min = 0;
    int max = static_cast<int>(data.size()) -1; // esto está hecho para asegurarse
    // de que el dato que regrese sea entero

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
