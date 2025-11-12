#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
        std::cout << std::endl;
}
void doubling(std::vector<int>& v)
{
    std::size_t length = v.size();
    v.reserve(length * 2);
    for (std::size_t i = 0; i < length; i++)
    {
        v.push_back(v[i]);
    }
}
int main()
{
std::vector<int> v {10, 20, 30};
doubling(v);
print(v); // Должно напечатать 10 20 30 10 20 30
}