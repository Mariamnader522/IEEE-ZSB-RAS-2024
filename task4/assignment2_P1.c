#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int compare(struct Date date1, struct Date date2) {
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year)
        return 0;
    else
        return 1;
}

int main() {
    struct Date date1, date2;

    printf("Enter the first date:\n");
    printf("Day: ");
    scanf("%d", &date1.day);

    printf("Month: ");
    scanf("%d", &date1.month);

    printf("Year: ");
    scanf("%d", &date1.year);

    printf("\nEnter the second date:\n");
    printf("Day: ");
    scanf("%d", &date2.day);

    printf("Month: ");
    scanf("%d", &date2.month);

    printf("Year: ");
    scanf("%d", &date2.year);

    if (compare(date1, date2) == 0)
        printf("Dates are equal");
    else
        printf("Dates are not equal");

    