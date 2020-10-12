#ifndef _SYSTEM_H__
#define _SYSTEM_H__


#define MAX_STR_LEN  100

typedef enum {
    admin ,
    student
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
tmode Init_System (void ) ;
void Init_Data(void) ;
tcompletion Ask_For_Resumption (char *message ) ;
#endif //  _SYSTEM_H__