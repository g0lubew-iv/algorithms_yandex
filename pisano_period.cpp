//
// Created by one_eyed_john on 30/06/23.
//

#include <iostream>
#include <vector>

// O(n)
int pis(int n, int m) {
    if (n <= 1) {
        return n;
    }

    std::vector<int> v = {0, 1};
    int temp;
    int prev = 0;
    int current = 1;

    for (int i = 0; i < (n - 1); i++) {
        temp = prev;
        prev = current % m;
        current = (temp + current) % m;
        v.push_back(current);

        if ((current == 1) && (prev == 0)) {
            // end of Pisano cycle
            return v[n % (i + 1)];
        }
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << pis(a, b);
    return 0;
}
