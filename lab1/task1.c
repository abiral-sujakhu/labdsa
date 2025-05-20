#include <stdio.h>
#include <string.h>
#include <time.h>

// Define structure
struct Student {
    char name[50];
    int rollNo;
    int dob_year;
    int marks[5];
    int age;
    float average;
    float percentage;
};

// Function to greet the user
void greet() {
    printf("Welcome to the DSA Lab Program!\n\n");
}

// Function to take input from user
void getInfo(struct Student *s) {
    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);
    
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);
    
    printf("Enter Year of Birth (e.g. 2004): ");
    scanf("%d", &s->dob_year);
    
    printf("Enter marks of 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("  Subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}

// Function to calculate age from year of birth
int calculateAge(int dob_year) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900 - dob_year;
}

// Function to calculate average marks
float calculateAverage(int marks[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return (float)sum / size;
}

// Function to calculate percentage (same as average in this case)
float calculatePercent(float average) {
    return average;
}

// Function to display the result
void displayResult(struct Student s) {
    printf("\n--- Student Report ---\n");
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.rollNo);
    printf("Age: %d\n", s.age);
    
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", s.marks[i]);
    }
    printf("\nAverage Marks: %.2f\n", s.average);
    printf("Percentage: %.2f%%\n", s.percentage);
}

// Main function
int main() {
    struct Student s;

    greet();                     // 1. Greet the user
    getInfo(&s);                 // 2. Take input from user
    s.age = calculateAge(s.dob_year);                 // 3. Calculate age
    s.average = calculateAverage(s.marks, 5);         // 4. Calculate average marks
    s.percentage = calculatePercent(s.average);       // 5. Calculate percentage
    displayResult(s);           // 6. Display result

    return 0;
}
