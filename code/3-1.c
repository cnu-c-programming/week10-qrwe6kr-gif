#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int score;
    struct Student* next;
} Student;
Student* head = NULL;

void addStudent(char* name, int score) {
    Student* newNode = (Student*)malloc(sizeof(Student));

    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Student* cur = head;

    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void deleteStudent(char* name) {
    Student* cur = head;
    Student* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }

            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void printStudents() {
    Student* cur = head;

    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void freeList() {
    Student* cur = head;

    while (cur != NULL) {
        Student* temp = cur;
        cur = cur->next;
        free(temp);
    }

    head = NULL;
}

int main() {
    char command[20];
    char name[50];
    int score;
  
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            addStudent(name, score);
        } 
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deleteStudent(name);
        } 
        else if (strcmp(command, "print") == 0) {
            printStudents();
        } 
        else if (strcmp(command, "quit") == 0) {
            freeList();
            break;
        }
    }
    return 0;
}
