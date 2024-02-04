#ifndef FUN_H
#define FUN_H

#define CHECK_U(elemint) if (str_cmp("cancel\n", elemint)) \
                            return user_check;             \
                         else                               \
                            ;

/*****************************************************************************
 * str_cmp: compare user string to system command.                           *
 *             return 0   unrecognized command.                              *
 *             return 1   recognized command.                                *
 *****************************************************************************/
 int str_cmp (char *comd, char *u_comd);

/*****************************************************************************
 * assess: return list: 0-> not recognized command.                          *
 *                      c-> clear(cls).                                      *
 *                      n-> new client(n|N).                                 *
 *                      x-> exit(exit|EXIT).                                 *
 *                      l-> list(lst).                                       *
 *                      h-> help(h|H).                                       *
 *****************************************************************************/
int assess (char *c);

/*****************************************************************************
 * scan_f:                                                                   *
 *                                                                           *
 *****************************************************************************/
int scan_f (char *c);

/*****************************************************************************
 * check_user: checking credential, username & password.                     *
 *             return user_check;                                            *
 *****************************************************************************/
 int check_user (void);

/*****************************************************************************
 * f_read: read file content.                                                *
 *             return client_c;                                              *
 *****************************************************************************/
 int f_read (char path[], int j);




#endif // FUN_H