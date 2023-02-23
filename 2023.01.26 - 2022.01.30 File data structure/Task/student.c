#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>


struct Course {
    char courseName[20];
    int grades[5];
};

struct Student {
    char name[20];
    char group[20];
    int amount;
    struct Course *courses;
};

void rFillStudent(struct Student *student) {
    char *names[] = {"Sofiia", "Sophie", "Igor", "Dima", "Kostya"};
    char *groups[] = {"CS-21-1", "PZ-20-2", "TB-19-2"};
    char *courses[] = {"Math", "English", "Programming", "Literature", "Philosophy"};
    
    strcpy(student->name, names[rand() % 5]);                       //name
    strcpy(student->group, groups[rand() % 3]);                     //group
    
    student->amount = 1 + rand() % 3;                           //courses.amount
    student->courses = (struct Course*)calloc(sizeof(struct Course), student->amount);
    for (int i = 0; i < student->amount; i++) {                   
        strcpy(student->courses[i].courseName, courses[rand() % 5]);
        for (int j = 0; j < 5; j++) 
            student->courses[i].grades[j] = rand() % 12;
    }
}

void printStudent(struct Student *student) {
    printf("name: %s \n  group: %s\n  amount of courses:%d\n  Grades: ", student->name, student->group, student->amount);
    for (int i = 0; i < student->amount; i++) {
        printf("\n    %s:", student->courses[i].courseName);
        for (int j = 0; j < 5; j++) 
            printf("%d ", student->courses[j].grades[j]);
    }
}


void writeStudents(struct Student *student, int len) {
    FILE *file = fopen("data.txt", "wt");
    if (file) {
        for (int n = 0; n < len; n++) {
            fprintf(file, "%s %s %d ", student[n].name, student[n].group, student[n].amount);
            for (int i = 0; i < student[n].amount; i++) {
                fprintf(file, "%s ", student[n].courses[i].courseName);
                for (int j = 0; j < 5; j++) 
                    fprintf(file, "%d ", student[n].courses[i].grades[j]);
            }
        }
        fclose(file);
    }
}


void readStudent(struct Student *student, int len) {
    FILE *file = fopen("data.txt", "rb");
    if (file) {
        for (int n = 0; n < len; n++) {
            fscanf(file, "%s%s%d", student[n].name, student[n].group, &student[n].amount);
            student[n].courses = (struct Course*)calloc(sizeof(struct Course), student[n].amount);
            for (int i = 0; i < student[n].amount; i++) {
                fscanf(file, "%s", student[n].courses[i].courseName);
                for (int j = 0; j < 5; j++) 
                    fscanf(file, "%d", &student[n].courses[i].grades[j]);
            }
        }
        fclose(file);
    }
}

int main() {
    srand(time(NULL));
    int len = 5;
    struct Student *studentin = (struct Student*)calloc(sizeof(struct Student), len);
    struct Student *rstud = (struct Student*)calloc(sizeof(struct Student), len);

    // fill students
    for (int i = 0; i < len; i++) 
        rFillStudent(&studentin[i]);

    // write to file 
    writeStudents(studentin, len);
    // read from file 
    readStudent(rstud, len);

    // print students after read 
    for (int i = 0; i < len; i++) {
        printStudent(&rstud[i]);
        //printStudent(&studentin[i]);
        printf("\n");
    }
    return 0;
}

