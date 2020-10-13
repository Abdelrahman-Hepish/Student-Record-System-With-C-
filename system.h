#ifndef _SYSTEM_H__
#define _SYSTEM_H__


#define MAX_STR_LEN  100

typedef enum {
    ADMIN ,
    STUDENT ,
}tmode;
typedef enum {
    Stop ,
    Resume
}tcompletion;
typedef enum
{
    FALSE ,
    TRUE
}bool;
typedef enum
{
    FAILURE_OPERATION ,
    SUCCESSFUL_OPERATION
}toperation;
/*
 * Description : Init_System is a function that you can choose the current mode through (admin or student) and checks if the log in is correct
 * return      : ADMIN if the user choose the admin mode and the password was correct , STUDENT if the user choose the student mode and the data of the student was exist in the class
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
tmode Init_System (void ) ;
/*
 * Description : Init_Data is a function that called once at the begging of the program to initialize the state of the class and the default password for the admin
 * return      : No thing
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
void Init_Data(void) ;
/*
 * Description : Ask_For_Resumption is a function that called after finishing a part of operations which you can choose between them and your can choose which part by pass a string literal to the specific part
 * return      : RESUME if the user want to resume in this block , Stop if the user want to get out of that block
 * complexity  : O(1) Best Case Time = Worst Case Time
 */
tcompletion Ask_For_Resumption (char *message ) ;
#endif //  _SYSTEM_H__