#include <iostream>
#include <list>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::list<int> warriors;
    for (int i = 1; i <= n; ++i) {
        warriors.push_back(i);
    }

    std::list<int>::iterator it = warriors.begin();
    std::vector<int> order;  


    while (!warriors.empty()) {
        for (int i = 1; i < m; ++i) {
            ++it;
            if (it == warriors.end()) {
                it = warriors.begin();
            }
        }
        order.push_back(*it);  
        it = warriors.erase(it);
        if (it == warriors.end() && !warriors.empty()) {
            it = warriors.begin();
        }
    }

    std::vector<int>::iterator order_it;
    for (order_it = order.begin(); order_it != order.end(); ++order_it) {
        std::cout << *order_it << " ";
    }
    std::cout << std::endl;
    std::cout << order.back() << std::endl; 
}