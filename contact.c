#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
int array[100];
void listContacts(AddressBook *addressBook) 
{
    if(addressBook->contactCount == 0)
    {
        printf("\nNo Contacts Available!\n");
        return;
    }

    printf("\n===============================================================\n");
    printf("| %-5s | %-20s | %-12s | %-25s |\n",
           "No", "Name", "Phone", "Email");
    printf("===============================================================\n");

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        
        printf("| %-5d | %-20s | %-12s | %-25s |\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("===============================================================\n");
}
    // Sort contacts based on the chosen criteria
    


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    char getname[20];char getphone[15];char gmail[50];
    int x=0;
    x+=check(getname);
    x+=checkphone(getphone);
    x+=checkgmail(gmail);
    if(x==3)
    {
        int i=addressBook->contactCount;
        strcpy(addressBook->contacts[i].name,getname);
        strcpy(addressBook->contacts[i].phone,getphone);
        strcpy(addressBook->contacts[i].email,gmail);
        addressBook->contactCount++;
        printf(":::contact saved:::");

    }


    
	/* Define the logic to create a Contacts */

}


void searchContact(AddressBook *addressBook) 
{
    int choice, found = 0;
    char search[50];

    printf("\n--- Search Contact ---\n");
    printf("1. Search by Name\n");
    printf("2. Search by Phone\n");
    printf("3. Search by Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

  //  printf("Enter search value: ");
   // scanf("%[^\n]", search);

    /* Validation */
    if(choice == 1 && !check(search))
    {
        printf("Invalid Name!\n");
        return;
    }

    if(choice == 2 && !checkphone(search))
    {
        printf("Invalid Phone Number!\n");
        return;
    }

    if(choice == 3 && checkgmail(search))
    {
        printf("Invalid Email!\n");
        return;
    }

    printf("\nSearching...\n");

 printf("\n===============================================================\n");
    printf("| %-5s | %-20s | %-12s | %-25s |\n",
           "No", "Name", "Phone", "Email");
    printf("===============================================================\n");
    int j=0;
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        
        if((choice == 1 && strcasecmp(addressBook->contacts[i].name, search) == 0) ||
           (choice == 2 && strcmp(addressBook->contacts[i].phone, search) == 0) ||
           (choice == 3 && strcmp(addressBook->contacts[i].email, search) == 0))
        {
            //printf("\nContact Found:\n");
            /*printf("Name  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);*/
            array[j]=i;
             printf("| %-5d | %-20s | %-12s | %-25s |\n",
               j + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
            found = 1;
            j++;
           // break;   // Fast stop after found
        }
    }

    if(!found)
    {
        printf("Contact Not Found!\n");
    }
}
    /* Define the logic for search */


void editContact(AddressBook *addressBook)
{
    int choice, slNo;
    char temp[50];

    searchContact(addressBook);   // call search function

    printf("\nEnter Serial Number to Edit: ");
    scanf("%d", &slNo);

    if (slNo < 1 || slNo > addressBook->contactCount)
    {
        printf("Invalid Serial Number!\n");
        return;
    }

    printf("\n===== Edit Contact =====\n");
    printf("1. Edit Name\n");
    printf("2. Edit Phone Number\n");
    printf("3. Edit Gmail\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
           // printf("Enter New Name: ");
            //scanf(" %[^\n]", temp);

            if (check(temp))
            {
                strcpy(addressBook->contacts[array[slNo - 1]].name, temp);
                printf("Name Updated Successfully!\n");
            }
            else
            {
                printf("Invalid Name!\n");
            }
            break;

        case 2:
            //printf("Enter New Phone Number: ");
            //sscanf("%s", temp);

            if (checkphone(temp))
            {
                strcpy(addressBook->contacts[array[slNo - 1]].phone, temp);
                printf("Phone Number Updated Successfully!\n");
            }
            else
            {
                printf("Invalid Phone Number!\n");
            }
            break;

        case 3:
           // printf("Enter New Gmail: ");
            //scanf("%s", temp);

            if (checkgmail(temp))
            {
                strcpy(addressBook->contacts[array[slNo - 1]].email, temp);
                printf("Gmail Updated Successfully!\n");
            }
            else
            {
                printf("Invalid Gmail!\n");
            }
            break;

        case 4:
            printf("Exit from Edit Contact\n");
            return;

        default:
            printf("Invalid Choice!\n");
    }
}
    
	/* Define the logic for Editcontact */
    


void deleteContact(AddressBook *addressBook)
{
    {
    int serialNo, index = -1;

    printf("\n--- Delete Contact ---\n");

    
    searchContact(addressBook);

    
    printf("Enter Serial Number to Delete: ");
    scanf("%d", &serialNo);


    if(serialNo < 1 || serialNo > addressBook->contactCount)
    {
        printf("Invalid Serial Number!\n");
        return;
    }

    index = array[serialNo - 1];


    for(int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Step 5: Decrement contact count
    addressBook->contactCount--;

    printf("Contact Deleted Successfully!\n");
}
	/* Define the logic for deletecontact */
   
}
int name(char getname[])
{
    int size=strlen(getname);
    //rule:1 name numst be 4 character.
    if(size<4)
    {
        printf("Error : name must contain at least 4 characters\n");
        return 0;
    }
    // rule:2 name must be only alpha.
    for(int i=0;getname[i]!='\0';i++)
    {
        if(!isalpha(getname[i]))
        {
        return 0;
        }
    }
    return 1;

}
int check(char getname[])
{
    int attement=0;
    //inavalid name attement 3 time.
    for(attement = 1; attement <= 3; attement++)
{  
    printf("Enter the name: ");
    scanf(" %[^\n]",getname);
if(name(getname))
{
    return 1;
}
else
{
    printf("plese enter the only alpha:\n");
    printf("you attemt 3 time remining %d\n",3-attement);
}
// 3 time attement program is end.
 if(attement==3)
{
    printf("program is end");
    exit(1);
} 
}

}
int phone(char getphone[])
{
    int i=0;
    //rule 1: phone number only digits.
    while(getphone[i]!='\0')
    {
     if (!isdigit(getphone[i]))
     {
     return 0;
     }
     i++;
     }
     // rule 2 : first digit must be between 6 and 9.
     if(!(getphone[0]>='6'&&getphone[0]<='9'))
     {
        return 0;
     }
     int size=strlen(getphone);
     // rule 3.must contain exactly 10 digits.
     if(size!=10)
     {
        return 0;
     }
     return 1;
}
int checkphone(char getphone[])
{
    int attemt;
    // invalid phone number attement 3 time
    for(int attemt=1;attemt<=3;attemt++)
    {
        printf("enter the phone number: ");
        scanf(" %[^\n]",getphone);
    if(phone(getphone))
    {
        return 1;
    }
    else
    {
        printf("phone number is only digits:\n ");
        printf("you attement 3 remining %d\n",3-attemt);
    }
    // 3 time finished attement program is end.
if(attemt==3)
{
    printf("program is ent: ");
    exit(2);
}
}
}
int mail(char gmail[])
{
int i, atcount = 0, dotcount = 0;
    int atpos = -1, dotpos = -1;

    int len = strlen(gmail);

    // Rule 1 & 3: Count @
    for(int i = 0; i < len; i++)
    {
        if(gmail[i] == '@')
        {
            atcount++;
            atpos = i;
        }
        if(gmail[i] == '.')
        {
            dotcount++;
            dotpos = i;
        }
    }

    if(atcount == 0)
    {
        printf("Invalid: Missing @ symbol\n");
        return 0;
    }
    if(atcount > 1)
    {
        printf("Invalid: Multiple @ symbols\n");
        return 0;
    }

    // Rule 2
    if(dotcount == 0)
    {
        printf("Invalid: Missing . (dot)\n");
        return 0;
    }

    // Rule 4
    if(dotpos < atpos)
    {
        printf("Invalid: Dot must come after @\n");
        return 0;
    }

    // Rule 5
    if(dotpos == atpos + 1)
    {
        printf("Invalid: No character between @ and dot\n");
        return 0;
    }

    // Rule 6: check characters after final dot
    for(int i = dotpos + 1; i < len; i++)
    {
        if(!isalnum(gmail[i]))
        {
            printf("Invalid: Extra characters after domain\n");
            return 0;
        }
    }

    // Rule 7 & 8
    for(int i = 0; i < len; i++)
    {
        if(!(isalnum(gmail[i]) || gmail[i] == '@' || gmail[i] == '.'))
        {
            printf("Invalid: Contains invalid symbol\n");
            return 0;
        }
    }

    // Rule 8: domain check (after @)
    for(int i = atpos + 1; i < len; i++)
    {
        if(gmail[i] == '.') continue;

        if(!isalnum(gmail[i]))
        {
            printf("Invalid: Domain must contain only letters or digits\n");
            return 0;
        }
    }

   // printf("Valid Email ID\n");




    return 1;


}
int checkgmail(char gmail[])
{
     int attemt=0;
     for(int attemt=1;attemt<=3;attemt++)
     {
        printf("Enter the gmail: ");
        scanf(" %[^\n]",gmail);
        if(mail(gmail))
        {
            return 1;
        }
        else
        {
            printf("Enter the valid gmail: ");
            printf("your attemt is 3 remin %d",3-attemt);

        }
     } 
     if(attemt==3)
     {
       printf("program is end");
       exit(3);
     }   
}
