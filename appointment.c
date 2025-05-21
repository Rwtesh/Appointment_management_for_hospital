#include <stdio.h>
#include <string.h>
#include "library.h"

void book()
{
    char name[20], check[20], pat[20], doc[20], date[20], time[20];
    char npat[20], ndate[20], ntime[20], ntime2[20];
    int validDoc = 0, flag = 0;
    int yn;

again:
    printf("\n=========================\n");
    printf(" Doctor Availability Menu\n");
    printf("=========================\n");
    printf("Which doctor's availability would you like to see?\n");
    doctors();
    printf("Enter doctor's name: ");
    scanf("%s", name);

    FILE *str = fopen("doctors.txt", "r");
    while (fscanf(str, "%s", check) != EOF)
    {
        if (compare(name, check) == 0)
            validDoc = 1;
    }
    fclose(str);

    if (validDoc == 0)
    {
        printf("Please enter a valid name.\n\n");
        goto again;
    }

    FILE *ptr = fopen("appointment.txt", "a+");
    rewind(ptr);
    printf("\nChecking appointments for Dr.%s...\n", name);
    while (fscanf(ptr, "%s %s %s %s", pat, doc, date, time) != EOF)
    {
        if (compare(name, doc) == 0)
        {
            flag = 1;
            printf("Doctor %s is busy on %s at %s\n", doc, date, time);
        }
    }

    if (flag == 0)
        printf("Doctor is free on all days.\n");

    printf("\nWould you still like to book an appointment with them?\n");
    printf("1 for Yes\n2 for No\nChoice: ");
    scanf("%d", &yn);
    if (yn == 2)
    {
        printf("Returning to doctor selection.\n\n");
        goto again;
    }

    printf("\nEnter your name: ");
    scanf("%s", npat);
    printf("Enter the date for which you would like to book an appointment (dd/mm/yyyy): ");
    scanf("%s", ndate);
    printf("From (hh:mm): ");
    scanf("%s", ntime);
    printf("Till (hh:mm): ");
    scanf("%s", ntime2);
    conc(ntime, "-");
    conc(ntime, ntime2);
    fprintf(ptr, "\n%s %s %s %s", npat, name, ndate, ntime);
    printf("\nYour appointment has been booked for %s %s with Dr.%s\n", ndate, ntime, name);
    printf("========================================\n");

    fclose(ptr);
}

int cancel()
{
    char name[20];
    char dname[20];
    char pat[20], doc[20], date[20], time[20];
    int flag = 0;

    printf("\n============================\n");
    printf(" Cancel an Appointment\n");
    printf("============================\n");
    printf("Enter your name: ");
    scanf("%s", name);

    FILE *ptr = fopen("appointment.txt", "r");
    FILE *new = fopen("temp.txt", "w");

    printf("\nYour appointments are:\n");
    while (fscanf(ptr, "%s %s %s %s", pat, doc, date, time) != EOF)
    {
        if (compare(name, pat) == 0)
        {
            flag = 1;
            printf("You have an appointment with Dr.%s on %s at %s.\n", doc, date, time);
        }
    }

    if (flag == 0)
    {
        printf("You have no appointments booked.\n");
        fclose(ptr);
        fclose(new);
        return 0;
    }

    flag = 0;
    rewind(ptr);
    printf("\nEnter the name of the doctor with whom you want to cancel your appointment: ");
    scanf("%s", dname);

    while (fscanf(ptr, "%s %s %s %s", pat, doc, date, time) != EOF)
    {
        if (compare(dname, doc) != 0 || strcmp(name, pat) != 0)
        {
            flag = 1;
            fprintf(new, "\n%s %s %s %s", pat, doc, date, time);
        }
    }

    if (flag == 1)
        printf("You have successfully cancelled your appointment with Dr.%s\n", dname);
    if (flag == 0)
        printf("Invalid operation.\n");

    fclose(ptr);
    fclose(new);
    remove("appointment.txt");
    rename("temp.txt", "appointment.txt");

    printf("====================================\n");

    return 0;
}

int see()
{
    char name[20];
    char pat[20], doc[20], date[20], time[20];
    int flag = 0;

    printf("\n============================\n");
    printf(" View Your Appointments\n");
    printf("============================\n");
    printf("Enter your name: ");
    scanf("%s", name);

    FILE *ptr = fopen("appointment.txt", "r");
    printf("\nYour upcoming appointments:\n");
    while (fscanf(ptr, "%s %s %s %s", pat, doc, date, time) != EOF)
    {
        if (compare(name, doc) == 0)
        {
            printf("You have an appointment with %s on %s at %s.\n", pat, date, time);
            flag = 1;
        }
    }

    if (flag == 0)
        printf("You don't have any appointments booked.\n");

    fclose(ptr);
    printf("========================================\n");

    return 0;
}

int appointment(int choice)
{
    switch (choice)
    {
    case (1):
        book();
        break;
    case (2):
        cancel();
        break;
    case (3):
        see();
        break;
    default:
        return 0;
    }
    return 0;
}
