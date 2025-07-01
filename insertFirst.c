#include "apc.h"

// Insert at firt position of node
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)    
        return FAILURE;
    
    new->data = data;
    new->next = *head;
    new->prev = NULL;
    
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}