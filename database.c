#include <stdlib.h>
#include <stdio.h>
#include "configuration.h"
#include "List.h"
#include "database.h"
#include <string.h>
#include "interfacing.h"

static List class ;

static char* admin_password  ;

#define safeFree(p) saferFree((void**)&(p))
static void saferFree(void **pp) ;
static available_place Available_Place (void ) ;


bool Check_Admin_Password (char *password )
{
    if (strcmp(password,admin_password) == 0 ) return TRUE ;
    else return  FALSE ;
}
bool Check_Student_ID_Password (char *password, int id )
{
    int student_place = Search_Student_Id (id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FALSE ;
    else
    {
     RetrieveList(student_place,&temp_record,&class) ;
     if(temp_record.id == id && strcmp(password ,temp_record.password) == 0 ) return TRUE ;
     return FALSE ; // may be doesn't exist and may be incorrect id
    }
}
toperation Add_Student(char* name,char* password,int id,int  year , int total_degree )
{
    int free_place = Available_Place() ;
    student_data temp_record ;
    if(Search_Student_Id(id) != NOT_FOUNDED) return FAILURE_OPERATION ;
    if (free_place == ALL_REVERSED ) return  FAILURE_OPERATION ;
    else
    {
        // bug is here
        temp_record.name = (char *) malloc(strlen(name)+1);
        temp_record.password = (char *) malloc(strlen(password)+1);
        strcpy(temp_record.name,name) ;
        strcpy(temp_record.password,password) ;
        temp_record.id = id ;
        temp_record.year = year ;
        temp_record.total_degree = total_degree ;
        InsertList(free_place,temp_record,&class) ;
        return  SUCCESSFUL_OPERATION ;
    }
}
toperation Remove_Student(int id)
{
    int student_place = Search_Student_Id(id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FAILURE_OPERATION ;
    else
    {
        RetrieveList(student_place,&temp_record,&class) ;
        safeFree(temp_record.name) ;
        safeFree(temp_record.password) ;
        DeleteList(student_place,&temp_record,&class) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Name(int id,char* name)
{
    int student_place = Search_Student_Id(id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FAILURE_OPERATION ;
    else
    {
        RetrieveList(student_place,&temp_record,&class) ;
        temp_record.name = (char *) malloc(strlen(name)+1);
        strcpy(temp_record.name,name) ;
        ReplaceList(student_place,temp_record,&class) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Password(int id,char* password)
{
    int student_place = Search_Student_Id(id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FAILURE_OPERATION ;
    else
    {
        RetrieveList(student_place,&temp_record,&class) ;
        temp_record.password = (char *) malloc(strlen(password)+1);
        strcpy(temp_record.name,password) ;
        ReplaceList(student_place,temp_record,&class) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Year(int id,int year)
{
    int student_place = Search_Student_Id(id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FAILURE_OPERATION ;
    else
    {
        RetrieveList(student_place,&temp_record,&class) ;
        temp_record.year = year ;
        ReplaceList(student_place,temp_record,&class) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Total_Degree(int id,int degree)
{
    int student_place = Search_Student_Id(id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FAILURE_OPERATION ;
    else
    {
        RetrieveList(student_place,&temp_record,&class) ;
        temp_record.total_degree = degree ;
        ReplaceList(student_place,temp_record,&class) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation View_Student_Info(int id)
{
    int student_place = Search_Student_Id(id) ;
    student_data temp_record ;
    if(student_place == NOT_FOUNDED) return FAILURE_OPERATION ;
    else
    {
        RetrieveList(student_place,&temp_record,&class);
        Make_Break();
        printf("Student name : %s\n",temp_record.name);
        printf("Student ID : %d\n",temp_record.id);
        printf("Student year : %d\n",temp_record.year);
        printf("Student degree : %d\n",temp_record.total_degree);
        Make_Break();
    }
    return SUCCESSFUL_OPERATION ;
}
toperation View_All_Records (void )
{
    int i ;
    student_data temp_record ;
    for(i = 0 ; i <ListSize(&class); i++)
    {
      RetrieveList(i,&temp_record,&class) ;
      View_Student_Info(temp_record.id) ;
    }
    if (i == 0 ) return FAILURE_OPERATION ;
    return SUCCESSFUL_OPERATION ;
}
toperation Modify_Admin_Password (char *password)
{
    admin_password  = (char *) malloc(strlen(password)+1) ;
    strcpy(admin_password , password) ;
    return SUCCESSFUL_OPERATION ;
}
static available_place Available_Place (void )
{
    return  ListSize(&class) ;
}
available_place Search_Student_Id (int id )
{
    int i  ;
    student_data temp_record ;
    for(i = 0 ; i <ListSize(&class) ; i++)
    {
        RetrieveList(i,&temp_record,&class);
        if(id==temp_record.id) break;
    }
    if (i == ListSize(&class)) return NOT_FOUNDED ;
    return  i ;
}

void Set_Place_State (void)
{
    CreateList(&class) ;
}
void Set_Admin_Default_Password (void )
{
    admin_password = (char *) malloc(sizeof(ADMIN_DEFAULT_PASSWORD)+1) ;
    strcpy(admin_password, ADMIN_DEFAULT_PASSWORD) ;
}
void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}