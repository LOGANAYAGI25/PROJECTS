#include "header.c"

void sort_list(st *ptr)
{
    printf("\t\t|----------------------------------------|\n");
    printf("\t\t|Enter                                   |\n");
    printf("\t\t|N/n: sort with name                     |\n");
    printf("\t\t|P/p: sort with percentage               |\n");
    printf("\t\t|________________________________________|\n");

    int i, j, c = count(ptr);
    int size = sizeof(st) - sizeof(st*);

    st **p = (st **)malloc(c * sizeof(st *));
    st temp;
    st *temp1=ptr;
    for (i = 0; i < c; i++)
    {
        p[i] = temp1;
        temp1 = temp1->next;
    }

    char ch;
    printf("Enter your option ");
    scanf(" %c", &ch);

    if (ch == 'n' || ch == 'N')
    {
	for (i = 0; i < c - 1; i++)
        {
            for (j = i + 1; j < c; j++)
            {
                int nameComparison = strcmp(p[i]->name, p[j]->name);
                if (nameComparison > 0)
                {
                    memcpy(&temp, p[i], size);
                    memcpy(p[i], p[j], size);
                    memcpy(p[j], &temp, size);
                }
            }
        }
		student_show(ptr);
    }

  else if (ch == 'p' || ch == 'P')
    {
    for (i = 0; i < c - 1; i++)
    {
        for (j = i + 1; j < c; j++)
        {
            int percentageComparison = 0;
            if (p[i]->percentage < p[j]->percentage)
            {
                percentageComparison = -1;
            }
            else if (p[i]->percentage > p[j]->percentage)
            {
                percentageComparison = 1;
            }

            if (percentageComparison > 0)
            {
                memcpy(&temp, p[i], size);
                memcpy(p[i], p[j], size);
                memcpy(p[j], &temp, size);
            }
        }
    }
    student_show(ptr);
    }

    else
    {
        printf("Invalid input! Sorting by name by default.\n");
        for (i = 0; i < c - 1; i++)
        {
            for (j = i + 1; j < c; j++)
            {
                int nameComparison = strcmp(p[i]->name, p[j]->name);
                if (nameComparison > 0)
                {
                    memcpy(&temp, p[i], size);
                    memcpy(p[i], p[j], size);
                    memcpy(p[j], &temp, size);
                }
            }
        }
    }
}

