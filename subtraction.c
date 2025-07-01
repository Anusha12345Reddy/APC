#include "apc.h"

//Subtract the two numbers
//Inputs: 3 - double Linked List pointers
//Output: Subtraction Result from two numbers
//Return Value: SUCCESS / FAILURE, on subtraction operation

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0, sub = 0, num1 = (*tail1)->data, num2 = (*tail2)->data;

    Dlist *temp1 = *tail1; 
    Dlist *temp2 = *tail2;

    if(((*head1)->data < 0) && ((*head2)->data < 0)) // num1 (-)    num2 (-)
    {
        (*head1)->data *= -1;
        (*head2)->data *= -1;
    }
    else if(((*head1)->data > 0) && ((*head2)->data < 0)) //num1 (+)    num2 (-)
    {
        //Addition //sign is always +ve
        (*head2)->data *= -1;
        if(addition(head1, tail1, head2, tail2, headR, tailR) == FAILURE)		
            return FAILURE;

        return SUCCESS;
    }
    else if(((*head1)->data < 0) && ((*head2)->data > 0)) //num1 (-)    num2 (+)
    {
        //Addition //sign is always -ve
        (*head1)->data *= -1;
        if(addition(head1, tail1, head2, tail2, headR, tailR) == FAILURE)		
            return FAILURE;

        return SUCCESS;
    }
    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp1 != NULL)  
        {
            num1 = temp1->data;
            temp1 = temp1->prev;
        } 
        else num1 = 0;
        
        if(temp2 != NULL)   
        {
            num2 = temp2->data;
            temp2 = temp2->prev;
        }
        else num2 = 0;

        if(borrow == 1)     
        {
            num1 -= 1;    
            borrow = 0;
        }                                                                                           

        if(num1 < num2)
        {
            num1 += 10;
            borrow = 1;
        }

        sub = num1 - num2;

        if(insert_first(headR, tailR, sub) == FAILURE)   
            return FAILURE;
    }
    return SUCCESS;
}
