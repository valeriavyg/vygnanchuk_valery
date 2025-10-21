#include <stdio.h>
#include <stdlib.h>
#include "2list.h"

List init(size_t n) 
{
    List list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; i++) 
        push_back(&list, 0);
    return list;
}

void print(const List* pl) 
{
    if (pl == NULL)
    {
        fprintf(stderr, "Error:  NULL pointer received\n");
        exit(1);
    }
    Node* current = pl->head;
    while (current != NULL) 
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (pl == NULL)
    {
        fprintf(stderr, "Error: Cannot add element to NULL list\n");
        exit(1);
    }

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;
    
    if (pl->tail != NULL) 
        pl->tail->next = new_node;
    else 
        pl->head = new_node;
    
    pl->tail = new_node;
    pl->size++;
}

int pop_back(List* pl) 
{
    if (pl->tail == NULL || pl == NULL)
    {
        fprintf(stderr, "Error: Cannot pop from NULL list\n");
        exit(1);
    }
    
    Node* last = pl->tail;
    int value = last->value;
    
    if (last->prev != NULL) 
    {
        last->prev->next = NULL;
        pl->tail = last->prev;
    } 
    else 
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    free(last);
    pl->size--;
    return value;
}

void push_front(List* pl, int value) 
{
    if (pl == NULL)
    {
        fprintf(stderr, "Error:  NULL pointer received\n");
        exit(1);
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        fprintf(stderr, "Error: Cannot push from NULL list\n");
        exit(1);
    }
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = pl->head;
    
    if (pl->head != NULL) 
        pl->head->prev = new_node;
    else 
        pl->tail = new_node;
    
    pl->head = new_node;
    pl->size++;
}

int pop_front(List* pl) 
{
    if (pl->head == NULL || pl == NULL ) 
    {
        fprintf(stderr, "Error: Cannot pop from empty list\n");
        exit(1);
    }
    
    Node* first = pl->head;
    int value = first->value;
    
    if (first->next != NULL) 
    {
        first->next->prev = NULL;
        pl->head = first->next;
    }
    else 
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    
    free(first);
    pl->size--;
    return value;
}

Node* erase(List* pl, Node* p) {
    if (p == NULL || pl == NULL) return NULL;
    
    if (p->prev != NULL) 
        p->prev->next = p->next;
    else 
        pl->head = p->next;
    
    
    if (p->next != NULL) 
        p->next->prev = p->prev;
    else 
        pl->tail = p->prev;
    
    
    Node* next_node = p->next;
    free(p);
    pl->size--;
    
    return next_node;
}

void splice(List* plist, Node* p, List* pother) 
{
    if (pother->head == NULL)  return;
    
    if (p != NULL) {
        if (p->prev != NULL) {
            p->prev->next = pother->head;
            pother->head->prev = p->prev;
        }
        else
        {
            plist->head = pother->head;
        }
        
        pother->tail->next = p;
        p->prev = pother->tail;
    } 
    else 
    {
        if (plist->tail != NULL) {
            plist->tail->next = pother->head;
            pother->head->prev = plist->tail;
        } 
        else 
        {
            plist->head = pother->head;
        }
        plist->tail = pother->tail;
    }
    
    plist->size += pother->size;
    
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) 
{
    if (pl == NULL)
    {
        fprintf(stderr, "Error:  NULL pointer received\n");
        exit(1);
    }
    Node* current = pl->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) {
    if (*pp == NULL) return;
    
    for (size_t i = 0; i < n && *pp != NULL; i++) {
        *pp = (*pp)->next;
    }
    
}