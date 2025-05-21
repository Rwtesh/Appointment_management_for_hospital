#include <stdio.h>
#include <string.h>
#include "library.h"

int doctors()
{
    char name[20];
    FILE *ptr = fopen("doctors.txt", "r");
    if (ptr == NULL)
    {
        printf("\n=============================================\n");
        printf(" Error opening doctors file.\n");
        printf("=============================================\n");
        return 0;
    }

    printf("\n=============================================\n");
    printf("               Available Doctors             \n");
    printf("=============================================\n");

    while (fscanf(ptr, "%s", name) != EOF)
    {
        printf(" - %s\n", name);
    }

    printf("=============================================\n");

    fclose(ptr);
    return 0;
}
