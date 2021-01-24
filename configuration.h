#ifndef __CONFIGURAION_H__
#define __CONFIGURAION_H__

typedef struct
{
    char *name ;
    char *password ;
    int id ;
    int year ;
    int total_degree ;
}student_data;
typedef student_data ListEntry;
/*
 * Choose between two features :
 * 1- UNLIMITED_SPACE
 * 2- LIMITED_SPACE
 */
#define  UNLIMITED_SPACE
#endif