#include "header.c"

int  count(st *ptr)
{
        int c=0;
        while(ptr!=0)
        {
                c++;
                ptr=ptr->next;
        }
        return c;
}

