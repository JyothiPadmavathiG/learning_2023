#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n, i;
    struct Student* students;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory dynamically for n students
    students = (struct Student*)malloc(n * sizeof(struct Student));

    // Input data for each student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        
        printf("Name: ");
        scanf("%s", students[i].name);
        
        printf("Age: ");
        scanf("%d", &(students[i].age));
        
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }

    // Display data for each student
    printf("\nStudent Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
