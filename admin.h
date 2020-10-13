#ifndef __ADMIN_H__
#define __ADMIN_H__

#define ADMIN_DEFAULT_PASSWORD "hello"

typedef enum
{
    ADD_RECORD ,
    REMOVE_RECORD ,
    EDIT_RECORD ,
    VIEW_RECORD ,
    VIEW_ALL_RECORDS ,
    EDIT_ADMIN_PASSWORD
}tprivileges_admin;
typedef enum
{
    MODIFY_NAME ,
    MODIFY_PASSWORD ,
    MODIFY_YEAR ,
    MODIFY_TOTAL_DEGREE ,
}tedit_record;
/*
 * Description : Admin_System is a function that can choose between a lot of privileges ike (ADD_RECORD ,REMOVE_RECORD ,EDIT_RECORD ,VIEW_RECORD ,VIEW_ALL_RECORDS ,EDIT_ADMIN_PASSWORD) through
 * return      : No thing
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
void Admin_System (void ) ;
#endif // __ADMIN_H__