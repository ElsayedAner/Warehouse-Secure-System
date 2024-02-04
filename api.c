#include <stdio.h>
#include <stdlib.h>
// custom header files.
#include "api.h"
#include "fun.h"

#define LENGTH_1 50
#define LENGTH_2 100

// shared variables.
extern char entered_user[];
extern char entered_pass[];
extern int user_check;
extern int clients_c;
extern char f_cont[LENGTH_1][LENGTH_2];

struct name{
    char first[10];
    char last[10];
};
struct items{
    char name[30];
    char q[4];
};
struct client{
    int num;
    struct name c_name;
    char age[3];
    char phone[15];
    struct items c_items;
};
struct client s_client, clean_client;
FILE *fptr;

/*****************************************************************************
 * clear_c: clear the command.                                               *
 *                                                                           *
 *****************************************************************************/
void clear_c (void)
{
    system("cls");
    printf("\n\t\t==> Safe system <==\n");
    printf("    ------------------------------------------\n\n\n");
}

/*****************************************************************************
 * add_client: add client data to data base system                           *
 *             return 0 for data ignored.                                    *
 *             return 1 for data added successfully.                         *
 *             return 2 for function error.                                  *
 *****************************************************************************/
int add_client (void)
{
    char c;
    printf("\n");
    printf("   new client...\n");
    printf("   ------------------------------------------\n");
    printf("-> Enter client first name>Elsayed(cancel)> ");
    scanf(" %[^\n]%*c", s_client.c_name.first);
    CHECK(s_client.c_name.first)
    printf("-> Enter client last name>Elsayed(cancel)> ");
    scanf(" %[^\n]%*c", s_client.c_name.last);
    CHECK(s_client.c_name.last)
    printf("-> Enter client age>Elsayed(cancel)> ");
    scanf(" %[^\n]%*c", s_client.age);
    CHECK(s_client.age)
    printf("-> Enter client phone number>Elsayed(cancel)> ");
    scanf(" %[^\n]%*c", s_client.phone);
    CHECK(s_client.phone)
    printf("-> Enter client item name>Elsayed(cancel)> ");
    scanf(" %[^\n]%*c", s_client.c_items.name);
    CHECK(s_client.c_items.name)
    printf("-> Enter client item quantity>Elsayed(cancel)> ");
    scanf(" %[^\n]%*c", s_client.c_items.q);
    CHECK(s_client.c_items.q)
    printf("\n");
    // print entered client data.
    printf("   __________________________________________________________________________\n");
    printf("   |%-4s|%-10s|%-10s|%-4s|%-13s|%-20s|%-3s |\n", "###", "First","Last", "Age", "Phone", "item", "Qty.");
    printf("   |----|----------|----------|----|-------------|--------------------|-----|\n");
    printf("   |%-4s|%-10s|%-10s|%-4s|%-13s|%-20s|%-4s |\n", "###", s_client.c_name.first, \
           s_client.c_name.last, s_client.age, s_client.phone, s_client.c_items.name, s_client.c_items.q);
    printf("   |----|----------|----------|----|-------------|--------------------|-----|\n");
	// choosing to save data or not?.
    printf("\n-> save client data(Y/N): ");
    scanf(" %c", &c);
    // ignore client data.
    if (c == 'n' || c == 'N')
    {
        B:
        s_client = clean_client;
        printf("   client data ignored.\n\n");
        return 0;
    }
    // save client data.
    else if (c == 'y' || c == 'Y')
    {
        if(f_read("data/safe.txt", 0))
        {
            fptr = fopen("data/safe_tmp.txt", "w");
            if(fptr == NULL)
            {
                // File not created hence exit.
                printf("   Unable to create file.\n");
                return 0;
            }
            else
            {
                // Write data to file.
                fprintf(fptr, "%s %s %s %s %s %s", s_client.c_name.first, s_client.c_name.last, \
                         s_client.age, s_client.phone, s_client.c_items.name, s_client.c_items.q);
                // Close file to save file data.
                fclose(fptr);
                if(f_read("data/safe_tmp.txt", (clients_c+1)))
                    {
                       for (int i = clients_c; i >= 0; i--)
                       {
                            ;
                       }

                    }
                    else
                    {
                        return 0;
                    }

                fclose(fptr);
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    return 2;
}

/*****************************************************************************
 * delete_client:                                                            *
 *                                                                           *
 *****************************************************************************/
void delete_client (void)
{

}

/*****************************************************************************
 * show_d:                                                                   *
 *                                                                           *
 *****************************************************************************/
void show_d (void)
{

}

/*****************************************************************************
 * list_d:                                                                   *
 *                                                                           *
 *****************************************************************************/
int list_d (void)
{
    if(f_read("data/safe.txt", 0))
    {
        for(int j = 0; j <= LENGTH_2; j++)
        {
            for(int i = 0; i <= LENGTH_1; i++)
            {
                f_cont[i][j] = 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
 * logout:                                                                   *
 *                                                                           *
 *****************************************************************************/
void logout (void)
{
    for(int i=0; i<=10; i++)
    {
        entered_user[i] = '\0';
        entered_pass[i] = '\0';
    }
    user_check = 0;
	printf("   user logout...\n\n");
}