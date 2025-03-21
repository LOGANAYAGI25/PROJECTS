#include "header.c"
int roll=0;

int main()
{
        st *hptr=0;
        char op,ch;

                //display_menu();
                while(1)
                {
                printf("\t\t|---------------------------------------------|\n");
                printf("\t\t|   **********STUDENT RECORD MENU**********   |\n");
                printf("\t\t|---------------------------------------------|\n");
                printf("\t\t| a/A :add new record                         |\n");
                printf("\t\t| d/D :delete a record                        |\n");
                printf("\t\t| s/S :show the list                          |\n");
                printf("\t\t| m/M :modify the record                      |\n");
                printf("\t\t| v/V :save                                   |\n");
                printf("\t\t| e/E :exit                                   |\n");
                printf("\t\t| t/T :sort the list                          |\n");
                printf("\t\t| l/L :delete all the records                 |\n");
                printf("\t\t| r/R :reverse the list                       |\n");
                printf("\t\t|_____________________________________________|\n");

                printf("Enter your choice: ");
                scanf(" %c",&ch);
                switch(ch)
                         {
                            case 'a':  case 'A':student_addmiddle(&hptr);break;
                            case 'd':  case 'D':student_delete(&hptr);break;
                            case 's':  case 'S':student_show(hptr);break;
                            case 'm':  case 'M':student_modification(hptr);break;
                            case 'v':  case 'V':student_save(hptr);break;
                            case 'e':  case 'E':student_exit(hptr);break;
                            case 't':  case 'T':sort_list(hptr);break;
                            case 'r':  case 'R':reverse_list(hptr);break;
                            case 'l':  case 'L':delete_all(&hptr);break;
                            default:printf("Invalid operator\n");
                                return 0;
                        }
              }
}

