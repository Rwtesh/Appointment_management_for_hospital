#include <stdio.h>
#include <string.h>
#include "library.h"

int signIn()
{
    char name[20];
    char pass[20];
    char user[20], p[20], role[20];
    int flag = 0;

    printf("\n=============================================\n");
    printf("                  Sign In                    \n");
    printf("=============================================\n");

    printf("Enter username (without spaces): ");
    scanf("%s", name);

    printf("Enter password (without spaces): ");
    scanf("%s", pass);

    FILE *ptr = fopen("users.txt", "r");
    if (ptr == NULL)
    {
        printf("\nError opening users file.\n");
        return 0;
    }

    while (fscanf(ptr, "%s %s %s", user, p, role) != EOF)
    {
        if (compare(name, user) == 0 && compare(pass, p) == 0)
        {
            if (compare("patient", role) == 0)
                flag = 1;
            else
                flag = 2;
            break;
        }
    }

    fclose(ptr);

    if (flag == 0)
    {
        printf("\nLogin failed. Incorrect username or password.\n");
        printf("=============================================\n");
        return 0;
    }
    else
    {
        printf("\nLogin successful. Welcome, %s!\n", name);
        printf("=============================================\n");
        return flag;
    }
}
