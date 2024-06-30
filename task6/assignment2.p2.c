#include <stdio.h>
#include <string.h>

#define stop "!!"

int main() {
    char input[100];
    char unique[100];
    int flag = 0;

    while (flag == 0) {
        int x = 0;
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  
        if (strcmp(input, stop) == 0) {
            flag = 1;
            break;
        }

        for (int i = 0; i < strlen(input); i++) {
            int uniquee = 0;
            for (int j = 0; j < x; j++) {
                if (input[i] == unique[j]) {
                    uniquee = 1;
                    break;
                }
            }
            if (!uniquee) {
                unique[x++] = input[i];
            }
        }
        unique[x] = '\0';  
        printf("Unique characters are: %s\n", unique);
    }

    return 0;
}