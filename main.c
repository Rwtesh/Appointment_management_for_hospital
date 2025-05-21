#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void patient()
{
    int choice;
    printf("\n=============================================\n");
    printf(" Hello there! We wish you a very quick recovery.\n");
    printf("=============================================\n");

heyPat:
    printf("\nPlease choose an option:\n");
    printf("1. See list of doctors\n");
    printf("2. Book an appointment\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        doctors();
        goto heyPat;
        break;
    case 2:
        appointment(1);
        goto heyPat;
        break;
    case 3:
        appointment(2);
        goto heyPat;
        break;
    case 4:
        return;
    default:
        printf("\nInvalid choice. Please try again.\n");
        goto heyPat;
        break;
    }
}

void doctor()
{
    int choice;
    printf("\n=============================================\n");
    printf(" Hello Doctor! Hope you are doing well.\n");
    printf("=============================================\n");

heyDoc:
    printf("\nPlease choose an option:\n");
    printf("1. See appointments\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        appointment(3);
        goto heyDoc;
        break;
    case 2:
        return;
    default:
        printf("\nInvalid choice. Please try again.\n");
        goto heyDoc;
        break;
    }
}

int main()
{
    int a;
    int identity = 0;

    printf("\n=============================================\n");
    printf("     Welcome to Appointment Management System\n");
    printf("=============================================\n");

again:
    printf("\nPlease choose an option:\n");
    printf("1. Sign in\n");
    printf("2. New user\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &a);

    switch (a)
    {
    case 1:
        if ((identity = signIn()) > 0)
        {
            printf("\nLogin successful.\n");
        }
        else
        {
            printf("\nLogin failed. Try again.\n");
            goto again;
        }
        break;
    case 2:
        if (createAcc() == 1)
        {
            printf("\nAccount created successfully.\n");
        }
        goto again;
        break;
    case 3:
        printf("\nExiting the program. Goodbye!\n");
        return EXIT_SUCCESS;
    default:
        printf("\nInvalid input. Please try again.\n");
        goto again;
        break;
    }

    if (identity == 1)
        patient();
    if (identity == 2)
        doctor();

    return 0;
}
