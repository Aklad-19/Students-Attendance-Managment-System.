#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#include <conio.h>

#include "splashscreen.h"
#include "login.h"
#include "home.h"
#include "student_data.h"
#include "exit.h"
#include "attendence_data.h"





int main(void)
{
    int choice;
    system("color F3");
    splash_screen();
    sleep(5);
    system("cls");

    printf("\n\n\n\n\n\n");

    printf("\t\t\t\t\tPress '1' for Register \n");
    printf("\t\t\t\t\tPress '2' for Login\n\n\n");
    printf("\t\t\t\t\tEnter> ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        system("CLS");
        registe();
    }
    else if(choice ==2)
    {
        system("CLS");
        login();
    }else{
        printf("Invalid choice \n");
    }
    return 0;
}
