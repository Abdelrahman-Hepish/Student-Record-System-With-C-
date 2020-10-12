#include <stdio.h>
#include "system.h"
#include "interfacing.h"
#include "database.h"
int share_student_id ;
void Init_Data(void)
{
    Set_Place_State() ;
    Set_Admin_Defult_Password() ;
}
tmode Init_System (void ) {
    tmode mode = admin;
    char password[MAX_STR_LEN] = "\0";
    int id ;
    Welcome_System () ;
    scanf("%d", &mode);
    switch (mode) {
        case admin :
            Welcome_Admin_Mode (password) ;
            if (Check_Admin_Password(password)) {
                Correct_Log_in("admin") ;
                return admin;
            } else {
                Invalid_Log_in ("admin") ;
            }
            break;
        case student :
            Welcome_Student_Mode (password , &id ) ;
            share_student_id = id ;
            if (Check_Student_ID_Password(password, id)) {
                Correct_Log_in ("student") ;
                return student;
            } else {
                Invalid_Log_in ("student") ;
            }
            break;
        default:
            Invalid_Choice ("mode") ;
    }
}


