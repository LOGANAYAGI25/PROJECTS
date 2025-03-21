#include "header.c"

void student_exit(st *ptr)
{
        char ch;
	printf("\n");
        printf("\t\t|----------------------------------------|\n");
        printf("\t\t|Enter                                   |\n");
        printf("\t\t|S/s:save and exit                       |\n");
        printf("\t\t|E/e:exit without saving                 |\n");
        printf("\t\t|________________________________________|\n");

        printf("Enter your option:");
        scanf(" %c",&ch);

        if(ch=='S'||ch=='s')
        {
                student_save(ptr);
        }
        else if(ch=='E'||ch=='e')
        {

                printf("Exiting without saving changes.\n");
                exit(0);
        }
        else
        {
                printf("Invalid choice.\n");

        }
}

