#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXCHARS (200 + 1) // we assume a line in the file has a maximum length of 200 characters + \0
#define MAXAMOUNT (25)

void array_lines(char** str);

int main(int argc, char* argv[])
{

    char** str;
    char line[MAXCHARS];

    int count = 0;
    char c;

    int buff[MAXAMOUNT];

    FILE* file = fopen("//wsl.localhost/Ubuntu/etc/passwd", "r"); // open file

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    str = (char**)malloc(MAXAMOUNT * sizeof(char*));

    int line_number = 0;
    while (fgets(line, MAXCHARS, file) != NULL && line_number < MAXAMOUNT) {

        char linelen = strcspn(line, "\n");

        str[line_number] = (char*)malloc(sizeof(char) * linelen);
        strncpy(str[line_number], line, linelen);

        line_number++;
    }

    array_lines(str);

    fclose(file);

    for (int i = 0; i < MAXAMOUNT; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}
void array_lines(char** str)
{
    for (int i = 0; i < MAXAMOUNT; i++) {
        if (str[i] != NULL) {
            unsigned short lengthline = strlen(str[i]);
            printf("%s %hu \n", str[i], lengthline);
        }
    }
}