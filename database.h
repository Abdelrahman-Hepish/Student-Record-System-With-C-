#ifndef __DATA_BASE_H__
#define __DATA_BASE_H__
#include "system.h"
#define CLASS_CAPACITY   10
typedef struct
{
    char *name ;
    char *password ;
    int id ;
    int year ;
    int total_degree ;
}student_data;
typedef enum
{
    RESERVED ,
    FREE
}place;
typedef enum
{
    ALL_REVERSED = -1 ,
    NOT_FOUNDED  = -1
}available_place ;
/*
 * Description : Check_Admin_Password is a function that checks if the the entered password is convenient with admin current password
 * return      : TRUE if convenient , FALSE if not
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
bool Check_Admin_Password (char *password ) ;
/*
 * Description : Check_Student_ID_Password is a function that checks if the the entered password is convenient with the student password with the entered id
 * return      : TRUE if convenient , FALSE if not
 * complexity  : O(N)
 */
bool Check_Student_ID_Password (char *password, int id ) ;
/*
 * Description : Add_Student is a function that checks if there is a free place in the class and the passed id is not exist if there is a free place and the passed id is unique it adds a new student in the class
 * return      : TRUE if there is a place in the class and the passed id is unique  , FALSE if there is no spare place in the class or the passed id is exist
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Add_Student(char* name,char* password,int  id,int  year , int total_degree) ;
/*
 * Description : Remove_Student is a function that checks if the passed id is exists in the class and if exists it will remove it from the class
 * return      : SUCCESSFUL_OPERATION if there is an id matches the passed id in the class , FAILURE_OPERATION if there is no id like the passed one
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Remove_Student(int id);
/*
 * Description : Modify_Student_Name is a function that checks if the passed id is exists in the class and if exists it will change the name of the specific id
 * return      : SUCCESSFUL_OPERATION if there is an id matches the passed id in the class , FAILURE_OPERATION if there is no id like the passed one
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Modify_Student_Name(int id,char* name) ;
/*
 * Description : Modify_Student_Password is a function that checks if the passed id is exists in the class and if exists it will change the password of the specific id
 * return      : SUCCESSFUL_OPERATION if there is an id matches the passed id in the class , FAILURE_OPERATION if there is no id like the passed one
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Modify_Student_Password(int id,char* password);
/*
 * Description : Modify_Student_Year is a function that checks if the passed id is exists in the class and if exists it will change the year of the specific id
 * return      : SUCCESSFUL_OPERATION if there is an id matches the passed id in the class , FAILURE_OPERATION if there is no id like the passed one
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Modify_Student_Year(int id,int year);
/*
 * Description : Modify_Student_Total_Degree is a function that checks if the passed id is exists in the class and if exists it will change the total degree of the specific id
 * return      : SUCCESSFUL_OPERATION if there is an id matches the passed id in the class , FAILURE_OPERATION if there is no id like the passed one
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Modify_Student_Total_Degree(int id,int degree);
/*
 * Description : View_Student_Info is a function that checks if the passed id is exists in the class and if exists it will print all his data (name - id - year - degree ) it will not print the password
 * return      : SUCCESSFUL_OPERATION if there is an id matches the passed id in the class , FAILURE_OPERATION if there is no id like the passed one
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation View_Student_Info(int id);
/*
 * Description : View_All_Records is a function that checks if there are students in the class and if it will prints all their data
 * return      : SUCCESSFUL_OPERATION if there are students in the class , FAILURE_OPERATION if there are no students in the class
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation View_All_Records (void ) ;
/*
 * Description : Modify_Admin_Password is a function changes the current admin password to the new passed password
 * return      : Always SUCCESSFUL_OPERATION
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
toperation Modify_Admin_Password (char *password) ;
/*
 * Description : Set_Place_State is a function used to initialize the places in the class all to be free
 * return      : No thing
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
void Set_Place_State (void) ;
/*
 * Description : Set_Admin_Default_Password is a function used to initialize the admin default password 
 * return      : No thing
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
void Set_Admin_Default_Password (void ) ;

#endif // __DATA_BASE_H__