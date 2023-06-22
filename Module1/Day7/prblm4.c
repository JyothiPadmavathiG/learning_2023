#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compareMarks(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;

    // Compare marks in descending order
    if (studentA->marks < studentB->marks)
        return 1;
    else if (studentA->marks > studentB->marks)
        return -1;
    else
        return 0;
}

void sortStudents(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compareMarks);
}

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    // Populate the array of structures with user input
    for (int i = 0; i < size; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &(students[i].rollno));
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
        printf("\n");
    }

    // Sort the array of structures based on marks
    sortStudents(students, size);

    // Display the sorted array of structures
    printf("\nSorted Student Details:\n");
    displayStudents(students, size);

    // Free dynamically allocated memory
    free(students);

    return 0;
}
