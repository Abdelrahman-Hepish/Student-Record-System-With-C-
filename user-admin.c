#include "configration.h"
#include "user-admin.h"
#define safeFree(p) saferFree((void**)&(p))
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int availableIndex[MAX_STUDENTS];
static students records[MAX_STUDENTS];
static char *adminCurrentPassword;
static void set_admin_password(void);
static void available_index_init(void);
static int is_id_exist(int);
static int get_available_index(void);



static void set_admin_password(void)
{

    adminCurrentPassword=(char *)malloc(strlen("hello")+1);
    strcpy(adminCurrentPassword, "hello");

}
static void available_index_init(void)
{

    int i;
    for (i = 0; i <MAX_STUDENTS; ++i)
    {
        availableIndex[i] = 1;
    }


}
static int is_id_exist(int ID)
{
    int i;
    for (i=0; i<MAX_STUDENTS; i++)
    {
        if(records[i].ID==ID)
        {
            return i;
        }

    }
    return -1;

}
static int get_available_index(void)
{
    int i;
    for ( i = 0; i <MAX_STUDENTS-1; ++i)
    {
        if(availableIndex[i]==1)
        {
            return i;
        }

    }
    return -1;
}
void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}
void user_admin_init(void)
{
    available_index_init();
    set_admin_password();
}
int check_admin_password(char *password)
{

    if(strcmp(password,adminCurrentPassword)==0)
    {
        return 1;

    }
    return 0;
}
int modify_admin_password(char *newPassword)
{

    adminCurrentPassword=realloc(adminCurrentPassword,strlen(newPassword)+1);
    strcpy(adminCurrentPassword,newPassword);
    return 1;

}
int check_student_ID_password(char *password, int ID)
{


    if(ID>0)
    {
        int i;

        for(i=0; i<MAX_STUDENTS-1; i++)
        {

            if(records[i].ID==ID)
            {
                if(strcmp(records[i].password,password)==0)
                {
                    return 1;
                }
            }
        }

    }

    else
    {

        return 0;
    }
    return 0;

}
int add_student(char *name, char *password, int ID, int year)
{
    int i=get_available_index();

    if(i!=-1)
    {
        availableIndex[i]=0;
        records[i].ID=ID;
        records[i].name = (char*)malloc(strlen(name)+1);
        strcpy(records[i].name,name);
        records[i].password=(char*)malloc(strlen(password)+1);
        strcpy(records[i].password,password);
        records[i].year=year;
        return 1;

    }
    return 0;
}
int remove_student(int ID)
{
    int i=is_id_exist(ID);
    if(i!=-1)
    {

        availableIndex[i]=1;
        records[i].ID=0;
        records[i].year=0;
        safeFree(records[i].name);
        safeFree(records[i].password);
        return 1;
    }
    return 0;
}
int modify_student_name(int ID, char *newName)
{
    int i=is_id_exist(ID);
    if(i!=-1)
    {
        records[i].name=realloc(records[i].name,strlen(newName)+1);
        strcpy(records[i].name,newName);
        return 1;

    }
    printf("Student doesn't exist") ;
    return 0;
}
int modify_student_password(int ID, char *newPassword)
{

    int i=is_id_exist(ID);
    if(i!=-1)
    {
        records[i].password=realloc(records[i].password,strlen(newPassword)+1);
        strcpy(records[i].password,newPassword);
        return 1;

    }
    return 0;

}

int modify_student_year(int ID, int newYear)
{


    int i=is_id_exist(ID);
    if(i!=-1)
    {
        records[i].year=newYear;
        return 1;

    }
    return 0;

}


void view_student_info(int ID)
{

    int i=is_id_exist(ID);
    if(i!=-1)
    {
        {
            printf("\n the student information is :\n");
            printf("the student ID is %d\n", records[i].ID);
            printf("the student name is %s\n", records[i].name);
            printf("the student Password is %s\n", records[i].password);
            printf("the student year is %d\n", records[i].year);

        }
    }
    else
    {
        printf("student doesn't exist\n");
    }
}
void view_all_records(void){

    int i;
    for(i=0;i<MAX_STUDENTS;i++){

        if(availableIndex[i]==0){

            printf("\n");
            printf("\nthe student information is :\n");
            printf("the student ID is %d\n", records[i].ID);
            printf("the student name is %s\n", records[i].name);
            printf("the student Password is %s\n", records[i].password);
            printf("the student year is %d\n", records[i].year);
            printf("\n");

        }
    }


};
