
#include <stdio.h>
#include <string.h>

void student_data(void);
void save_std_details(void);
void view_std_details(void);
void del_std(void);


typedef struct student {
    char name[50];
    char id[50];
    char section[10];
    char batch[50];
    char major[50];
    char department[50];
}student;

void student_data(void)
{

    system("cls");
    char op_1;
    printf("\n\n\n\n\t\t\t\t\t\t===Student Data===\n\n\n");

    printf("\t\t\t\t\t ==> 1. Save Student Details\n");
    printf("\t\t\t\t\t ==> 2. View Student Details\n");
    printf("\t\t\t\t\t ==> 3. Delete Student\n");
    printf("\t\t\t\t\t ==> 4. Log Out\n");
    printf("\t\t\t\t\t ==> 5. Exit\n\n\n");

    printf("\t\t\t\t\t   Select an Option:");

    op_1 = getche();

    switch (op_1) {
    case '1':
        save_std_details();
        break;
    case '2':
        view_std_details();
        break;

    case '3':
        del_std();
        break;
    case '4':
        home();
        break;
     case '5':
        ext();
        break;
    default:
        printf("INVALID KEYWORD\n");
        Sleep(1000);
        student_data();
  }
    return ;

}
void save_std_details(void) {
    char op_2;
    student std;
    system("cls");

    printf("\n\t\t\t\t\t  ===SAVE STUDENT DETAILS===\n");
    FILE * fptr;
    fptr = fopen("Student info.txt", "a");
    if (fptr == NULL) {
        printf("Error");
        exit(1);
  }
    fflush(stdin);
    printf("\n   \tEnter Student Name: ");
    gets(std.name);
    printf("\n   \tEnter Student ID: ");
    gets(std.id);
    printf("\n   \tEnter Section: ");
    gets(std.section);
    printf("\n   \tEnter Student BATCH: ");
    gets(std.batch);
    printf("\n   \tEnter Department: ");
    gets(std.department);

    printf("\n   \tEnter Major: ");
    gets(std.major);



    fwrite( & std, sizeof(std), 1, fptr);
    printf("\n\n >> SAVE SUCCESSFUL <<\n");
    fclose(fptr);
    printf("\t\t\tSave more Student details[y/n] ");
    op_2 = getche();

    switch (op_2) {
    case 'y':
        save_std_details();
        break;
    case 'n':
        student_data();
        break;
    default:
        printf("\n\t\t\t\t  INVALID KEYWORD\n");
        Sleep(1000);
        student_data();

  }

    return ;
}
void view_std_details(void) {
    system("cls");
    student std;
    printf("\n\t\t\t\t  ALL STUDENTS INFORMATION\n\n");
    FILE *fptr1;
    fptr1 = fopen("Student info.txt", "r");
    if (fptr1 == NULL) {
        printf("Error");
        //exit(1);
    }
    while (fread(&std, sizeof(std), 1, fptr1)) {
        printf("\n\t\t\t  NAME: %s\n\t\t\t  ID: %s\n\t\t\t  Section: %s\n\t\t\t  Batch: %s\n\t\t\t  Department: %s\n\t\t\t  Major: %s\n", std.name, std.id, std.section, std.batch, std.department, std.major);
    }
    fclose(fptr1);

    //EXIT_Switch

    char op_1;
    printf("\n\n  Press 1 for View All Students Again\n");
    printf("  Press 2 for go to Back\n");
    printf("  Press 3 for EXIT Software\n");
    printf(" Select an Option:");

    scanf("%c", &op_1);
    //end = getche();

    switch (op_1) {
    case '1':
        view_std_details();
        break;
    case '2':
        student_data();
        break;
    case '3':
        ext();
        break;
    default:
        printf("\n  INVALID KEYWORD\n");
        sleep(1000);
        student_data();
    }

    return;
}
void del_std(void) {
    system("cls");
    printf("\n  Delete Student Information\n");
    FILE * fp1, * fp2;
        student std1;
    int found = 0;
    char id[50];

    // Open the input file for reading and the output file for writing
    fp1 = fopen("Student info.txt", "r");
    fp2 = fopen("Delete.txt", "w");
    fflush(stdin);
    printf("\n  Enter The Student ID You Want To Delete  ");
    gets(id);
    // Read records from input file and write non-matching records to the output file
    while (1) {
        fread( & std1, sizeof(std1), 1, fp1);
        if (feof(fp1)) {
        break;
    }
    if (strcmp(id, std1.id) == 0) {
        found = 1;
    } else {
      fwrite( & std1, sizeof(std1), 1, fp2);
    }
  }
    fclose(fp1);
    fclose(fp2);
    if (found == 0) {
        printf("\n\n  DATA NOT FOUND \n");
  } else {
        // Open the input file in write mode and the output file in read mode
        fp1 = fopen("Student info.txt", "w");
        fp2 = fopen("Delete.txt", "r");

        // Read records from the output file and write them back to the input file
    while (1) {
      fread( & std1, sizeof(std1), 1, fp2);
      if (feof(fp2)) {
        break;
      }
      fwrite( & std1, sizeof(std1), 1, fp1);
    }
    printf("\n\n  >> DELETE SUCCESSFUL <<  \n\n");
  }
    fclose(fp1);
    fclose(fp2);

  //EXIT_Switch
    char op_1;
    //printf("\n\n  Press 1 for Search again\n");
    printf("\n\n  Press 1 for Home Portal\n");
    printf("  Press 2 for EXIT Software\n");
    printf(" Select an Option:");

    scanf("%c", &op_1);
    system("cls");

    switch (op_1) {

    case '1':
        student_data();
        break;
    case '2':
        ext();
        break;
    default:
        printf("\n  INVALID KEYWORD\n");
        sleep(1000);
        student_data();
  }
    fflush(stdin);
    return ;
}

