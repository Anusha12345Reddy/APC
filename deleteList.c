// Delete List
// Inputs: Double linked list pointers
// Output: Double linked list pointers initialized with NULL
// Return Value: FAILURE / SUCCESS, based on nodes on the list
#include "apc.h"
int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)   return FAILURE;
    
    while((*head) != NULL)
    {
        *tail = (*tail)->prev;
        if((*tail) == NULL)
        {
            free(*head);
            *head = NULL;
            continue;
        }
        free((*tail)->next);
        (*tail)->next = NULL;
    }
    return SUCCESS;
}