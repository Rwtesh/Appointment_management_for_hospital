#include <stdio.h>
#include <string.h>
#include "library.h"

int createAcc()
{
    char name[20];
    char pass[20];
    char role[20];

    FILE *ptr = fopen("users.txt", "a");
    FILE *str = fopen("doctors.txt","a");
    if (ptr == NULL)
    {
        printf("\n=============================================\n");
        printf(" Error opening file.\n");
        printf("=============================================\n");
        return 0;
    }
    fputs("\n", ptr);

    printf("\n=============================================\n");
    printf("             Create New Account              \n");
    printf("=============================================\n");

    printf("Enter your name (without spaces): ");
    scanf("%s", name);

    printf("Enter password (without spaces): ");
    scanf("%s", pass);

    printf("Enter your role (patient or doctor): ");
    scanf("%s", role);

    fprintf(ptr, "%s %s %s", name, pass, role);
    fclose(ptr);

    if(compare(role,"doctor")==0){
        fprintf(str,"%s\n",name);
    }
    fclose(str);

    printf("\nAccount successfully created for %s.\n", name);
    printf("=============================================\n");

    return 1;
}
