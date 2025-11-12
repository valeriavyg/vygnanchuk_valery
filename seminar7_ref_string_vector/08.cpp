#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    
    for (std::size_t i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (std::isalpha(c))
            numLetters++;
        else if (std::isdigit(c))
            numDigits++;
    }
}

int main()
{
    std::string test = "M1P71stH3b3s7";
    int letters, digits;
    countLetters(test, letters, digits);
    std::cout << "Букв: " << letters << ", Цифр: " << digits << std::endl;
}
