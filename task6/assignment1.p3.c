#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char max_freq(char str[]) {
    int count[256] = {0};
    int length = strlen(str);
    for (int i = 0; i < length; i++)
        count[(int)str[i]]++;

    char max;
    int max_char = 0;
    for (int i = 0; i < length; i++) {
        if (count[(int)str[i]] > max_char) {
            max_char = count[(int)str[i]];
            max = str[i];
        }
    }

    printf("The frequency of the most repeated character is: %d\n", max_char);

    return max;
}

int main() {
    int length;
    printf("Enter the max length for the name: ");
    scanf("%d", &length);
    getchar(); 

    char name[length+1];
    printf("Enter the name: ");
    fgets(name, length+1, stdin);
    name[strcspn(name, "\n")] = '\0'; 

    printf("Name entered: %s\n", name);
    char repeated_char = max_freq(name);
    printf("Most repeated character: %c", repeated_char);

    return 0;
}