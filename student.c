#include "student.h"
#include <stdio.h>
#include "interfacing.h"
#include "database.h"
/* FAILURE_OPERATION ,
    SUCCESSFUL_OPERATION*/
extern int share_student_id ;
void Student_System (void ) {
    tprivileges_student student_proecess = view_student_record;
    char name[MAX_STR_LEN] = "\0";
    char password[MAX_STR_LEN] = "\0";
    int id = share_student_id ;
    int year = 0;
    tcompletion completion = Resume;
    do {
        Make_Break();
        Present_Sutudent_Privileges();
        scanf("%d", &student_proecess);
        switch (student_proecess) {
            case view_student_record :
                Init_View_One_Record();
                if(View_Student_Info(id) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in viewing student info process ") ; }
                break;
            case edit_password :
                Init_Edit_Password_Process("student");
                Set_Password(password, "student");
                if(Modify_Student_Password(id, password) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in editing student password process ") ; }
                break;
            default:
                Invalid_Choice("operation");
                break;

        }
    }while (Ask_For_Resumption("student mode") == Resume) ;
}