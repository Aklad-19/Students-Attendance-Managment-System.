#include <stdio.h>


//Function Prototype
void home(void);
void attendance_data(void);
void search_attendance(void);
void search_attendance1(int tdt);
void search_student_attendance(void);
void view_student_att(void);
void student_data(void);
void ext(void);



//Function for Home Portal
void home(void) {
    system("cls");
    char tswitch;
    printf("\n\n\n");

    printf("\n\n\t\t\t\t\t  ===Home Portal===\n\n\n\n\n");

    printf("\t\t\t\t\t ==> 1. Input Attendance\n");
    printf("\t\t\t\t\t ==> 2. View Attendance\n");
    printf("\t\t\t\t\t ==> 3. Search a Student Attendance\n");
    //printf("\t\t\t\t\t ==> 4. Edit Attendance\n");
    printf("\t\t\t\t\t ==> 4. Student Data\n");
    printf("\t\t\t\t\t ==> 5. Log Out\n");
    printf("\t\t\t\t\t ==> 6. Exit Program\n\n\n");

    printf("\t\t\t\t\t Select an Option:");

    tswitch = getche();
    switch (tswitch) {
    case '1':
        attendance_data();// Call the function for inputting attendance
        break;
    case '2':
        search_attendance();// Call the function for viewing attendance
        break;
    case '3':
        search_student_attendance();// Call the function for viewing attendence for a single student
        break;

    case '4':
        student_data();// Call the student_data function for save, view and delete student data
        break;
    case '5':
        login(); // Call the login function for logging out
        break;
    case '6':
        ext();
    default:
        printf("\n\n\t\t\t\t\t  INVALID KEYWORD\n");
        Sleep(1000);
        home();
  }
  return ;

}
