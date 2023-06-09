#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "User.h"

extern Student s;
extern List l;
extern LIST L;
/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit_student_name			                                                               |
Parameters: it take three parameters ( ID , pointer to struct , pointer to List ).             |
Return: it returns no thing.                                                                   |
Usage: it is used to Edit student name by student.                                             |
                                                                                               |
------------------------------------------------------------------------------------------------
*/
void Edit_student_name(int Entared_id,Student *STD,List *l){
        int new_name;
        char name[30];
            while(l->Head != NULL){

                printf("\nEnter the New Name: ");
                 fflush(stdin);
                fgets(STD->Name, 20, stdin);
                name[strcspn(STD->Name, "\n")] = '\0';
                Replace(Entared_id,STD,l);

                printf("_________________________________________________\n");

				printf("\n              *Name is updated succesfully*              \n");
                printf("\n");
				printf("_________________________________________________\n");

				printf("               Student InfO                            \n");
			     printf("_________________________________________________\n");

				printf("ID: "); printf("%d\n",STD->ID);
				printf("Password: "); printf("%s\n",STD->password);
				printf("Gender: "); printf("%c\n",STD->gender);
				printf("Age: "); printf("%.2f\n",STD->age);
				printf("Grade: "); printf("%.2f\n",STD->grade);
				printf("Name: "); printf("%s\n",STD->Name);
				printf("_________________________________________________\n");
				break;}
}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: vViewYourRecord			                                                               |
Parameters: it take two parameters (ID , pointer to List).                                     |
Return: it returns no thing.                                                                   |
Usage: it is used to view student record by student.                                           |
                                                                                               |
------------------------------------------------------------------------------------------------
*/
void vViewYourRecord(int pos, List *l){
    List_Entry view;
    printf("Your data\n");
    printf("___________________________\n");
    Get_Element(pos,&view,l);
            printf("Name: %s\n", view.Name);
            printf("Password: %s\n", view.password);
            printf("Id: %d\n", view.ID);
            printf("Age: %.2f\n", view.age);
            printf("Gender: %c\n", view.gender);
            printf("Grades: %.2f\n", view.grade);
            printf("___________________________\n");

}
/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit_student_pass			                                                               |
Parameters: it take three parameters (ID ,pointer to student struct, pointer to List).         |
Return: it returns no thing.                                                                   |
Usage: it is used to Edit student password by student.                                         |
                                                                                               |
------------------------------------------------------------------------------------------------
*/
      void Edit_student_pass(int Entared_id,Student *STD,List *l){
      char newPassword[20];
      printf("Enter the new Student password: ");
            scanf("%s", &newPassword);
    strcpy(STD->password, newPassword);
    printf("Student password updated successfully\n");
     Replace(Entared_id,STD,l);
                printf("_________________________________________________\n\n");
				printf("               Student InfO                            \n");
                printf("_________________________________________________\n");
				printf("ID: "); printf("%d\n",STD->ID);
				printf("Password: "); printf("%s\n",STD->password);
				printf("Gender: "); printf("%c\n",STD->gender);
				printf("Age: "); printf("%.2f\n",STD->age);
				printf("Grade: "); printf("%.2f\n",STD->grade);
				printf("Name: "); printf("%s\n",STD->Name);
				  printf("_________________________________________________\n");;
}

void Student_Mode(int Entered_ID)
{
    int order;

	printf("\n\n");
	printf("___________________________________________________________\n");
	printf("View Your Record.            >>>                     Enter1\n");
	printf("Edit Your Password.          >>>                     Enter2\n");
	printf("Edit Your Name.              >>>                     Enter3\n");
    printf("Return to main screen.       >>>                     Enter4\n");
    printf("___________________________________________________________\n");

	printf("\nYour choice: ");
	scanf("%d",&order);
	printf("\n");

	switch(order)
	{
		case 1:
        printf("                  View Your Record                       \n");
		printf("\n");

        Get_Element(Entered_ID,&s,&l);
        vViewYourRecord(Entered_ID, &l);
        Student_Mode(Entered_ID);
		break;

		case 2:
        printf("                  Edit Your Password                     \n");
        printf("\n");
        Get_Element( Entered_ID,&s,&l);

        Edit_student_pass( Entered_ID,&s,&l);
        Student_Mode(Entered_ID);
		break;

		case 3:
		printf("                  Edit Your Name                         \n");
        printf("\n");
        Get_Element( Entered_ID,&s,&l);
        Edit_student_name(Entered_ID,&s,&l);
        Student_Mode(Entered_ID);

		break;

        case 4:
            Start_Program();
		default:
		printf("                You Entered Wrong Choice                   \n");
		printf("\n");
		Student_Mode(Entered_ID);
	}
}
