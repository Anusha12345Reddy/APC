#include "apc.h"

void print_list(Dlist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("\nHead -> ");
	    while (head)		
	    {
		    printf("%d <-", head -> data);

		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}