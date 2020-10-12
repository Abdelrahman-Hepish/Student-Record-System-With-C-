#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfacing.h"
#define safeFree(p) saferFree((void**)&(p))

static student_data class [CLASS_CAPACITY] ;
static  place state [CLASS_CAPACITY] ;
static char* admin_password = ADMIN_DEFAULT_PASSWORD ;

static void saferFree(void **pp) ;
static available_place Available_Place (void ) ;
static void  view_index_info (int i ) ;
static available_place Search_Student_Id (int id ) ;

bool Check_Admin_Password (char *password )
{
    if (strcmp(password,admin_password) == 0 ) return TRUE ;
    else return  FALSE ;
}
bool Check_Student_ID_Password (char *password, int id )
{
    int student_place = Search_Student_Id (id) ;
    if(student_place == NOT_FOUNDED)
    {
        return FALSE ;
    } else
    {
        if(class[student_place].id == id && strcmp(password , class[student_place].password) == 0 && state[student_place] == RESERVED )
        {
            return TRUE ;
        }
        return FALSE ; // may be doesn't exist and may be incorrect id
    }
}
toperation Add_Student(char* name,char* password,int  id,int  year , int total_degree )
{
    int free_place = Available_Place() ;
    if (free_place == ALL_REVERSED ) return  FAILURE_OPERATION ;
    else
    {
        state[free_place] = RESERVED ;
        class[free_place].name = (char *) malloc(strlen(name)+1);
        strcpy(class[free_place].name , name) ;
        class[free_place].password = (char *) malloc(strlen(password)+1);
        strcpy(class[free_place].password , password) ;
        class[free_place].id = id ;
        class[free_place].year = year ;
        class[free_place].total_degree = total_degree ;
        return  SUCCESSFUL_OPERATION ;
    }
}
toperation Remove_Student(int id)
{
  int student_place = Search_Student_Id(id) ;
  if(student_place == NOT_FOUNDED)
  {
      return FAILURE_OPERATION ;
  }else
  {
      state[student_place] = FREE ;
     safeFree(class[student_place].password) ;
     safeFree(class[student_place].name) ;
     /* i don't need the following 3 lines of code but for semetry */
     class[student_place].id = -10 ;
     class[student_place].year = -10 ;
      class[student_place].total_degree = -10 ;
      return SUCCESSFUL_OPERATION ;
  }
}
toperation Modify_Student_Name(int id,char* name)
{
 int student_place = Search_Student_Id(id) ;
    if(student_place == NOT_FOUNDED)
    {
        return FAILURE_OPERATION ;
    }else
    {
        class[student_place].name = (char *) malloc(strlen(name)+1) ;
        strcpy(class[student_place].name , name) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Password(int id,char* password)
{
    int student_place = Search_Student_Id(id) ;
    if(student_place == NOT_FOUNDED)
    {
        return FAILURE_OPERATION ;
    }else
    {
        class[student_place].password = (char *) malloc(strlen(password)+1) ;
        strcpy(class[student_place].password , password) ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Year(int id,int year)
{
    int student_place = Search_Student_Id(id) ;
    if(student_place == NOT_FOUNDED)
    {
        return FAILURE_OPERATION ;
    }else
    {
        class[student_place].year = year ;
        return SUCCESSFUL_OPERATION ;
    }
}
toperation Modify_Student_Total_Degree(int id,int degree)
{
    int student_place = Search_Student_Id(id) ;
    if(student_place == NOT_FOUNDED)
    {
        return FAILURE_OPERATION ;
    }else
    {
        class[student_place].total_degree = degree ;
        return SUCCESSFUL_OPERATION ;
    }

}
toperation View_Student_Info(int id)
{
    int student_place = Search_Student_Id(id) ;
    if(student_place == NOT_FOUNDED)
    {
        return FAILURE_OPERATION ;
    }else
    {
        Make_Break();
        printf("Student name : %s\n",class[student_place].name);
        printf("Student ID : %d\n",class[student_place].id);
        printf("Student year : %d\n",class[student_place].year);
        printf("Student degree : %d\n",class[student_place].total_degree);
        Make_Break();
    }
    return SUCCESSFUL_OPERATION ;
}
toperation View_All_Records (void )
{
  int i = 0 , j = 0 ;
  for(i = 0 ; i <CLASS_CAPACITY ; i++)
  {
      if (state[i] == RESERVED)
      {
          view_index_info(i) ;
          j++ ;
      }
  }
  if (j == 0 )
  {
      return FAILURE_OPERATION ;
  }
    return SUCCESSFUL_OPERATION ;
}
toperation Modify_Admin_Password (char *password)
{
    admin_password  = (char *) malloc(strlen(password)+1) ;
    strcpy(admin_password , password) ;
    return SUCCESSFUL_OPERATION ;
}
void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}
static available_place Available_Place (void )
{
    int i = 0 ;
    for(i=0 ; i < CLASS_CAPACITY ; i++)
    {
        if(state[i] == FREE)
        break;
    }
    if (i == CLASS_CAPACITY)
    {
        return ALL_REVERSED ;
    }
    return  i ;
}
static available_place Search_Student_Id (int id )
{
    int i = 0 ;
    for(i = 0 ; i <CLASS_CAPACITY ; i++)
    {
        if(class[i].id == id && state[i]== RESERVED)
            break;
    }
    if (i == CLASS_CAPACITY)
    {
        return NOT_FOUNDED ;
    }
    return  i ;

}
static void  view_index_info (int i )
{
    Make_Break();
    printf("Student name : %s\n",class[i].name);
    printf("Student ID : %d\n",class[i].id);
    printf("Student year : %d\n",class[i].year);
    printf("Student degree : %d\n",class[i].total_degree);
    Make_Break();
}