// This program performs the Gauss Sum with iterative, recursive and direct sum methods
// A01643073
// Date of creation: August 25, 2026
#include <iostream>
#include <stdexcept>

// This function performs the sum with an iterative method, it receives a variable n of type
// long long as parameter and returns another long long variable, which is the result of the sum    
// Computational Complexity: O(n)
long long iterativeSum(long long n) {
    if (n < 0) {
        throw std::invalid_argument("'n' should be greater or equal to 0.");
    } 
    else {
        long long totalSum = 0;
        for (long long i = 0; i <= n; i++) {
            totalSum += i;
        }
        return totalSum;
    }
}

// This function performs the sum with a recursive method, it receives a variable n of type
// long long as parameter and returns another long long variable, which is the result of the
// sum.
// Computational Complexity: O(n)
long long recursiveSum(long long n) {
    if (n < 0) {
        throw std::invalid_argument("'n' should be greater or equal to 0.");
    } 
    else if (n == 0) {
        return 0;
    } 
    else {
        return n + recursiveSum(n - 1);
    }
}

// This function performs the sum with the direct mathematical formula, it receives a variable 
// n of type long long as parameter and returns another long long variable, which is the result
// of the sum.
// Computational Complexity: O(1)
long long directSum(long long n) {
    if (n < 0) {
        throw std::invalid_argument("'n' should be greater or equal to 0.");
    } 
    else {
        return n * (n + 1) / 2;
    }
}

int main() {
    long long n = 0;
    std::cout << "Enter a value for n: ";
    std::cin >> n;

    try {
        long long nIterative = iterativeSum(n);
        std::cout << "iterativeSum: " << nIterative << std::endl;
        
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        long long nDirect = directSum(n);
        std::cout << "directSum: " << nDirect << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        long long nRecursive = recursiveSum(n);
        std::cout << "recursiveSum: " << nRecursive << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: "<< e.what() << std::endl;
    }

    return 0;
}