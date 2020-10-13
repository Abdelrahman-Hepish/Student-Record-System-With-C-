#ifndef __STUDENT_H__
#define __STUDENT_H__
typedef enum
{
    VIEW_STUDENT_RECORD ,
    EDIT_PASSWORD
}tprivileges_student ;
/*
 * Description : Student_System is a function that can choose between a lot of privileges ike (VIEW_STUDENT_RECORD ,EDIT_PASSWORD) through for students
 * return      : No thing
 * complexity  : O(N) Best Case Time = Worst Case Time
 */
void Student_System (void ) ;
#endif // __STUDENT_H__