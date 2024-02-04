#include <stdio.h>
#include <stdlib.h>

#include "api.h"
#include "fun.h"

#define COM_LEN 10 /** maximum command length.**/

extern int user_check;
extern int clients_c;

int main()
{
    char p_command[COM_LEN+1];
    unsigned short int k;
    system("color a");
    clear_c();
    A:
    printf("-> Enter command(help): ");
    // in case of logged in.
    if (user_check == 1)
    {
        printf("\b\b>Elsayed> ");
    }
    k = scan_f(p_command);
    while (1){
        switch (k){

        // wrong command.
        case 0:
            goto A;

        // clear command (cls).
        case 'c':
            clear_c();
            goto A;

        // new client (n|N).
        case 'n':
            check_user();
            if(user_check)
            {
                add_client();
            }
            printf("\n");
            goto A;

        // delete client (d|D).
        case 'd':
            check_user();
            while(user_check)
            {

            }
            break;

        // list all client (lst).
        case 'l':
            check_user();
            if(user_check)
            {
                if(list_d())
                {
                    goto A;
                }
                else
                {
                    return 1;
                }
            }
            break;

        // exit command (exit).
        case 'x':
            return 0xff;

        // list all command (h|H).
        case 'h':
            printf("   -----------------------------------------\n");
            printf("   %-10s -->clear command window\n", "cls");
            printf("   %-10s -->list all registered clients\n", "lst");
            printf("   %-10s -->add new client\n", "nc");
            printf("   %-10s -->delete a client\n", "dc");
            printf("   %-10s -->return to main command\n", "cancel");
            printf("   %-10s -->exit program\n", "exit");
            printf("   %-10s -->list system commands\n", "help");
            printf("   -----------------------------------------\n\n");
            goto A;

        case 'o':
            logout();
            goto A;

        default:
            return 0x01;
        }
    }
    return 0;
}