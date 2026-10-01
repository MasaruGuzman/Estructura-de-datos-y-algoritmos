#include <iostream>
#include "binarySearch.h"

int main() {
    std::vector<int> data = {0, 1, 2, 3, 7, 5, 6, 2};
    int locality = binarySearch(data, 7);
    std::cout << data[locality] << " found in locality " << locality << std::endl;
    return 0;
}