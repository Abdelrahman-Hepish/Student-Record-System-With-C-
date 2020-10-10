#ifndef __DATA_BASE_H__
#define __DATA_BASE_H__
#include "system.h"
#define CLASS_CAPACITY   10
typedef struct
{
    char *name ;
    char *password ;
    int id ;
    int total_degree ;
}student_data;
typedef enum
{
    NOT_AVAILABLE ,
    AVAILABLE
}place;
bool Check_Admin_Password (char *password ) ;
bool Check_Student_ID_Password (char *password, int id ) ;
toperation Add_Student(char* name,char* password,int  id,int  year) ;
toperation Remove_Student(int id);
toperation Modify_Student_Name(int id,char* name) ;
toperation Modify_Student_Password(int id,char* password);
toperation Modify_Student_Year(int id,int year);
toperation View_Student_Info(int id);
toperation View_All_Records (void ) ;
toperation Modify_Admin_Password (char *password) ;

#endif // __DATA_BASE_H__