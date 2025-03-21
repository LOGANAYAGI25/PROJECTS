#include "header.c"

void student_show(st *ptr)
{
        if(ptr==NULL)
        {
                printf("Records is empty\n");
                return;
        }
        //student *temp=ptr;
        printf("\nRoll Number\t\tName\t\t\tPercentage\n");
        printf("-----------------------------------------------------------\n");
        while(ptr!=NULL)
        {
                printf("%d\t\t\t%s\t\t\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
}

