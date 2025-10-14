#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book 
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(const Book* pb) 
{
    printf("Book: %s, Pages: %i, Price: %g\n", pb->title, pb->pages, pb->price);
}

int main()
{
    Book a;
    
    strcpy(a.title, "Don Quixote");
    a.pages = 1000;
    a.price = 750.0;
    Book* p = &a;
    print_book(p);

    free(p);
}
