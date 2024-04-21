#include <stdio.h>
struct student_info
{
    int roll_num;
    char name[30];
    int age;
    char address[100];
    float marks;
};

int main()
{
    struct student_info students[15];
    printf("Enter the informations \n");
    for (int i = 0; i < 15; i++)
    {
        printf("\nStudent number : %d\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &students[i].roll_num);
        fflush(stdin);// to clear the input buffer after reading each value

        printf("Name: ");
        scanf("%s", students[i].name);
        fflush(stdin);

        printf("Age: ");
        scanf("%d", &students[i].age);
        fflush(stdin);

        printf("Address: ");
        scanf("%s", students[i].address);
        fflush(stdin);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        fflush(stdin);
    }
    for (int i = 0; i < 15; i++)
    {
        printf("\nStudent number : %d\n", i + 1);
        printf("Roll number: %d\n", students[i].roll_num);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
        printf("Marks: %.3f\n", students[i].marks);
    }

    return 0;
}