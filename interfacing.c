#include "interfacing.h"
#include <stdio.h>
void  Welcome_System (void )
{
    printf("Hello sir,\n"
           "Choosing mode process.\n"
           "Enter 0 for admin mode and 1 for student mode\n");
}
void  Welcome_Admin_Mode (char *password )
{
    printf("You are in Admin Mode \n" );
    Set_Password(password , "Admin") ;

}
void  Welcome_Student_Mode (char *password , int *id  )
{
    printf("You are in Student Mode \n");
    Set_ID(id) ;
    Set_Password(password, "Student") ;
}
void  Invalid_Log_in (char *mode)
{
    printf("Invalid Log in to %s mode :( \n",mode);
}
void  Correct_Log_in (char *mode)
{
    printf("Correct log in to %s mode \n",mode);
}
void  Invalid_Choice (char *tchoice)
{
    printf("Invalid %s choice :( \n",tchoice) ;
}
void  Set_All_Data (char *name, char *password, int *ID, int *year , int *degree)
{
    Set_Name (name) ;
    Set_Password ( password , "Student") ;
    Set_ID (ID) ;
    Set_Year(year) ;
    Set_Total_Degree(degree) ;
}
void  Set_Total_Degree (int *degree )
{
    printf("Enter student degree \n") ;
    scanf("%d",degree) ;
}
void  Set_ID (int *id)
{
    printf("Enter student id \n") ;
    scanf("%d",id) ;
}
void  Set_Name (char *name)
{
    printf("Enter Student Name \n") ;
    scanf("%s",name) ;
}
void  Set_Password (char *password,char *mode)
{
    printf("Enter %s password \n",mode) ;
    scanf("%s",password) ;
}
void Set_Year (int *year )
{
    printf("Enter student year \n") ;
    scanf("%d",year) ;
}
void  Init_Add_Record (void)
{
    printf("Adding new record process \n"
           "****************************\n");
}
void  Init_Remove_Record (void)
{
    printf("Removing new record process \n"
           "****************************\n");
}
tedit_record  Init_Modify_Record (void)
{
    tedit_record choice = modify_total_degree ;
    printf("Modifying record process \n"
           "****************************\n"
           "Choosing specified data to change \n"
           " Enter 0 to modify name            , 1 to modify password          \n"
           "       2 to modify year            , 3 to modify total degree      \n");
    scanf("%d",&choice) ;
    return choice ;
}
void  Init_View_One_Record (void)
{
    printf("Viewing -one- record process \n"
           "****************************\n");
}
void  Init_View_All_Records (void)
{
    printf("Viewing All records process \n"
           "****************************\n");
}
void  Init_Edit_Password_Process (char *tmode)
{
    printf("Editing %s Password process \n"
           "****************************\n",tmode);
}
void  Present_Admin_Privileges (void )
{
    printf("welcome in admin mode \n"
           "Choosing operation\n"
           " Enter 0 to add student record  , 1 to remove student record \n"
           "       2 to edit student record , 3 to view student record   \n"
           "       4 to view all records    , 5 to edit admin password  \n") ;
}
void  Present_Sutudent_Privileges (void )
{
    printf("welcome in student mode \n"
           "Choosing operation\n"
           " Enter 0 to view your record   , 1 to edit your password \n") ;
}
void  Make_Break (void )
{
    printf("*************************************************************************************\n") ;
}
tcompletion Ask_For_Resumption (char *message )
{
    tcompletion completion ;
    printf("To resume %s\n"
           "Enter : 1 \n"
           "To end %s"
           "Enter : 0\n",message,message) ;
    scanf("%d",&completion) ;
    return completion ;
}
void  Detect_Failure(char *failure)
{
    printf("Failure in %s\n",failure) ;
}