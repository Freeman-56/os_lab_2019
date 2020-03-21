#include <stdio.h>
#include <string.h>
#include "revert_string.h"

void RevertString(char *str)
{
	char temp;
    int length = strlen(str), i;
    for(i = 0; i < (length / 2); i++)
    {
        temp = str[i];
        str[i] = str[(length - 1) - i];
        str[(length - 1) - i] = temp;
    }
}

