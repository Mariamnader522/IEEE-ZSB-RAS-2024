#include <stdio.h>
struct test
{
    int id;
    char name[30];
    char class_id;
};


int main() {
    
    struct test example1 ;
    printf("the size before is:%d\n",sizeof(example1));

    return 0;
}