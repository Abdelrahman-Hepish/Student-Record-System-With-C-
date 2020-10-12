#ifndef __INTERFACING_H__
#define __INTERFACING_H__
#include "system.h"
#include "admin.h"
/* get data & commands functions */
void  Set_All_Data (char *name, char *password, int* ID, int *year , int *degree) ;
void  Set_ID (int *id) ;
void  Set_Password (char *password,char *mode) ;
void  Set_Name (char *name) ;
void  Set_Year (int *year ) ;
void  Set_Total_Degree (int *degree ) ;
/* presentation & git functions */
void  Welcome_Admin_Mode (char *password ) ;
void  Welcome_Student_Mode (char *password , int *id  ) ;
void  Correct_Log_in (char *mode) ;
void  Invalid_Log_in (char *mode) ;
void  Invalid_Choice (char *tchoice) ;
void  Init_Edit_Password_Process (char *tmode) ;
tedit_record  Init_Modify_Record (void) ;
/* just present */
void  Welcome_System (void ) ;
void  Present_Admin_Privileges (void ) ;
void  Present_Sutudent_Privileges (void ) ;
void  Make_Break (void ) ;
void  Init_Add_Record (void) ;
void  Init_Remove_Record (void) ;
void  Init_View_One_Record (void) ;
void  Init_View_All_Records (void) ;
#endif // __INTERFACING_H__
