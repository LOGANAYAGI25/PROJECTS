#include "header.c"

void reverse_list(st *ptr)
{/*
        int i,j,c=count(ptr);
        int size=sizeof(st)-sizeof(st*);
        st **p=(st**)malloc(c*sizeof(st*));
        st temp;

        for(i=0;i<c;i++)
        {
                p[i]=ptr;
                ptr=ptr->next;
        }
        for(i=0,j=c-1;i<j;i++,j--)
        {
                memcpy(&temp,p[i],size);
                memcpy(p[i],p[j],size);
                memcpy(p[j],&temp,size);
        }*/

	if(ptr==0)
		return;
	reverse_list(ptr->next);
	printf("%d  %s  %f\n",ptr->rollno,ptr->name,ptr->percentage);

}

