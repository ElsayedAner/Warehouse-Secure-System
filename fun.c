#include <stdio.h>
#include <stdlib.h>
// custom header files.
#include "fun.h"
// MACROS.
#define LENGTH_1 50
#define LENGTH_2 100
// shared variables.
extern FILE *fptr;

char user_1[] = "Elsayed\0";
char pass_1[] = "1234\0";
char entered_user[10];
char entered_pass[10];
int user_check = 0;
char f_cont[LENGTH_1][LENGTH_2];
int clients_c;


/*****************************************************************************
 * str_cmp: compare user string to system command.                           *
 *             return 0   unrecognized command.                              *
 *             return 1   recognized command.                                *
 *****************************************************************************/
 int str_cmp (char *comd, char *u_comd)
 {
	 int i = 0;
	 do{
		 if (u_comd[i] != comd[i])
			{
				return 0;
			}
			i++;
	 } while (u_comd[i] != '\0');
	 return 1;
 }


/*****************************************************************************
 * assess: return list: 0-> not recognized command.                          *
 *                      c-> clear(cls).                                      *
 *                      n-> new client(n|N).                                 *
 *                      x-> exit(exit|EXIT).                                 *
 *                      l-> list(lst).                                       *
 *                      h-> help(h|H).                                       *
 *****************************************************************************/
int assess (char *c)
{
    int i=0;
	char ch[10];
	do{
		ch[i] = c[i];
		// check for white space.
		if (c[i] == ' ')
		{
			return 0;
		}
		i++;
	} while(c[i-1] != '\0');

	// command vector.........
	// clear command.
	if (str_cmp(ch,"cls\0"))
		return 'c';
	// exit command.
	else if (str_cmp(ch, "exit\0"))
		return 'x';
	// new client command.
	else if (str_cmp(ch, "nc\0"))
		return 'n';
	// delete client command.
	else if (str_cmp(ch, "dc\0"))
		return 'd';
	// list all client command.
	else if (str_cmp(ch,"lst\0"))
		return 'l';
	// help, list all available command.
	else if (str_cmp(ch, "help\0"))
		return 'h';
	// logout command.
	else if (str_cmp(ch, "lout\0"))
		return 'o';
	else
	{
		printf("   \'%s\' is not recognized as an internal or external command!\n\n", c);
		return 0;
	}
    return 0xff;
}

/*****************************************************************************
 * scan_f:                                                                   *
 *                                                                           *
 *****************************************************************************/
int scan_f (char *c)
{
    scanf(" %[^\n]%*c", c);
    return assess(c);
}

/*****************************************************************************
 * check_user: checking credential, username & password.                     *
 *             return user_check;                                            *
 *****************************************************************************/
 int check_user (void)
 {
     if (user_check == 0)
     {
         printf("\n   ------------------------------------------\n");
         printf("   checking credential required...\n");
         A:
         printf("-> Enter username(cancel): ");
         scanf(" %[^\n]%*c", entered_user);
         CHECK_U(entered_user)
         printf("-> Enter password(cancel): ");
         scanf(" %[^\n]%*c", entered_pass);
         CHECK_U(entered_pass)
         for(int i = 0; entered_user[i] != '\0'; i++)
            {
                if (entered_user[i] != user_1[i])
                {
                    printf("   incorrect user name or password!\n\n");
                    goto A;
                }
            }
         for(int i = 0; entered_pass[i] != '\0'; i++)
            {
                if (entered_pass[i] != pass_1[i])
                {
                    printf("   incorrect user name or password!\n\n");
                    goto A;
                }
            }
         printf("   access granted...\n");
		 printf("   welcome Mr.%s\n\n", user_1);
		 user_check = 1;
     }
     else
         user_check = 1;
     return user_check;
 }

/*****************************************************************************
 * f_read: read file content.                                                *
 *             return client_c;                                              *
 *****************************************************************************/
 int f_read (char path[], int j)
 {
     fptr = fopen(path, "r");
     if(fptr == NULL)
        {
            printf("go\n");
            // File not open hence exit.
            printf("   Unable to open safe file.\n\n");
            return 0;
        }
     else
        {
            int i = j;
            while(!feof(fptr))
            {
                fgets(&f_cont[i][0],LENGTH_1, fptr);
                // set client total number.
                clients_c = i;
                i++;
            }
            fclose(fptr);
            return 1;
        }
 }


 /*****************************************************************************
 * print_f: read file content.                                                *
 *             return client_c;                                               *
 *****************************************************************************/
  /**
 int print_f (void)
 {
    // print entered client data.
    printf("   __________________________________________________________________________\n");
    printf("   |%-4s|%-10s|%-10s|%-4s|%-13s|%-20s|%-3s |\n", "###", "First","Last", "Age", "Phone", "item", "Qty.");
    printf("   |----|----------|----------|----|-------------|--------------------|-----|\n");
    printf("   |%-4s|%-10s|%-10s|%-4s|%-13s|%-20s|%-4s |\n", "###", s_client.c_name.first, \
           s_client.c_name.last, s_client.age, s_client.phone, s_client.c_items.name, s_client.c_items.q);
    printf("   |----|----------|----------|----|-------------|--------------------|-----|\n");
 }
**/