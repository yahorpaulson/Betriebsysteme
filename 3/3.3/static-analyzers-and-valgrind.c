#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DO NOT CHANGE this struct !!
//
typedef struct
{
    char* name;
    char owner[7];
    char hasOwner;
} Pet;

// DO NOT CHANGE the function signature !!
//
Pet* createPet(const char* name, const char* owner)
{
    Pet* petPtr = NULL;

    petPtr = (Pet*)malloc(sizeof(Pet));
    petPtr->name = (char*)malloc(sizeof(char) * strlen(name));

    strcpy(petPtr->name, name);
    strcpy(petPtr->owner, owner);
    petPtr->hasOwner = strlen(owner) ? 'X' : '-';

    return petPtr;
}

int main()
{
    const char buddy[] = "Buddy";
    const char kitty[] = "Kitty";
    const char bella[] = "Bella";

    Pet* dog1 = createPet(buddy, "Brian Kernighan");
    Pet* cat1 = createPet(kitty, "Dennis Ritchie");

    Pet* dog2 = (Pet*)malloc(sizeof(Pet));
    *dog2 = *dog1;
    strncpy(dog2->name, bella, strlen(bella) + 1);

    printf("%s belongs to %.*s %c\n", dog1->name, 7, dog1->owner, dog1->hasOwner);
    printf("%s belongs to %.*s %c\n", cat1->name, 7, cat1->owner, cat1->hasOwner);
    printf("%s belongs to %.*s %c\n", dog2->name, 7, dog2->owner, dog2->hasOwner);

    free(dog2);
    free(dog1->name);
    free(dog1);
    free(cat1->name);
    free(cat1);

    return 0;
}