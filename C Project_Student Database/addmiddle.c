#include "header.c"

void student_addmiddle(st **ptr)
{
        char op;
        do
        {
                data_add(ptr);

                printf("Do you wants add another node(y/n)\n");
                scanf(" %c",&op);
        }while((op=='Y')||(op=='y'));
}

void data_add(st **ptr)
{
        st *temp=(st*)malloc(sizeof(st));
        if(!temp)
        {
                printf("Memory allocation failed.\n");
                return;
        }
        temp->rollno=new_rollno(* ptr);


        printf("Enter the name and percentage\n");
        scanf("%s%f",temp->name,&temp->percentage);

        if((*ptr==0)||(temp->rollno<(*ptr)->rollno))
        {
                temp->next=*ptr;
                *ptr=temp;
        }
        else
        {
                st *last=*ptr;
                while((last->next!=0)&&(temp->rollno>(last->next->rollno)))
                        last=last->next;

                temp->next=last->next;
                last->next=temp;
        }
}

int new_rollno(st *ptr)
{
    int roll = 1;
    st *temp = ptr;
    while (temp != NULL)
    {
        if (temp->rollno == roll)
        {
            roll++;
        }
        temp = temp->next;
    }
    return roll;
}

