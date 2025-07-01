#include "apc.h"

void insert_zeros(Dlist **head, Dlist **tail, int count_0s)
{
    while (count_0s > 0)
    {
        insert_first(head, tail, 0);
        count_0s--;
    }
}

//Multiply the two numbers
//Inputs: 5 - double Linked List
//Output: Multiplication Result from two numbers
//Return Value: SUCCESS / FAILURE, on multiplication operation
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *headr = NULL, *tailr = NULL;
    Dlist *bckhead = NULL, *bcktail = NULL;

    int num1 = 0, num2 = 0, carry = 0, mul = 0, data = 0, count = 0, flag = 0;

    Dlist *temp1 = *tail1;  
    Dlist *temp2 = *tail2;
    
    while (temp2 != NULL)
    {
        num1 = temp2->data;
        flag = 1;
        while (temp1 != NULL)
        {
            num2 = temp1->data;
            mul = (num1 * num2) + carry;
            data = mul % 10;
            carry = mul / 10;
            
            if (count == 0)  
                insert_first(headR, tailR, data);
            else
            {
                if (flag == 1)
                {
                    insert_zeros(&headr, &tailr, count);
                    flag = 0;
                }
                insert_first(&headr, &tailr, data);
            }
            temp1 = temp1->prev;
        }

        if (carry)  
        {
            insert_first(&headr, &tailr, carry);
            carry = 0;  // Reset carry after using it
        }

        if (headr != NULL)
        {
            addition(headR, tailR, &headr, &tailr, &bckhead, &bcktail);

            // Free the temp list properly
            delete_list(&headr, &tailr);
            
            // Update headR only after deletion
            *headR = bckhead;
            *tailR = bcktail;
            bckhead = NULL;
            bcktail = NULL;
        }
        
        count++;
        temp2 = temp2->prev;
        temp1 = *tail1;
    }
    return SUCCESS;
}
