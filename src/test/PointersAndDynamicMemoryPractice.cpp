#include <iostream>

int main() {
    int a = 10, *p;
    p = &a;
    std::cout << a << " " << *p << std::endl;
    return 0;
}