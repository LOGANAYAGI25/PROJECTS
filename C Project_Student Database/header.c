#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
        int rollno;
        char name[50];
        float percentage;
        struct student *next;
}st;

void student_addmiddle(st**);
void data_add(st**);
void student_show(st*);
void delete_all(st**);
void student_save(st*);
void student_exit(st*);
int count(st*);
void reverse_list(st*);
void student_delete(st**);
void student_modification(st*);
void sort_list(st*);
int new_rollno(st*);
void roll_delete(st **);
void name_delete(st**);
void p_modify(st*);
void n_modify(st *);
void roll_name_percentage_modify(st*,int);
void roll_percentage_modify(st*,int);
void roll_name_modify(st*,int);
void roll_modify(st *);
void n_modify(st*);
void name_modify(st *, char *);
void n_percentage_modify(st *, char *);
void name_percentage_modify(st *, char *);
void p_name_modify(st *, float );
void percentage_modify(st *, float );
void p_name_percentage_modify(st *, float );

