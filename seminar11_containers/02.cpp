#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<int> uniquenumbers;
    int num;

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> num;
        uniquenum.insert(num);
    }

    for (auto it = uniquenum.begin(); it != uniquenum.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}