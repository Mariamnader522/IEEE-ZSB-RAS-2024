#include <stdio.h>
#include <string.h>

struct student_info
{
    unsigned int roll_number : 4;
    unsigned int age : 8;
    unsigned int marks : 3;
    char address[100];
    char name[100];
};

void print_students(const struct student_info *student1)
{
    printf("Roll number: %u\n", student1->roll_number);
    printf("Age: %u\n", student1->age);
    printf("Marks: %u\n", student1->marks);
    printf("Address: %s\n", student1->address);
    printf("Name: %s\n", student1->name);
    printf("\n");
}

int main()
{
    struct student_info student1[15];

    printf("Enter the students information:\n");

    for (int i = 0; i < 15; ++i)
    {
        student1[i].roll_number = i + 1;
        student1[i].age = i + 20;
        student1[i].marks = i + 10;
        strcpy(student1[i].address, "address");
        strcpy(student1[i].name, "mariam");
    }

    for (int i = 0; i < 15; i++)
    {
        printf("Student: %d\n", i + 1);
        print_students(&student1[i]);
    }

    printf("Size of struct is %lu", sizeof(struct student_info));
    /*The processor will handle each member of the struct based on their respective sizes and alignments.*/

    return 0;
}