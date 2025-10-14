#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct book 
{
    char* title;
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
    Book* p = (Book*)malloc(1 * sizeof(Book));
    p->title = (char*)malloc(20 * sizeof(char));
    strcpy(p->title, "Don Quixote");
    p->pages = 1000;
    p->price = 750.0;
    print_book(p);
    free(p->title);
    free(p);
}