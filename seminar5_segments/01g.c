#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct book 
{
    char title[50];
    int pages;
    float price;
};

void print_book(const Book* pb) 
{
    printf("Book: %s, Pages: %i, Price: %g\n", pb->title, pb->pages, pb->price);
}

typedef struct book Book;

int main() {
    Book* p = (Book*)malloc(3 * sizeof(Book));
    strcpy(p[0].title, "Don Quixote");
    strcpy(p[1].title, "Oblomov");
    strcpy(p[2].title, "The Odyssey");

    int pages[] = {1000, 400, 500};
    float prices[] = {750.0, 250.0, 500.0};
    for (int i = 0; i < 3; i++)
    {
        p[i].pages = pages[i];
        p[i].price = prices[i];
    }
    for (int i = 0; i < 3; i++) 
    {
        print_book(p + i);
    }
    free(p);
}