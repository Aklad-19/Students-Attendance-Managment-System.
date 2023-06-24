
#include<stdio.h>
#include<stdlib.h>

// Function prototype
void ext(void);
// Function definition
void ext(void)
{
      system("cls");
      printf("\n  EXIT PAGE\n");
      char c_exit;
      fflush(stdin);
      printf("\n  Press 1 Cancel Exit");
      printf("\n  Press 0 For Exit Software");
      //scanf("%c", &c_exit);
      c_exit = getche();

switch (c_exit)  {
    case '1':
        home();//Calling home function for return to Home Portal
        break;
    case '0':
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t  THANKS FOR USING STUDENT ATTENDANCE MANAGEMENT SYSTEM");
        printf("\n\t\t\t\t  Press Any Key To EXIT......");
        getchar();
        exit(EXIT_SUCCESS);
        break;
    default:
        printf("\nINVALID KEYWORD\n");
        sleep(1000);
        ext();
        }
    return ;
}


