#include<stdio.h>


void attendance_data(void);
void search_attendance(void);
void search_attendance1(int tdt);
void search_student_attendance(void);
void view_student_att(void);
void gotoxy(int x, int y);



typedef struct s_attendance{
    char date[30];
    char sid[30];
    char ati[5];
    char sname[50];
    int att_count;
}s_attendance;

typedef struct s_attendance2 {
    char date[30];
    char sid[30];
    char ati[5];
    char sname[50];
    int att_count;
}s_attendance2;

void attendance_data(void) {
    system("cls");
    student std;
    s_attendance s_att;
    /*int i = 0;
    int count = 0;
    char name[100];
    int id[100];*/
    char date[100];
    int found = 0;
    char att_cmp[5] = {"p"};

    char att_cmp1[5] = {"a"};
      FILE * fptr1;
      fptr1 = fopen("Student info.txt", "r");
      FILE * chdate;
      chdate = fopen("Attendance.txt", "r");

      printf("\n\n\n\t\t\t\t\tEnter Current date[dd/mm/yyyy]:");
      scanf("%s", date);
      while (fread( & s_att, sizeof(s_att), 1, chdate)) {
        if (strcmp(date, s_att.date) == 0) {
          found = 1;
    }
  }

  if (found == 0) {
    while (fread( & std, sizeof(std), 1, fptr1)) {
      fflush(stdin);
      strcpy(s_att.date, date);
      strcpy(s_att.sid, std.id);
      strcpy(s_att.sname, std.name);

      printf("\n\n\t\t\t\t\t  Student Name: %s\n\t\t\t\t\t  Student ID: %s\n\n  ", s_att.sname, s_att.sid);
      printf("\t\t\t\t  Press [p] for present and [a] for absent....");
      scanf("%s",  s_att.ati);

      if (strcmp(s_att.ati, att_cmp) == 0 || strcmp(s_att.ati, att_cmp1) == 0) {
        if (strcmp(s_att.ati, att_cmp) == 0) {
          s_att.att_count = s_att.att_count + 1;
        }
        if (strcmp(s_att.ati, att_cmp1) == 0) {
          s_att.att_count = s_att.att_count + 0;
        }
      } else {
        printf("\n\n\t\t\t\t  Invalid Attendance Case Try Again...!!\n");

      }

      FILE * att1;
      att1 = fopen("Attendance.txt", "a");

      if (att1 == NULL) {
        printf("Error\n");
        exit(1);
      }
      fwrite( & s_att, sizeof(s_att), 1, att1);
      fclose(att1);
    }

    printf("\n  SAVE SUCCESS\n\n\n");
    char end;
    printf("  Press 1 for Input more attendance\n");
    printf("  Press 2 for go Back\n");
    printf("  Press 3 for EXIT Software\n");
    printf(" Select an Option:");

    end = getche();

    switch (end) {
    case '1':
      attendance_data();
      break;
    case '2':
      home();
      break;
    case '3':
      ext();
      break;
    default:
      printf("\n  INVALID KEYWORD\n");
      Sleep(1000);
      home();
    }
  } else {

    printf("\n\t\t\t\t\tAttendance Already Taken. TRY ANOTHER DATE\n\n");
    sleep(2000);

    attendance_data();
  }

  return ;
}
void search_attendance(void) {
    int tdt = 0;
    s_attendance s_att;
    FILE * fptdt;
    fptdt = fopen("Attendance.txt", "r");
    while (fread( & s_att, sizeof(s_att), 1, fptdt)) {
    tdt = tdt + 1;
    }
    fclose(fptdt);
    search_attendance1(tdt);

    //EXIT_Switch
    char end;
    printf("\n\n  Press 1 for search more attendance\n");
    printf("  Press 2 for go Back\n");
    printf("  Press 3 for EXIT Software\n");
    printf(" Select an Option:");

    end = getche();

    switch (end) {
    case '1':
        search_attendance();
        break;
    case '2':
        home();
        break;
    case '3':
        ext();
        break;
    default:
        printf("\nINVALID KEYWORD\n");
        sleep(1000);
        home();
  }

    return ;
}

void search_attendance1(int tdt) {
    system("cls");
    s_attendance s_att;
    printf("\n\t\t\t\t\t\tSEARCH ATTENDANCE \n");
    //int lc = 0;
    char sr_att[30];

    printf("\n\t\t\t\t  Enter the date you want to search attendance: ");

    scanf("%s", sr_att);
    system("cls");
    FILE * fpsr;
    fpsr = fopen("Attendance.txt", "r");
    printf("\n\n  \t\t\t\tDate: %s\n", sr_att);

    while (fread( & s_att, sizeof(s_att), 1, fpsr)) {
        if (strcmp(sr_att, s_att.date) == 0) {
          printf("\n  Student Name: %s\n  Student ID: %s\n  Attendance: %s\n", s_att.sname, s_att.sid, s_att.ati);
        }
      }

      return ;
}

void search_student_attendance(void) {
    system("cls");
    student std;
    s_attendance s_att;
    float present = 0;
    float absent = 0;
    int y = 25;

    float count = 0;
    float count1 = 0;

    char p[50] = {"p"};
    char a[50] = {"a"};
    FILE * ssatt;
    ssatt = fopen("Attendance.txt", "r");
    char id[30];
    char dtls;
    int  found = 0;
    view_student_att();

    gotoxy(50, 5);
    printf(" Enter The ID You Want To Search: ");

    fflush(stdin);
    gets(id);

    while (fread( & s_att, sizeof(s_att), 1, ssatt)) {
        if (strcmp(id, s_att.sid) == 0) {
          if (strcmp(p, s_att.ati) == 0) {
            present = present + 1;
          } else {
            absent = absent + 1;
          }
          count = count + 1;
          found = 1;
        }
      }
      if (found == 0) {

        gotoxy(51, 10);
        printf("DATA NOT FOUND");

      } else

      {
        char idfc[20];
        FILE * stdptr1;
        stdptr1 = fopen("Student info.txt", "r");
        while (fread( & std, sizeof(std), 1, stdptr1)) {
          strcpy(idfc, std.id);
          break;
        }
        fclose(stdptr1);
        FILE * stdptr2;
        stdptr2 = fopen("Attendance.txt", "r");
        while (fread( & s_att, sizeof(s_att), 1, stdptr2)) {
          if (strcmp(idfc, s_att.sid) == 0) {
            count1 = count1 + 1;
          }
        }
        fclose(stdptr2);

    FILE * stdptr;
    stdptr = fopen("Student info.txt", "r");
    while (fread( & std, sizeof(std), 1, stdptr)) {
        if (strcmp(id, std.id) == 0) {

        gotoxy(50, 7);
        printf(">> Attendance <<\n\n");

        gotoxy(50, 9);
        printf("Name:%s", std.name);
        gotoxy(50, 10);
        printf("ID: %s", std.id);
        gotoxy(50, 11);
        printf("Department: %s", std.department);
        gotoxy(50, 12);
        printf("Section: %s", std.section);
        gotoxy(50, 14);
        printf("Total Class: %0.0f", count1);
        gotoxy(50, 15);
        printf("Present: %0.0f Days", present);
        gotoxy(50, 16);
        printf("Absent: %0.0f Days", absent);
          }
        }




    printf("\nDo you want to view attendance details[y/n]");
    scanf("%c", & dtls);
    system("cls");

    if (dtls == 'y') {
      FILE * temp2;
      temp2 = fopen("Attendance.txt", "r");
      while (fread( & s_att, sizeof(s_att), 1, temp2)) {
        if (strcmp(id, s_att.sid) == 0) {
          if (strcmp(p, s_att.ati) == 0) {

            gotoxy(50, y);
            printf("%s: Present\n", s_att.date);
          } else if (strcmp(a, s_att.ati) == 0) {

            gotoxy(50, y);
            printf("%s: Absent\n", s_att.date);

          }
          y++;
        }

      }
      fclose(temp2);
    }

    fclose(ssatt);
  }

    //EXIT_Switch

    char end;

    printf("\n\n\t\t\tPress 1 To Search Again\n");
    printf("\n\n\t\t\tPress 2 for go Back\n");
    printf("\n\n\t\t\tPress 3 for EXIT Software\n");
    printf("\n\n\t\t\tSelect an Option:");

    end = getche();

    switch (end) {
    case '1':
        search_student_attendance();
        break;
    case '2':
        home();
        break;
    case '3':
        ext();
        break;
    default:
    printf("INVALID KEYWORD");
    Sleep(1000);
    home();
  }

  return ;
}
void view_student_att(void) {
    system("cls");
    student std;
    printf("\n\t  ALL STUDENTS\n\n");
    FILE * fptr_att;
    fptr_att = fopen("Student info.txt", "r");
    while (fread( & std, sizeof(std), 1, fptr_att)) {

    printf("\n\t  NAME: %s\n\t  ID: %s\n", std.name, std.id, std.section);
    }
    fclose(fptr_att);
    return ;
}
COORD coord = {
  0,
  0
};
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
