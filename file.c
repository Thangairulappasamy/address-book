#include <stdio.h>
#include "file.h"

#define FILE_NAME "contacts.txt"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp = fopen(FILE_NAME, "w");

    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE!!\n");
        return;
    }

    fprintf(fp, "#%d\n", addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL)
    {
        printf("No file found, starting fresh\n");
        addressBook->contactCount = 0;
        return;
    }

    fscanf(fp, "#%d\n", &addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fp, "%49[^,],%14[^,],%49s\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    fclose(fp);
}
