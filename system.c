#include <stdio.h>
#include "system.h"
#include "interfacing.h"
#include "database.h"
int share_student_id ;
void Init_Data(void)
{
    Set_Place_State() ;
    Set_Admin_Default_Password() ;
}
tmode Init_System (void ) {
    tmode mode = ADMIN;
    char password[MAX_STR_LEN] = "\0";
    int id ;
    Welcome_System () ;
    scanf("%d", &mode);
    switch (mode) {
        case ADMIN :
            Welcome_Admin_Mode (password) ;
            if (Check_Admin_Password(password)) {
                Correct_Log_in("admin") ;
                return ADMIN;
            } else {
                Invalid_Log_in ("admin") ;
            }
            break;
        case STUDENT :
            Welcome_Student_Mode (password , &id ) ;
            share_student_id = id ;
            if (Check_Student_ID_Password(password, id)) {
                Correct_Log_in ("student") ;
                return STUDENT;
            } else {
                Invalid_Log_in ("student") ;
            }
            break;
        default:
            Invalid_Choice ("mode") ;
    }
}
tcompletion Ask_For_Resumption (char *message )
{
    tcompletion completion ;
    printf("To resume in %s\n"
           "Enter : 1 \n"
           "To end %s\n"
           "Enter : 0\n",message,message) ;
    scanf("%d",&completion) ;
    return completion ;
}