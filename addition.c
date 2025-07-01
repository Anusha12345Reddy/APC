#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0, num1 = 0, num2 = 0, sum = 0, data = 0, sign = 0;
    
    // Use temporary variables to store the first node values
    int first_digit1 = (*head1)->data;
    int first_digit2 = (*head2)->data;

    /* Conditions:
       Addition:
        - num1 (+) + num2 (+)
        - num1 (-) + num2 (-) -> Convert to positive and track sign
       Subtraction:
        - num1 (+) + num2 (-)
        - num1 (-) + num2 (+)
    */
    if (first_digit1 < 0 && first_digit2 < 0)  // num1 (-) + num2 (-)
    {
        sign = 1;
        first_digit1 *= -1;  // Convert to positive
        first_digit2 *= -1;  // Convert to positive
    }
    else if (first_digit1 > 0 && first_digit2 < 0)  // num1 (+) + num2 (-)
    {
        first_digit2 *= -1;  // Convert to positive
        return subtraction(head1, tail1, head2, tail2, headR, tailR);
    }
    else if (first_digit1 < 0 && first_digit2 > 0)  // num1 (-) + num2 (+)
    {
        first_digit1 *= -1;  // Convert to positive
        return subtraction(head1, tail1, head2, tail2, headR, tailR);
    }

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while (temp1 != NULL || temp2 != NULL)
    {
        num1 = (temp1 != NULL) ? temp1->data : 0;
        num2 = (temp2 != NULL) ? temp2->data : 0;

        sum = num1 + num2 + carry;
        data = sum % 10;
        carry = sum / 10;

        if (insert_first(headR, tailR, data) == FAILURE) return FAILURE;

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    if (carry)
    {
        if (insert_first(headR, tailR, carry) == FAILURE) return FAILURE;
    }

    // If the result should be negative, flip the sign of the first node
    if (sign)
    {
        if ((*headR)->data != 0)  // Prevent adding negative zero
        {
            (*headR)->data *= -1;
        }
    }

    return SUCCESS;
}
