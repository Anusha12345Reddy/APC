#include "apc.h"

int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return SUCCESS;
    else
        return FAILURE;
}

int my_alnum(char *str)
{
    int i = 0;
    if ((str[i] == '+') || (str[i] == '-'))  
        i++;

    while (str[i] != '\0')
    {
        if (is_digit(str[i]) == FAILURE)
        {
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}

//Converts the string into integer
//Inputs: String
//Output: number
//Return Value: number, based on the string
int my_atoi(char *str)
{
    int sign = 0, num = 0, i = 0;
    
    if (str[i] == '-')
    {
        sign = 1;
        i = 1;
    }
    else if (str[i] == '+')
    {
        sign = 2;
        i = 1;
    }
    else
    {
        i = 0;
    }

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = (num * 10) + (str[i] - '0');
        }
        else 
        {
            break;
        }
        i++;
    }
    
    if (sign == 1)
        return -num;
    else
        return num;
}

int validate_args(int argc, char* argv[], int *num1, int *num2)
{
    if (argc != 4)   
        return FAILURE;

    if (my_alnum(argv[1]) == SUCCESS && my_alnum(argv[3]) == SUCCESS)
    {
        if (strcmp(argv[2], "+") == 0 || strcmp(argv[2], "-") == 0 || strcmp(argv[2], "x") == 0 || strcmp(argv[2], "/") == 0)
        {
            *num1 = my_atoi(argv[1]);
            *num2 = my_atoi(argv[3]);
            return SUCCESS;
        }
    }
    return FAILURE;
}
