#include <stdio.h>
#include "system.h"
#include "user-admin.h"
/* get data & commands functions */
static void  Get_All_Data (char *name, char *password, int* ID, int *year) ;
static void  Get_ID (int *id) ;
static void  Get_Password (char *password,char *mode) ;
static void  Get_Name (char *name) ;
static void Get_Year (int *year ) ;
/* presentation & git functions */
static void  Welcome_Admin_Mode (char *password ) ;
static void  Welcome_Student_Mode (char *password , int *id  ) ;
static void  Correct_Log_in (char *mode) ;
static void  Invalid_Log_in (char *mode) ;
static void  Invalid_Choice (char *tchoice) ;
static void  Init_Edit_Password_Process (char *tmode) ;
static tedit_record  Init_Modify_Record (void) ;
/* just present */
static void  Welcome_System (void ) ;
static void  Present_Admin_Privileges (void ) ;
static void  Present_Sutudent_Privileges (void ) ;
static void  Make_Break (void ) ;
static void  Init_Add_Record (void) ;
static void  Init_Remove_Record (void) ;
static void  Init_View_One_Record (void) ;
static void  Init_View_All_Records (void) ;



tmode Init_System (int *id ) {
    user_admin_init();
    tmode mode = admin;
    char password[MAX_STR_LEN] = "\0";
    Welcome_System () ;
    scanf("%d", &mode);
    switch (mode) {
        case admin :
            Welcome_Admin_Mode (password) ;
            if (check_admin_password(password)) {
                Correct_Log_in("admin") ;
                return admin;
            } else {
                Invalid_Log_in ("admin") ;
            }
            break;
        case student :
            Welcome_Student_Mode (password , id ) ;
            if (check_student_ID_password(password, *id)) {
                Correct_Log_in ("student") ;
                return student;
            } else {
                Invalid_Log_in ("admin") ;
            }
            break;
        default:
            Invalid_Choice ("mode") ;
    }
}
void Admin_System (void )
{  /* initialization */
    tprivileges_admin admin_process = view_all ;
    char name     [MAX_STR_LEN] = "\0" ;
    char password [MAX_STR_LEN] = "\0" ;
    int id = 0 ;
    int year = 0 ;
    tcompletion completion = Resume ;
    do {
        Make_Break () ;
        Present_Admin_Privileges ( ) ;
        scanf("%d",&admin_process) ;
        switch (admin_process) {
            case add_record :
                Init_Add_Record() ;
                Get_All_Data (name, password, &id, &year) ;
                add_student( name, password, id, year) ;
                break;
            case remove_record :
                Init_Remove_Record () ;
                Get_ID(&id) ;
                remove_student(id);
                break;
            case edit_record :
                switch (Init_Modify_Record () ) {
                    case modify_name_password_year :
                        Get_ID (&id) ;
                        Get_Name (name) ;
                        Get_Password (password,"student") ;
                        Get_Year(&year);
                        modify_student_name(id, name) ;
                        modify_student_password(id, password);
                        modify_student_year(id, year);
                        break;
                    case modify_name :
                        Get_ID (&id) ;
                        Get_Name (name) ;
                        modify_student_name(id, name) ;
                        break;
                    case modify_password :
                        Get_ID (&id) ;
                        Get_Password (password,"student") ;
                        modify_student_password(id, password);
                        break;
                    case  modify_year :
                        Get_ID (&id) ;
                        Get_Year(&year);
                        modify_student_year(id, year);
                        break;
                    case modify_name_password :
                        Get_ID (&id) ;
                        Get_Name (name) ;
                        Get_Password (password,"student") ;
                        modify_student_name(id, name) ;
                        modify_student_password(id, password);
                        break;
                    case  modify_name_year :
                        Get_ID (&id) ;
                        Get_Name (name) ;
                        Get_Year(&year);
                        modify_student_name(id, name) ;
                        modify_student_year(id, year);
                        break;
                    case  modify_passoword_year :
                        Get_ID (&id) ;
                        Get_Password (password,"student") ;
                        Get_Year(&year);
                        modify_student_password(id, password);
                        modify_student_year(id, year);
                        break;
                    default:
                        /* should not be here */
                        break;
                }
                break; // for edit record
            case view_record :
                Init_View_One_Record () ;
                Get_ID (&id) ;
                view_student_info(id);
                break;
            case view_all :
                    Init_View_All_Records () ;
                    view_all_records () ;
                    break;
            case  edit_admin_password :
                Init_Edit_Password_Process ("admin") ;
                Get_Password (password ,"admin" ) ;
                modify_admin_password (password) ;
                break;
            default:
                Invalid_Choice ("operation") ;
                break;
        }

    }while (Ask_For_Resumption("in admin mode ") == Resume) ;

}
void Student_System (int id ) {
    tprivileges_student student_proecess = view_student_record;
    char name[MAX_STR_LEN] = "\0";
    char password[MAX_STR_LEN] = "\0";
    int year = 0;
    tcompletion completion = Resume;
    do {
        Make_Break();
        Present_Sutudent_Privileges();
        scanf("%d", &student_proecess);
        switch (student_proecess) {
            case view_student_record :
                Init_View_One_Record();
                view_student_info(id);
                break;
            case edit_password :
                Init_Edit_Password_Process("student");
                Get_Password(password, "student");
                modify_student_password(id, password);
                break;
            default:
                Invalid_Choice("operation");
                break;

        }
    }while (Ask_For_Resumption("in student mode") == Resume) ;
}

static void  Welcome_System (void )
{
    printf("Hello sir,\n"
           "Choosing mode process.\n"
           "Enter 0 for admin mode and 1 for student mode\n");
}
static void  Welcome_Admin_Mode (char *password )
{
    printf("You are in Admin Mode \n" );
    Get_Password(password , "Admin") ;

}
static void  Welcome_Student_Mode (char *password , int *id  )
{
    printf("You are in Student Mode \n");
    Get_ID(id) ;
    Get_Password(password, "Student") ;
}
static void  Invalid_Log_in (char *mode)
{
    printf("Invalid Log in to %s mode :( \n",mode);
}
static void  Correct_Log_in (char *mode)
{
    printf("Correct log in to %s mode \n",mode);
}
static void  Invalid_Choice (char *tchoice)
{
    printf("Invalid %s choice :( \n",tchoice) ;
}
static void  Get_All_Data (char *name, char *password, int *ID, int *year)
{
    Get_Name (name) ;
    Get_Password ( password , "Student") ;
    Get_ID (ID) ;
    Get_Year(year) ;
}
static void  Get_ID (int *id)
{
    printf("Enter student id \n") ;
    scanf("%d",id) ;
}
static void  Get_Name (char *name)
{
    printf("Enter Student Name \n") ;
    scanf("%s",name) ;
}
static void  Get_Password (char *password,char *mode)
{
    printf("Enter %s password \n",mode) ;
    scanf("%s",password) ;
}
static void Get_Year (int *year )
{
    printf("Enter student year \n") ;
    scanf("%d",year) ;
}
static void  Init_Add_Record (void)
{
    printf("Adding new record process \n"
           "****************************\n");
}
static void  Init_Remove_Record (void)
{
    printf("Removing new record process \n"
           "****************************\n");
}
static tedit_record  Init_Modify_Record (void)
{
    tedit_record choice = modify_name_password_year ;
    printf("Modifying record process \n"
           "****************************\n"
           "Choosing specified data to change \n"
           " Enter 0 to modify name              , 1 to modify password             \n"
           "       2 to modify_year              , 3 to modify name & password & year   \n"
           "       4 to modify name & password   , 5 to modify passoword & year  \n") ;
    scanf("%d",&choice) ;
    return choice ;
}
static void  Init_View_One_Record (void)
{
    printf("Viewing -one- record process \n"
           "****************************\n");
}
static void  Init_View_All_Records (void)
{
    printf("Viewing All records process \n"
           "****************************\n");
}
static void  Init_Edit_Password_Process (char *tmode)
{
    printf("Editing %s Password process \n"
           "****************************\n",tmode);
}
static void  Present_Admin_Privileges (void )
{
    printf("welcome in admin mode \n"
           "Choosing operation\n"
           " Enter 0 to add student record  , 1 to remove student record \n"
           "       2 to edit student record , 3 to view student record   \n"
           "       4 to view all records    , 5 to edit admin password  \n") ;
}
static void  Present_Sutudent_Privileges (void )
{
    printf("welcome in admin mode \n"
           "Choosing operation\n"
           " Enter 0 to view your record   , 1 to edit your password \n") ;
}
static void  Make_Break (void )
{
    printf("*************************************************************************************\n") ;
}
tcompletion Ask_For_Resumption (char *message )
{
    tcompletion completion ;
    printf("To resume %s\nEnter : 1 \nTo end Enter : 0\n",message) ;
    scanf("%d",&completion) ;
    return completion ;
}