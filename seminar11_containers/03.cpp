#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::multiset<int> sorted;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        sorted.insert(num);
    }
    for (const int& val : sorted) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}