#include "header.c"

void student_delete(st **ptr)
{
        if((*ptr)==NULL)
	{
                 printf("No stduent data to delete\n");
                 return;
        }

	char op;

    printf("\t\t|----------------------------------------|\n");
    printf("\t\t|Enter                                   |\n");
    printf("\t\t|R/r:enter roll to delete                |\n");
    printf("\t\t|N/n:enter name to delete                |\n");
    printf("\t\t|________________________________________|\n");

    printf("Enter your option: ");
    scanf(" %c",&op);

    if(op=='r'||op=='R')
        roll_delete(ptr);    

    else if(op=='n'||op=='N')
        name_delete(ptr);

    else
    {
        printf("invalid option\n");
        return;
    }
}

void roll_delete(st **ptr)
{
 	int x;
        printf("enter the roll number:");
        scanf("%d",&x);

        st *temp=*ptr,* last;
        while(temp!=0)
	{
                if(temp->rollno==x)
		{
                        if((*ptr)->rollno==x)
				*ptr=(*ptr)->next;
                       
                        else
				last->next=temp->next;
                
			free(temp);
			temp=NULL;
			return;
                }
                else
		{        
			last=temp;
			temp=temp->next;
                }
        }

	printf("data doesn't exist to delete\n");
}

void name_delete(st **ptr)
{
        char a[50];
        printf("enter the name to delete:\n");
        scanf(" %[^\n]",a);

        st* new=*ptr,*temp1=*ptr,*last1;
        int count;
        count=0;
        while(new!=0)
	{
		if(strcmp(new->name,a)==0)
			count ++;
                        new=new->next;
        }
        if(count>1)
	{
		new=*ptr;
                while(new!=0)
		{
			if(strcmp(new->name,a)==0)
				printf("%d  %s %f\n",new->rollno,new->name,new->percentage);
                                new=new->next;
                 }
         }
        if(count>1)
		roll_delete(ptr);
        else
	{
                while(temp1!=0)
		{
                        if(strcmp(temp1->name,a)==0)
			{
                                if(strcmp((*ptr)->name,a)==0) 
					*ptr=(*ptr)->next;
                                else
					last1->next=temp1->next;
                        
				free(temp1);
				temp1=NULL;
				return;
                        }
                        else
			{
				last1=temp1;
				temp1=temp1->next;
                        }
               }
        }
    
       	printf("data doesn't exist to delete\n");
}


