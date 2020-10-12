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
                Add_Student( name, password, id, year , total_degree) ;
                break;
            case remove_record :
                Init_Remove_Record () ;
                Set_ID(&id) ;
                Remove_Student(id) ;
                break;
            case edit_record :
                switch (Init_Modify_Record () ) {
                    case modify_name_password_year :
                        Set_ID (&id) ;
                        Set_Name (name) ;
                        Set_Password (password,"student") ;
                        Set_Year(&year);
                        Modify_Student_Name(id, name) ;
                        Modify_Student_Password(id, password);
                        Modify_Student_Year(id, year);
                        break;
                    case modify_name :
                        Set_ID (&id) ;
                        Set_Name (name) ;
                        Modify_Student_Name(id, name) ;
                        break;
                    case modify_password :
                        Set_ID (&id) ;
                        Set_Password (password,"student") ;
                        Modify_Student_Password(id, password);
                        break;
                    case  modify_year :
                        Set_ID (&id) ;
                        Set_Year(&year);
                        Modify_Student_Year(id, year);
                        break;
                    case modify_name_password :
                        Set_ID (&id) ;
                        Set_Name (name) ;
                        Set_Password (password,"student") ;
                        Modify_Student_Name(id, name) ;
                        Modify_Student_Password(id, password);
                        break;
                    case  modify_name_year :
                        Set_ID (&id) ;
                        Set_Name (name) ;
                        Set_Year(&year);
                        Modify_Student_Name(id, name) ;
                        Modify_Student_Year(id, year);
                        break;
                    case  modify_password_year :
                        Set_ID (&id) ;
                        Set_Password (password,"student") ;
                        Set_Year(&year);
                        Modify_Student_Password(id, password);
                        Modify_Student_Year(id, year);
                        break;
                    default:
                        /* should not be here */
                        break;
                }
                break; // for edit record
            case view_record :
                Init_View_One_Record () ;
                Set_ID (&id) ;
                View_Student_Info(id);
                break;
            case view_all :
                Init_View_All_Records () ;
                View_All_Records () ;
                break;
            case  edit_admin_password :
                Init_Edit_Password_Process ("admin") ;
                Set_Password (password ,"admin" ) ;
                Modify_Admin_Password (password) ;
                break;
            default:
                Invalid_Choice ("operation") ;
                break;
        }

    }while (Ask_For_Resumption("in admin mode ") == Resume) ;

}