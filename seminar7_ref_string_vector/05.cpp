#include <iostream>
struct Book
{
    std::string title;
    int pages;
    float price;
};
bool isExpensive(const Book& a) 
{
    if (a.price > 1000) 
        return true;
    else return false;
}
int main() 
{
    Book a = {"Harry Potter", 100, 100.0};
    Book b = {"Physics", 1000, 2000.0};
    std::cout << isExpensive(a) << std::endl;
    std::cout << isExpensive(b) << std::endl;
}