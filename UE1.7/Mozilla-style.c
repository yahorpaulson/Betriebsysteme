#include <stdlib.h>

int
main(int argc, char const* argv[])
{
  unsigned short int buff[8]; // 2 bytes

  unsigned short int buffSize = sizeof(buff) / sizeof(buff[0]);

  buff[0] = 0;
  buff[1] = 1;

  for (int i = 2; i < buffSize; i++) {
    buff[i] = buff[i - 1] + buff[i - 2];
  }

  for (int j = 0; j < buffSize; j++) {
    printf("%hu ", buff[j]);
  }

  srand(time(NULL));
  unsigned short int index = (rand() % 7);

  printf("\n");

  printArray(buff, index, buffSize);

  getch();
  return 0;
}

void
printArray(unsigned short int* arr[],
           unsigned short int* index,
           unsigned short int* arrLng)
{

  for (int i = 0; i < arrLng; i++) {
    if (i <= index) {
      printf("%hu ", arr[i]);
    }
  }
}
