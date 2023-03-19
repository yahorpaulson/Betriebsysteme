unsigned strlength(char* str)
{
    unsigned count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}