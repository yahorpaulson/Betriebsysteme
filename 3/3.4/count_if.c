#include <stdbool.h>
#include <stdio.h>

typedef bool(IntFunction)(int);

unsigned count_if(int array[], unsigned size, IntFunction func)
{
    int counter = 0;
    bool result;
    bool (*ptr)(int) = func;

    for (int i = 0; i < size; i++) {

        result = ptr(array[i]);
        if (result) {
            counter++;
        }
    }

    return counter;
}

bool isEven(int value)
{
    if (value % 2 == 0) {
        return true;
    } else
        return false;
}

bool isGreaterThanPrevious(int value)
{
    static int prev_Value = 0;
    if (prev_Value < value) {
        prev_Value = value;
        return true;
    } else {
        prev_Value = +value;
        return false;
    }
}

int main()
{

    int array[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    int array_length = sizeof(array) / sizeof(int);
    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    int counter_isEven = count_if(array, array_length, (IntFunction*)isEven);
    printf("%d\n", counter_isEven);
    int counter_greater_than_prevs = count_if(array, array_length, (IntFunction*)isGreaterThanPrevious);
    printf("%d\n", counter_greater_than_prevs);
}