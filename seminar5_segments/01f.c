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
    Book** p = (Book**)malloc(1 * sizeof(Book*));
    *p = (Book*)malloc(1 * sizeof(Book));
    strcpy((*p)->title, "Don Quiexote");
    (*p)->price = 750.0;
    (*p)->pages = 1000;
    print_book(*p);
    
    free(*p);
    free(p);
}
