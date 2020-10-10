#include "database.h"
#include <stdlib.h>
#define safeFree(p)   saferFree((void**)&(p))

static student_data class [CLASS_CAPACITY] ;
static  place state [CLASS_CAPACITY] ;
static void saferFree(void **pp) ;

bool Check_Admin_Password (char *password )
{

}
bool Check_Student_ID_Password (char *password, int id )
{

}
toperation Add_Student(char* name,char* password,int  id,int  year)
{

}
toperation Remove_Student(int id)
{

}
toperation Modify_Student_Name(int id,char* name)
{

}
toperation Modify_Student_Password(int id,char* password)
{

}
toperation Modify_Student_Year(int id,int year)
{

}
toperation View_Student_Info(int id)
{

}
toperation View_All_Records (void )
{

}
toperation Modify_Admin_Password (char *password)
{

}

void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}