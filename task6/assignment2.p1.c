#include <stdio.h>

int main() {
    int hours, minutes, seconds;
    int time;

    printf("Enter the time in [hh:mm:ss]: ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    time = hours * 10000 + minutes * 100 + seconds;

    printf("Time is: %02d:%02d:%02d\n", hours, minutes, seconds);
    printf("Time is: %06d\n", time);

    return 0;
}