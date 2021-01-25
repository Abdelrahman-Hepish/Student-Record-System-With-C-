#include "stdio.h"
#include "admin.h"
#include "system.h"
#include "interfacing.h"
#include "database.h"
void Admin_System (void )
{  /* initialization */
    tprivileges_admin admin_process = VIEW_ALL_RECORDS ;
    char name     [MAX_STR_LEN] = "\0" ;
    char password [MAX_STR_LEN] = "\0" ;
    int id = 0 ;
    int year = 0 ;
    int total_degree = 0 ;
    int student_place = 0 ;
    tcompletion completion = Resume ;
    do {
        Make_Break () ;
        Present_Admin_Privileges ( ) ;
        scanf("%d",&admin_process) ;
        switch (admin_process) {
            case ADD_RECORD :
                Init_Add_Record() ;
                Set_All_Data (name, password, &id, &year , &total_degree) ;
                if(Add_Student( name, password, id, year , total_degree) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in adding new student process ") ; }
                break;
            case REMOVE_RECORD :
                Init_Remove_Record () ;
                Set_ID(&id) ;
                if(Remove_Student(id) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in removing student process ") ; }
                break;
            case EDIT_RECORD :
                do {
                    Set_ID(&id);
                    student_place = Search_Student_Id(id);
                    if (student_place == NOT_FOUNDED)
                    {
                        Detect_Failure("getting the ID ");
                        continue;
                    }
                    switch (Init_Modify_Record () ) {
                        case MODIFY_NAME :
                            Set_Name (name) ;
                            if(Modify_Student_Name(id, name) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student name ") ; }
                            break;
                        case MODIFY_PASSWORD :
                            Set_Password (password,"student") ;
                            if(Modify_Student_Password(id, password) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student password ") ; }
                            break;
                        case  MODIFY_YEAR :
                            Set_Year(&year);
                            if(Modify_Student_Year(id, year) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student year ") ; }
                            break;
                        case MODIFY_TOTAL_DEGREE :
                            Set_Total_Degree(&total_degree) ;
                            if(Modify_Student_Total_Degree(id , total_degree) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student total degree ") ; }
                            break;
                        default:
                            /* should not be here */
                            break;
                    }
                }while (Ask_For_Resumption("editing student record ") == Resume) ;
                break; // for edit record
            case VIEW_RECORD :
                Init_View_One_Record () ;
                Set_ID (&id) ;
                if(View_Student_Info(id) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in viewing student record process ") ; }
                break;
            case VIEW_ALL_RECORDS :
                Init_View_All_Records () ;
                if(View_All_Records ()  != SUCCESSFUL_OPERATION)
                { Detect_Failure("in viewing all records process ") ; }
                break;
            case  EDIT_ADMIN_PASSWORD :
                Init_Edit_Password_Process ("admin") ;
                Set_Password (password ,"admin" ) ;
                if(Modify_Admin_Password (password)   != SUCCESSFUL_OPERATION)
                { Detect_Failure("in editing admin password process ") ; }
                break;
            default:
                Invalid_Choice ("operation") ;
                break;
        }

    }while (Ask_For_Resumption("admin mode ") == Resume) ;

}