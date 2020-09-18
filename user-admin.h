//
// Created by HP EliteBook on 9/8/2020.
//

#ifndef INTERMDIATE_LVL_PROJECT_USER_ADMIN_H
#define INTERMDIATE_LVL_PROJECT_USER_ADMIN_H
void user_admin_init(void);
/*
 * description : initializing admin default password , initializing the array of available indexes.
 */
int check_admin_password(char *password);
/*
*  description: check if the entered password is correct or not.
*  return: 1 if correct, 0 if wrong.
*/
int modify_admin_password(char *newPassword);
/*
* description: reallocate the memory for the new password and edit the admin default Password.
*/
int check_student_ID_password(char *password, int ID);
/*
*  description: check if the entered ID and password are correct.
*  return: 1 if correct, 0 if wrong.
*/

int add_student(char *name, char *password, int ID, int year);
/*
*  description: add new record.
*  return: 1 if adding is done, 0 if adding is undone.
*/

int remove_student(int ID);
/*
*  description: remove the student.
*  return: 1 if the student is removed , 0 if the Entered ID doesn't exist.
*/

int modify_student_name(int ID, char *newName);
/*
*  description: modify the student name.
*  return: 1 if modifying is done, 0 if modifying is undone.
*/

int modify_student_password(int ID, char *newPassword);
/*
*  description: modify the student password.
*  return: 1 if modifying is done, 0 if modifying is undone.
*/


int modify_student_year(int ID, int newYear);
/*
*  description: modify the student year.
*  return: 1 if modifying is done, 0 if modifying is undone.
*/

void view_student_info(int ID);
/*
*  description: view info about student.
*  return: void.
*/

void view_all_records (void);
/*
 * description: view info of all the students .
 * return:void.
 */

#endif //INTERMDIATE_LVL_PROJECT_USER_ADMIN_H

