#include "header.c"

void student_modification(st *ptr)
{

	char op;
        printf("\t\t|--------------------------------------------------|\n");
        printf("\t\t| Enter which record to search for modification    |\n");
        printf("\t\t| R/r :to search a rollno                          |\n");
        printf("\t\t| N/n :to search a name                            |\n");
        printf("\t\t| P/p :percentage based                            |\n");
        printf("\t\t|__________________________________________________|\n");

        printf("Enter your choice: ");
	scanf(" %c",&op);

        if(ptr==NULL)
	{
		printf("There is no data to modify\n");
		return ;
        }

	if(op=='r'||op=='R')
		roll_modify(ptr);

	else if(op=='N'||op=='n')
		n_modify(ptr);

        else if(op=='P'||op=='p')
		p_modify(ptr);
             
	else
		printf("invalid option to student modify\n");
	return ;
}


void roll_modify(st *ptr)
{
        int a,x;
        printf("enter the roll no to search to modify the data\n");
        scanf("%d",&x);

        st *temp=ptr;
        while(temp!=0)
	{
        
		if((temp->rollno)==x)
		{
			printf("rollno exist\n%d  %s  %f\n",temp->rollno,temp->name,temp->percentage);

			break;
                }
        
		else
			temp=temp->next;
	}
        if(temp==0)
	{
                printf("data doesn't exist to modify\n");
                return ;
	}

	printf("Enter 1-modify name,\nEnter 2-modify percentage and \nEnter 3-modify both name and percentage.\nEnter your option:\n");
	scanf("%d",&a);
	printf("%d  %s  %f\n",temp->rollno,temp->name,temp->percentage);

	switch(a)
	{
		case 1:roll_name_modify(ptr,x);break;
		case 2:roll_percentage_modify(ptr,x);break;
		case 3:roll_name_percentage_modify(ptr,x);break;
		default:printf("invalid option to modify based on rollno menu\n");return;
        }
}

void roll_name_modify(st *ptr,int n)
{
        st* p=ptr;

        char a[50];
        printf("enter the new name\n");
        scanf(" %[^\n]",a);

        while(p!=0)
	{
            if(p->rollno==n)
	    {
                    strcpy(p->name,a);
                    return;
            }
            else
                    p=p->next;
        }
}

void roll_percentage_modify(st*ptr,int n)
{
        st* p=ptr;
        float y;
        printf("enter the new percentage\n");
        scanf("%f",&y);

        while(p!=0)
	{
            if(p->rollno==n)
	    {
                    p->percentage=y;
                    return;
            }
            else
                    p=p->next;
        }
}

void roll_name_percentage_modify(st *ptr,int n)
{

        st* p=ptr;
        char a[50];float y;
        printf("enter the new name and percentage\n");
        scanf("%s%f",a,&y);

	while(p!=0)
	{
            if(p->rollno==n)
	    {
                   strcpy( p->name,a);
                    p->percentage=y;
                    return;
            }
            else
                    p=p->next;
        }
}

void n_modify(st *ptr)
{
        int a;
	char x[50];
        printf("enter the name to search to modify the data\n");
        scanf("%s",x);

        st *temp=ptr;
        while(temp!=0)
        {
                if (strcmp(temp->name, x) == 0)
                {
                        printf("name exist\n%d  %s  %f\n",temp->rollno,temp->name,temp->percentage);
                        break;
                }
                else
                        temp=temp->next;
        }
        if(temp==0)
        {
                printf("data doesn't exist to modify\n");
                return ;
        }

        printf("Enter 1-modify name,\nEnter 2-modify percentage and \nEnter 3-modify both name and percentage.\nEnter your option:\n");
        scanf("%d",&a);
        printf("%d  %s  %f\n",temp->rollno,temp->name,temp->percentage);

        switch(a)
        {
                case 1:name_modify(ptr,x);break;
                case 2:n_percentage_modify(ptr,x);break;
                case 3:name_percentage_modify(ptr,x);break;
                default:printf("invalid option to modify based on name\n");return;
        }
}


void name_modify(st *ptr, char *old_name)
{
    st *temp = ptr;
    st *new = ptr;
    char new_name[50];
    int count = 0;
    int roll_no = 0;

    printf("Enter the new name: ");
    scanf(" %[^\n]", new_name);

    while (new != NULL)
    {
        if (strcmp(new->name, old_name) == 0)
        {
            count++;
        }
        new = new->next;
    }

    if (count >= 1)
    {
        new = ptr;
        while (new != NULL)
        {
            if (strcmp(new->name, old_name) == 0)
            {
                printf("%d  %s  %f\n", new->rollno, new->name, new->percentage);
            }
            new = new->next;
        }

        printf("Enter the roll number of the student to modify: ");
        scanf("%d", &roll_no);

     
        temp = ptr;
        while (temp != NULL)
        {
            if (temp->rollno == roll_no)
            {
                strcpy(temp->name, new_name);
                printf("Name updated for roll number %d.\n", roll_no);
                return;
            }
            temp = temp->next;
        }
        printf("Record not found.\n");
    }
    else 
    {
        temp = ptr;
        while (temp != NULL)
        {
            if (strcmp(temp->name, old_name) == 0)
            {
                strcpy(temp->name, new_name);
                printf("Name updated.\n");
                return;
            }
            temp = temp->next;
        }
    }
    printf("Record not found.\n");
}


void n_percentage_modify(st *ptr, char *name)
{
    float new_percentage;
    printf("Enter new percentage: ");
    scanf("%f", &new_percentage);

    st *temp = ptr;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            temp->percentage = new_percentage;
            printf("Percentage updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}
void name_percentage_modify(st *ptr, char *name) {
    char new_name[50];
    float new_percentage;

    printf("Enter new name: ");
    scanf(" %[^\n]", new_name);
    printf("Enter new percentage: ");
    scanf("%f", &new_percentage);

    st *temp = ptr;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            strcpy(temp->name, new_name);
            temp->percentage = new_percentage;
            printf("Name and percentage updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}
void p_modify(st *ptr)
{
    int option;
    float search_percentage;
    printf("Enter the percentage to search for modification: ");
    scanf("%f", &search_percentage);

    st *temp = ptr;
    while (temp != NULL)
    {
        if (temp->percentage == search_percentage)
        {
            printf("%d  %s  %f\n", temp->rollno, temp->name, temp->percentage);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("No student found with percentage %.2f.\n", search_percentage);
        return;
    }

    printf("Enter 1 to modify name,\n");
    printf("Enter 2 to modify percentage,\n");
    printf("Enter 3 to modify both name and percentage.\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            p_name_modify(ptr, search_percentage);
            break;
        case 2:
            percentage_modify(ptr, search_percentage);
            break;
        case 3:
            p_name_percentage_modify(ptr, search_percentage);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
}

void p_name_modify(st *ptr, float search_percentage)
{
    char new_name[50];
    st *temp = ptr;

    while (temp != NULL)
    {
        if (temp->percentage == search_percentage)
        {
            printf("%d  %s  %f\n", temp->rollno, temp->name, temp->percentage);
            printf("Enter new name: ");
            scanf(" %[^\n]", new_name); 
            strcpy(temp->name, new_name);
            printf("Name updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("No student found with percentage %.2f.\n", search_percentage);
}


void percentage_modify(st *ptr, float search_percentage)
{
    float new_percentage;
    st *temp = ptr;

    while (temp != NULL)
    {
        if (temp->percentage == search_percentage)
        {
            printf("%d  %s  %f\n", temp->rollno, temp->name, temp->percentage);
            printf("Enter new percentage: ");
            scanf("%f", &new_percentage);
            temp->percentage = new_percentage;
            printf("Percentage updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("No student found with percentage %.2f.\n", search_percentage);
}


void p_name_percentage_modify(st *ptr, float search_percentage)
{
    char new_name[50];
    float new_percentage;
    st *temp = ptr;

    while (temp != NULL)
    {
        if (temp->percentage == search_percentage)
        {
            printf("%d  %s  %f\n", temp->rollno, temp->name, temp->percentage);
            printf("Enter new name: ");
            scanf(" %[^\n]", new_name); 
            printf("Enter new percentage: ");
            scanf("%f", &new_percentage);
            strcpy(temp->name, new_name);
            temp->percentage = new_percentage;
            printf("Both name and percentage updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("No student found with percentage %.2f.\n", search_percentage);
}
