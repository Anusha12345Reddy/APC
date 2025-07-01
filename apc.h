#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;


/* Include the prototypes here */

/*store the operands into the list */
void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/*Addition */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Validation*/
int validate_args(int argc, char *argv[], int *num1, int *num2);

/*Create List*/
int create_list(Dlist **head, Dlist **tail, int num);

/*Insert First*/
int insert_first(Dlist **head, Dlist **tail, int data);

/*Delete First*/
int delete_first(Dlist **head, Dlist **tail);

/*Delete Zeros at First*/
int remove_zeros_atFirst(Dlist **head, Dlist **tail);

/*Delete List*/
int delete_list(Dlist **head, Dlist **tail);

/*Print List*/
void print_list(Dlist *head);

#endif
