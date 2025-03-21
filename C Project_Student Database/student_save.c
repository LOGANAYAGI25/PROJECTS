#include "header.c"

void student_save(st *ptr)
{
        FILE *file=fopen("student.data","w");
        if(!file)
        {
                printf("File is not exist\n");
                return;
        }
        //student *temp=ptr;
        while(ptr!=0)
        {
                fprintf(file,"%d   %s   %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
        fclose(file);
        printf("All records are saved successfully in a file\n");
        
}
