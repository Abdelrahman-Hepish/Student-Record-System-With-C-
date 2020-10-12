#ifndef _SYSTEM_H__
#define _SYSTEM_H__


#define MAX_STR_LEN  100

typedef enum {
    admin ,
    student
}tmode;
typedef enum
{
    add_record ,
    remove_record ,
    edit_record ,
    view_record ,
    view_all ,
    edit_admin_password
}tprivileges_admin;
typedef enum
{
    view_student_record ,
    edit_password
}tprivileges_student ;
typedef enum
{
     modify_name ,
     modify_password ,
     modify_year ,
     modify_name_password_year ,
     modify_name_password ,
     modify_name_year ,
     modify_passoword_year
}tedit_record;
typedef enum {
    Stop ,
    Resume
}tcompletion;
typedef enum
{
    FALSE ,
    TRUE
}bool;
typedef enum
{
    FAILURE_OPERATION ,
    SUCCESSFUL_OPERATION
}toperation;
tmode Init_System (void ) ;
void Admin_System (void ) ;
void Student_System (void ) ;
tcompletion Ask_For_Resumption (char *message ) ;
#endif //  _SYSTEM_H__