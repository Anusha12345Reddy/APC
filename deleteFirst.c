// Delete First Node on List
// Inputs: Double linked list pointers
// Output: list with nodes
// Return Value: FAILURE / SUCCESS, based on node deletion

#include "apc.h"
int delete_first(Dlist **head, Dlist **tail)
{
    if(*head == NULL)   return FAILURE;
    
    *head = (*head)->next;
    if(*head == NULL)//Only one node
    {
        free(*tail);
        *tail = NULL;
        return SUCCESS;
    }
    
    free((*head)->prev);
    (*head)->prev = NULL;
    return SUCCESS;
}

// Remove Zeros at First
int remove_zeros_atFirst(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;

    while(temp != NULL)
    {
        if(temp->data == 0)     
            delete_first(head, tail);
        else    
            return SUCCESS;
        temp = temp->next;
    }

    return SUCCESS;
}