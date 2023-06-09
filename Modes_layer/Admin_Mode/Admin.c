
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Admin.h"
extern Student s;
extern List l;
extern LIST L;
void Create_list_Admin(LIST *l){
   l->head=NULL;
   l->Size=0;
}
int list_Empty(LIST *l){
    return (l->Size==0);
}
int list_Full(LIST *l){
return 0;
}
void Get_Admin(int pos, Entry *element, LIST *l){
if (pos<0 && pos>= l->Size){

    printf("invalid position\n");
}
nodeAdmin *current=l->head;
int current_pos=0;

while(current!=NULL && current_pos!= pos){

    current=current->Next;
    current_pos++;
}
if (current== NULL){
    printf("element not found\n");
}
*element=current->Value;
}

int Insert_admin(int pos,Entry  *element, LIST *l){
     nodeAdmin *p, *q;
     int i;
   if( p=(nodeAdmin *)malloc(sizeof(nodeAdmin))){
     p->Value =*element;
     p->Next=NULL;
     if(pos==0){
        p->Next=l->head;
        l->head=p;
     }
     else{
        for(q=l->head,i=0;i<pos-1;i++)
            q=q->Next;

            p->Next=q->Next;
            q->Next=p;

     }
  l->Size++;
  return 1;
}
else return 0;
}
void add_admin( LIST *L,Admin *_admin)
{
	//Admin1

	_admin->adminID =0;
	strcpy(_admin->adminName,"admin1");
    strcpy(_admin->adminPassword,"1234");
	Insert_admin(0,_admin,L);


}

/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: vViewAllRecords			                                                               |
Parameters: it take one parameters ( pointer to List ).                                        |
Return: it returns no thing.                                                                   |
Usage: it is used to view all student records by an admin.                                     |
                                                                                               |
------------------------------------------------------------------------------------------------
*/
void vViewAllRecords(List *l){
    Node *current=l->Head;
    if(current==NULL) printf("List is empty");
    else{
        int pos=0;
        while(current != NULL){
            printf("Student%d data\n",pos);
            printf("Name: %s\n", current->value.Name);
            printf("Password: %s\n", current->value.password);
            printf("ID: %d\n", current->value.ID);
            printf("Age: %.2f\n", current->value.age);
            printf("Gender: %c\n", current->value.gender);
            printf("Grades: %.2f\n", current->value.grade);

            printf("\n");
            pos++;
            current=current->next;
        }
    }
}


/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: vAddStudentRecord			                                                               |
Parameters: it take two parameters (pointer to struct , pointer to List).                      |
Return: it returns no thing.                                                                   |
Usage: it is used to add student record by an admin.                                           |
                                                                                               |
------------------------------------------------------------------------------------------------
*/

void vAddStudentRecord(List_Entry *element, List *l){
    int Entered_ID;
    printf("Enter student data\n");
    printf("Enter ID: ");
    scanf("%d",&Entered_ID);
    element->ID = Entered_ID;
    printf("Name: ");
    scanf("\n");
    scanf("%[^\n]c", &element->Name);
    printf("Password: ");
    scanf(" %s", &element->password);
    printf("Age: ");
    scanf(" %f", &element->age);
    printf("Gender: ");
    scanf(" %c", &element->gender);
    printf("Note: The student grade should be between 0 to 100.\n");
    printf("Grades: ");
    scanf(" %f", &element->grade);
    printf("\n");
     if(element->grade>=0 && element->grade<=100){
    Insert(Entered_ID, element, l);

    printf("           *This record is added successfully*           \n");
    printf("_________________________________________________\n");
    }

    else{
    printf("        *Invalid Grade*         ");
    printf("_________________________________________________\n");
    }}



/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name:  EditAdminPassword			                                                           |
Parameters: it take one parameters (pointer to List).                                          |
Return: it returns no thing.                                                                   |
Usage: it is used to edit admin password by an admin.                                          |
                                                                                               |
------------------------------------------------------------------------------------------------
*/
void EditAdminPassword(LIST* LIST) {
    if (LIST->head== NULL) {
        printf("No admin record found.\n");
        return;
    }

    char newPassword[20];
    int attempts = 3;

    while (attempts > 0) {
        char enteredPassword[20];
        printf("Enter the current admin password: ");
        scanf("%s", enteredPassword);

        if (strcmp(enteredPassword, LIST->head->Value.adminPassword) == 0) {
            printf("correct Password\nEnter the new admin password: ");
            scanf("%s", newPassword);

            strncpy(LIST->head->Value.adminPassword, newPassword, sizeof(LIST->head->Value.adminPassword) );
            LIST->head->Value.adminPassword[sizeof(LIST->head->Value.adminPassword)] = NULL;

            printf("Admin password updated successfully\n");
            return;
        }
        else {
            attempts--;
            printf("wrong password\n%d attempts remaining.\n", attempts);
        }
    }

    printf("sorry;You have reached the maximum number of attempts\nPassword cannot be changed;please try again later\n");
}
/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: View_student_record			                                                           |
Parameters: it take three parameters ( ID , pointer to struct , pointer to List ).             |
Return: it returns no thing.                                                                   |
Usage: it is used to  View student record by an admin.                                         |
------------------------------------------------------------------------------------------------
*/


void View_student_record(int Entared_id,Student *STD,List *l){

                while(l->Head != NULL){
                printf("_________________________________\n\n");
				printf("The record of the student..\n");
                printf("_________________________________\n");
				printf(" ID: ");
                printf("%d\n",STD->ID);
                printf(" password: ");
                printf("%s\n",STD->password);
                printf(" age: ");
                printf("%.2f\n",STD->age);
                printf(" grade: ");
                printf("%.2f\n",STD->grade);
                printf(" gender: ");
                printf("%c\n",STD->gender);
                printf(" name: ");
                printf("%s\n",STD->Name);
                printf("_________________________________\n");
                break;
				}

}
/*
------------------------------------------------------------------------------------------------
									Function Definition		                	    		   |
------------------------------------------------------------------------------------------------
Name: Edit_student_grade			                                                           |
Parameters: it take three parameters ( ID , pointer to struct , pointer to List ).             |
Return: it returns no thing.                                                                   |
Usage: it is used to Edit student grade by an admin.                                           |
                                                                                               |
------------------------------------------------------------------------------------------------
*/

void Edit_student_grade(int Entared_id,Student *STD,List *l){

              int new_grade;
               while(l->Head != NULL){
               printf("\nNote: The student grade should be between 0 to 100.\n");
               printf("\nEnter the New Grade: ");
               scanf("%d",&new_grade);
               if(new_grade>=0 && new_grade<=100){
               STD->grade = new_grade;
                Replace(Entared_id,STD,l);
                printf("_________________________________________________\n");
                printf("\n              *Grade is updated succesfully*               \n");
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
				break;
				}
				else {
                        printf("\n*Invalid Grade*\n");}
                printf("_________________________________________________\n");
				break;}}
void RemoveStudentRecord(void) {

    printf("This record deleted successfully ");

}

void Admin_Mode()
{
	int order;
	int Entered_ID;

	printf("\n\n");

	printf("_________________________________________________\n");
	printf("Add Student Record              >>>        Enter1\n");
	printf("View Student Record             >>>        Enter2\n");
	printf("Edit Student Grade              >>>        Enter3\n");
    printf("Remove student record           >>>        Enter4\n");
    printf("Edit admin password             >>>        Enter5\n");
    printf("View All Student Record         >>>        Enter6\n");
    printf("Return to main screen           >>>        Enter7\n");
	printf("_________________________________________________\n");

	printf("\nYour choice: ");
	scanf("%d",&order);
	printf("\n");

	switch(order)
	{
		case 1:
		printf("                  Add Student Record                     \n");

        vAddStudentRecord(&s, &l);

        Admin_Mode();
		break;

       case 2:

		printf("                  View Student Record                    \n");
		printf("\n");
		printf("Enter ID: ");
		scanf("%d",&Entered_ID);
		Get_Element( Entered_ID,&s,&l);
		View_student_record(Entered_ID,&s,&l);
        Admin_Mode();
		break;
		case 3:
		printf("                  Edit Student Grade                     \n");
		printf("\n");
		printf("Enter Student ID: ");
		scanf("%d",&Entered_ID);
		Get_Element( Entered_ID,&s,&l);
		Edit_student_grade(Entered_ID,&s,&l);
		Admin_Mode();
		break;
        case 4:
        printf("Enter Student ID: ");
		scanf("%d",&Entered_ID);
		Get_Element( Entered_ID,&s,&l);
		Delete( Entered_ID,&s,&l);
        RemoveStudentRecord();
        printf("%d",l.list_size);
        Admin_Mode();

        break;
        case 5:
        printf("Enter admin id:");
        scanf("%d", &Entered_ID);
        EditAdminPassword(&L);
        Admin_Mode();
        break;
        case 6:
        vViewAllRecords(&l);
        Admin_Mode();
        break;
        case 7:
        Start_Program();
        break;
		default:
        printf(" __________________________________________\n");
		printf("                 Invalid Choice                  \n");
		printf(" __________________________________________\n");
		printf("\n");
		Admin_Mode();

	}

}

