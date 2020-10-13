#ifndef __ADMIN_H__
#define __ADMIN_H__
typedef enum
{
    add_record ,
    remove_record ,
    edit_record ,
    view_record ,
    view_all ,
    edit_admin_password
}tprivileges_admin;
typedef enum
{
    modify_name ,
    modify_password ,
    modify_year ,
    modify_total_degree ,
    modify_name_password_year_degree ,
    modify_name_password_year ,
    modify_name_password ,
    modify_name_year ,
    modify_password_year ,
    modify_name_degree
}tedit_record;
void Admin_System (void ) ;
#endif // __ADMIN_H__