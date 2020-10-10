#ifndef __INTERFACING_H__
#define __INTERFACING_H__
#include "system.h"
/* get data & commands functions */
void  Get_All_Data (char *name, char *password, int* ID, int *year) ;
void  Get_ID (int *id) ;
void  Get_Password (char *password,char *mode) ;
void  Get_Name (char *name) ;
void  Get_Year (int *year ) ;
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
