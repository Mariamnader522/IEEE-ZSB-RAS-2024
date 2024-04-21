#include <stdio.h>
struct student_info
{
    int roll_num;
    char name[30];
    int age;
    char address[100];
    float marks;
};
void print_students(struct student_info students[])
{
    int count = 0;
    for (int i = 0; i < 15; i++)
    {
        printf("\nStudent number:%d\n", i + 1);
        printf("Roll number: %d\n", students[i].roll_num);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Marks (Max 20): %.3f\n", students[i].marks);
        if (students[i].marks < 12.00)
        {
            count++;
        }
    }
    printf("Number of students with marks less than 12 is : %d\n", count);
}

int main()
{
    struct student_info students[15];
    printf("Enter the informations \n");
    for (int i = 0; i < 15; i++)
    {
        printf("\nStudent number:%d\n", i + 1);
        printf("Roll number : ");
        scanf("%d", &students[i].roll_num);
        fflush(stdin); // to clear the input buffer after reading each value

        printf("Name : ");
        scanf("%s", students[i].name);
        fflush(stdin);

        printf("Age : ");
        scanf("%d", &students[i].age);
        fflush(stdin);

        printf("Address : ");
        scanf("%s", students[i].address);
        fflush(stdin);

        printf("Marks (Max 20): ");
        scanf("%f", &students[i].marks);
        fflush(stdin);
    }
    print_students(students);

    return 0;
}