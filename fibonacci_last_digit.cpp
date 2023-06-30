//
// Created by one_eyed_john on 30/06/23.
//

#include <iostream>

// O(n)
int fib(int n) {
    if (n <= 1) {
        return n;
    }

    int array[n];
    array[0] = 0;
    array[1] = 1;

    for (int i = 2; i < n; i++) {
        array[i] = (array[i - 1] + array[i - 2]) % 10;
    }

    return (array[n - 1] + array[n - 2]) % 10;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n);
    return 0;
}
