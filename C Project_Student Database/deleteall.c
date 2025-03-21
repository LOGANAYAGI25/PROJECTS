#include "header.c"

void delete_all(st **ptr)
{
        st *temp=*ptr;
        while((*ptr)!=0)
        {
                (*ptr)=temp->next;
                free(temp);
                temp=(*ptr);
        }
	printf("All nodes deleted successfully.\n");
}

