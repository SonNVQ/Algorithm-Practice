#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 1001
int currentStudentNumber = 0;
int totalStudent = 0;

struct Student {
    char studentID[20];
    char fullName[50];
    char sex[10];
    float progressTestMark;
    float assignmentMark;
    float workshopMark;
    float practicalExamMark;
    float finalExamMark;
} students[MAX_STUDENT];

void ImportStudent() {
    struct Student student;
    printf("Please enter student information as follows:\n");
    printf("1.Student ID: ");
    scanf("%s", &student.studentID);
    printf("2.Full name: ");
    while ((getchar()) != '\n'); //fix gets() won't work after scanf()
    gets(student.fullName);
    printf("3.Sex: ");
    scanf("%s", &student.sex);
    printf("4.Progress Test Mark: ");
    scanf("%f", &student.progressTestMark);
    printf("5.Assignment Mark: ");
    scanf("%f", &student.assignmentMark);
    printf("6.Workshop Mark: ");
    scanf("%f", &student.workshopMark);
    printf("7.Practical Exam Mark: ");
    scanf("%f", &student.practicalExamMark);
    printf("8.Final Exam Mark: ");
    scanf("%f", &student.finalExamMark);
    students[++currentStudentNumber] = student;
    ++totalStudent;
    printf("Insertion Done!\n");
};

void ImportManyStudents(int N) {
    for (int i = 1; i <= N; ++i) {
        printf("\nStuden number %d\n", i);
        ImportStudent();
    }
}

void PrintAllStudents() {
    printf("Student list: \n");
    printf("ID      Full_Name               Sex     Progress_Test  Assignment  Workshop  Practical_Exam  Final_Exam\n");
    for (int i = 1; i <= currentStudentNumber; ++i) {
        if (!strlen(students[i].studentID)) continue;
        printf("%-8s%-24s%-6s  %13.1f  %10.1f  %8.1f  %14.1f  %10.1f\n",
               students[i].studentID,
               students[i].fullName,
               students[i].sex,
               students[i].progressTestMark,
               students[i].assignmentMark,
               students[i].workshopMark,
               students[i].practicalExamMark,
               students[i].finalExamMark);
    }
}

void PrintOneStudents(struct Student student) {
    printf("Student list: \n");
    printf("ID      Full_Name               Sex     Progress_Test  Assignment  Workshop  Practical_Exam  Final_Exam\n");
    printf("%-8s%-24s%-6s  %13.1f  %10.1f  %8.1f  %14.1f  %10.1f\n",
           student.studentID,
           student.fullName,
           student.sex,
           student.progressTestMark,
           student.assignmentMark,
           student.workshopMark,
           student.practicalExamMark,
           student.finalExamMark);
    printf("\n");
}

void DeleteAllStudents() {
    for (int i = 1; i <= currentStudentNumber; ++i) {
        students[i] = students[0];
    }
    printf("Successfully deteted all students\n");
}

void DeleteOneStudent(char *studentID) {
    for (int i = 1; i <= currentStudentNumber; ++i) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            students[i] = students[0];
            --totalStudent;
            printf("Successfully deteted student with ID %s\n", studentID);
            return;
        }
    }
    printf("Error: Can not find student with ID %s\n", studentID);
}

struct Student FindStudent(char *studentID) {
    for (int i = 1; i <= currentStudentNumber; ++i) {
        if (strcmp(students[i].studentID, studentID) == 0)
            return students[i];
    }
    return students[0];
}

float Result(struct Student student) {
    return 0.1 * student.progressTestMark
        + 0.1 * student.assignmentMark
        + 0.1 * student.workshopMark
        + 0.4 * student.practicalExamMark
        + 0.3 * student.finalExamMark;
}

char *StudentCheck(struct Student student) {
    if ((student.progressTestMark > 0 &&
        student.assignmentMark > 0 &&
        student.workshopMark > 0 &&
        student.practicalExamMark > 0 &&
        student.finalExamMark > 0) ||
        (student.finalExamMark >= 4 && Result(student) >= 5)) {
        return "complete";
    }
    return "incomplete";
}

void CheckAllStudent() {
    printf("ID      Full_Name               Sex     Result      \n");
    for (int i = 1; i <= totalStudent; ++i) {
        if (!strlen(students[i].studentID)) continue;
        printf("%-8\s%-24s%-6s  %-12s\n",
               students[i].studentID,
               students[i].fullName,
               students[i].sex,
               StudentCheck(students[i]));
    }
    printf("\n");
}

void ExportToFile() {
    FILE *text;
    text = fopen("Students.txt", "w");
    fprintf(text, "ID      Full_Name               Sex     Progress_Test  Assignment  Workshop  Practical_Exam  Final_Exam  Result      \n");
    for (int i = 1; i <= currentStudentNumber; ++i) {
        if (!strlen(students[i].studentID)) continue;
        fprintf(text, "%-8s%-24s%-6s  %13.1f  %10.1f  %8.1f  %14.1f  %10.1f  %-12s\n",
               students[i].studentID,
               students[i].fullName,
               students[i].sex,
               students[i].progressTestMark,
               students[i].assignmentMark,
               students[i].workshopMark,
               students[i].practicalExamMark,
               students[i].finalExamMark,
               StudentCheck(students[i]));
    }
    fclose(text);
}

void MenuListPrint() {
    printf("Student Mark Management:\n");
    printf("[1] Import students\n");
    printf("[2] Print student list\n");
    printf("[3] Add a student\n");
    printf("[4] Delete all students\n");
    printf("[5] Check all student marks\n");
    printf("[6] Find a student\n");
    printf("[7] Delete a student\n");
    printf("[8] Export to file\n");
    printf("[9] Exit\n");
    printf("Please enter a number: ");
}

void Menu() {
    MenuListPrint();
    int selection = 0;
    scanf("%d", &selection);
    system("cls");
    switch (selection) {
        case 1: {
            int N;
            printf("How many students do you want to import?: ");
            scanf("%d", &N);
            if (N == 1) {
                ImportStudent();
            }
            else {
                ImportManyStudents(N);
            }
            break;
        }
        case 2: {
            PrintAllStudents();
            break;
        }
        case 3: {
            ImportStudent();
            break;
        }
        case 4: {
            DeleteAllStudents();
            break;
        }
        case 5: {
            CheckAllStudent();
            break;
        }
        case 6: {
            char studentID[10];
            printf("Enter student id: ");
            scanf("%s", &studentID);
            struct Student student = FindStudent(studentID);
            if (!strlen(student.studentID))
                printf("Can not find student with ID %s \n", studentID);
            else
                PrintOneStudents(student);
            break;
        }
        case 7: {
            char studentID[10];
            printf("Enter student id: ");
            scanf("%s", &studentID);
            DeleteOneStudent(studentID);
            break;
        }
        case 8: {
            ExportToFile();
            printf("Successfully exported to file 'Students.txt'\n");
            break;
        }
        default: {
            exit(0);
        }
    }
    printf("\n");
    Menu();
}

int main() {
    Menu();
    return 0;
}
