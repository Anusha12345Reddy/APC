#include "apc.h"

int print_error()
{
    printf("\nERROR : ./a.out INVALID ARGUMENTS\n");
    printf("\nTo perform Addition please pass like ./a.out 50 + 10");
    printf("\nTo perform Subtraction please pass like ./a.out 50 - 10");
    printf("\nTo perform Multiplication please pass like ./a.out 10 x 50");
    printf("\nTo perform Division please pass like ./a.out 50 / 10\n");
    return 0;
}

void print_output(Dlist *headR)
{
    printf("\nOutput:");
    print_list(headR);
    printf("\n");
}

int change_head_data(Dlist **headR, Dlist **tailR, int data_)
{
    data_ *= -1;
    if (delete_first(headR, tailR) == FAILURE)
        return FAILURE;
    if (insert_first(headR, tailR, data_) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    int num1 = 0, num2 = 0;
    if (validate_args(argc, argv, &num1, &num2) == FAILURE)
    {
        return print_error();
    }

    int sub = 0, add_sign1 = 0, add_sign2 = 0, temp = 0;
    
    if (strstr(argv[2], "-"))
    {
        if (num1 < 0 && num2 < 0)
        {
            num2 *= -1;
            temp = -(num1);

            if (temp > num2)
            {
                num2 *= -1;
                add_sign1++;
            }
            else if (temp < num2)
            {
                num2 *= -1;
                add_sign2++;
                int swap = num1;
                num1 = num2;
                num2 = swap;
            }
            else if (temp == num2)
            {
                if (insert_first(&headR, &tailR, 0) == FAILURE)
                    return FAILURE;
                print_output(headR);
                return 0;
            }
        }
        else if (num1 > 0 && num2 > 0)
        {
            if (num1 < num2)
            {
                int swap = num1;
                num1 = num2;
                num2 = swap;
                sub++;
            }
            else if (num1 == num2)
            {
                if (insert_first(&headR, &tailR, 0) == FAILURE)
                    return FAILURE;
                print_output(headR);
                return 0;
            }
        }
        else if (num1 < 0 && num2 > 0)
        {
            sub++;
        }
        else if (!num1 && !num2)
        {
            if (insert_first(&headR, &tailR, 0) == FAILURE)
                return FAILURE;
            print_output(headR);
            return 0;
        }
        else if (!num1 && num2 > 0)
        {
            int swap = num1;
            num1 = num2;
            num2 = swap;
        }
    }
    else if (strstr(argv[2], "x") || (strstr(argv[2], "/") && (num1 <= 0 || num2 <= 0)))
    {
        if ((!num2 && num1) && strstr(argv[2], "/"))
        {
            printf("\nCANNOT DIVIDE BY ZERO\n");
            print_error();
            return 0;
        }
        else if ((!num2 && !num1) && strstr(argv[2], "/"))
        {
            printf("\nRESULT IS UNDEFINED\n");
            print_error();
            return 0;
        }
        else if ((!num2 || !num1) && strstr(argv[2], "x"))
        {
            if (insert_first(&headR, &tailR, 0) == FAILURE)
                return FAILURE;
            print_output(headR);
            return 0;
        }
        else if (num1 < 0 && num2 < 0)
        {
            num1 *= -1;
            num2 *= -1;
            sub = 0;
        }
        else
        {
            sub++;
            if (num2 < 0)
                num2 *= -1;
            else if (num1 < 0)
                num1 *= -1;
            else
                sub = 0;
        }
    }
    else if (strstr(argv[2], "+"))
    {
        if (num2 < 0 && num1 > 0)
        {
            temp = -(num2);
            if (temp > num1)
            {
                add_sign2++;
                int swap = num1;
                num1 = num2;
                num2 = swap;
            }
            else if (temp == num1)
            {
                if (insert_first(&headR, &tailR, 0) == FAILURE)
                    return FAILURE;
                print_output(headR);
                return 0;
            }
        }
        else if (num2 > 0 && num1 < 0)
        {
            temp = -(num1);
            if (temp > num2)
            {
                add_sign1++;
            }
            else if (temp < num2)
            {
                int swap = num1;
                num1 = num2;
                num2 = swap;
            }
            else if (temp == num2)
            {
                if (insert_first(&headR, &tailR, 0) == FAILURE)
                    return FAILURE;
                print_output(headR);
                return 0;
            }
        }
    }

    if (num1 && create_list(&head1, &tail1, num1) == FAILURE)
    {
        printf("\nINFO: Error in Create List\n");
        return 0;
    }
    else if (!num1 && insert_first(&head1, &tail1, 0) == FAILURE)
    {
        return FAILURE;
    }

    if (num2 && create_list(&head2, &tail2, num2) == FAILURE)
    {
        printf("\nINFO: Error in Create List\n");
        return 0;
    }
    else if (!num2 && insert_first(&head2, &tail2, 0) == FAILURE)
    {
        return FAILURE;
    }

    char operator = argv[2][0];
    if (operator == '+')
    {
        if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
            return FAILURE;
    }
    else if (operator == '-')
    {
        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
            return FAILURE;
    }
    else if (operator == 'x')
    {
        if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
            return FAILURE;
    }
    else if (operator == '/')
    {
        if (division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == FAILURE)
            return FAILURE;
    }
    else
    {
        printf("Invalid Input: Try again...\n");
    }

    if (sub || add_sign1 || add_sign2)
    {
        if (change_head_data(&headR, &tailR, headR->data) == FAILURE)
            return FAILURE;
    }

    print_output(headR);
    return 0;
}
