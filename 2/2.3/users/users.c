#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXCHARS (200 + 1) // we assume a line in the file has a maximum length of 200 characters + \0

int main(int argc, char* argv[])
{
    FILE* file = fopen("//wsl.localhost/Ubuntu/etc/passwd", "r"); // open file

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int bufferLength = MAXCHARS;
    char buffer[bufferLength];

    char* pch;

    while (fgets(buffer, bufferLength, file)) {
        pch = strtok(buffer, ":");

        char count = 0;
        while (pch != NULL) {

            switch (count) {
            case 0:
                printf("Username: \"%s\" ", pch);
                count++;
                break;
            case 2:
                printf("UserID: \"%s\"\n", pch);
                count++;
                break;

            default:
                count++;
                break;
            }

            pch = strtok(NULL, ":");
        }
    }

    fclose(file);

    return 0;
}
