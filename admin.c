#include "stdio.h"
#include "admin.h"
#include "system.h"
#include "interfacing.h"
#include "database.h"
void Admin_System (void )
{  /* initialization */
    tprivileges_admin admin_process = view_all ;
    char name     [MAX_STR_LEN] = "\0" ;
    char password [MAX_STR_LEN] = "\0" ;
    int id = 0 ;
    int year = 0 ;
    int total_degree = 0 ;
    tcompletion completion = Resume ;
    do {
        Make_Break () ;
        Present_Admin_Privileges ( ) ;
        scanf("%d",&admin_process) ;
        switch (admin_process) {
            case add_record :
                Init_Add_Record() ;
                Set_All_Data (name, password, &id, &year , &total_degree) ;
                if(Add_Student( name, password, id, year , total_degree) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in adding new student process ") ; }
                break;
            case remove_record :
                Init_Remove_Record () ;
                Set_ID(&id) ;
                if(Remove_Student(id) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in removing student process ") ; }
                break;
            case edit_record :
                do {
                    Set_ID (&id) ;
                    switch (Init_Modify_Record () ) {
                        case modify_name :
                            Set_Name (name) ;
                            if(Modify_Student_Name(id, name) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student name ") ; }
                            break;
                        case modify_password :
                            Set_Password (password,"student") ;
                            if(Modify_Student_Password(id, password) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student password ") ; }
                            break;
                        case  modify_year :
                            Set_Year(&year);
                            if(Modify_Student_Year(id, year) != SUCCESSFUL_OPERATION)
                            { Detect_Failure("in modifying student year ") ; }
                            break;
                        case modify_total_degree :
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
            case view_record :
                Init_View_One_Record () ;
                Set_ID (&id) ;
                if(View_Student_Info(id) != SUCCESSFUL_OPERATION)
                { Detect_Failure("in viewing student record process ") ; }
                break;
            case view_all :
                Init_View_All_Records () ;
                if(View_All_Records ()  != SUCCESSFUL_OPERATION)
                { Detect_Failure("in viewing all records process ") ; }
                break;
            case  edit_admin_password :
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