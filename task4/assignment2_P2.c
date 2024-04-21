#include <stdio.h>
struct info
{
    char name[30];
    int age;
};


int main() {

    struct info object ;
    struct info *ptr;
    ptr = &object;
    strcpy(object.name,"Mariam Nader");
    object.age = 25;
    printf("Name: %s\n",ptr->name);
    printf("Age: %d\n", ptr->age);
    return 0;
}