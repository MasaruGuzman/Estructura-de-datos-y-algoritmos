//Recursive methods

#include <iostream>
using namespace std;

/*int factorial (int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}*/

/*int factorialIterative (int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
long fibonacci(int n) {
    // Naive approach
    // En este método, visualmente es un codigo sencillo de entender, pero ineficiente 
    // computacionalmente un método iterativo podría servir mejor
    // Guardar valores en un array podría servir mejor para evitar recalcular
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}*/

long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial (n-1);
    }
}

long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

long power(int base, int n) {
    if (n == 0) {
        return 1;
    } else {
        return base * power(base, n-1);
    }
}

bool palindrome(char str[], int i, int f) {

    if (i >= f) {
        return true;
    } else if (str[i] != str[f]) {
        return false;
    } else {
        return palindrome(str, i + 1, f - 1);
    } 

}


int main() {
    /*int nIterative = factorialIterative (5);
    cout << "5! = " << nIterative << endl;

    int m = fibonacci(10);
    cout << "Fibonacchi(10) = " << m << endl;
    return 0;*/

    long n = factorial (5);
    cout << "5! = " << n << endl;
    
    long m = fibonacci(10);
    cout << "Fibonacchi(10) = " << m << endl;

    long a = power(5, 2);
    cout << "5^2 = " << a << endl;

    char str[] = {'r', 'a', 'd', 'a', 'r'};
    int strSize = sizeof(str)-1;
    cout << "String size: " << strSize << endl;
    bool answer = palindrome(str, 0, strSize);
    cout << answer << endl;
    
    return 0;
}

