#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "User.h"
void vViewYourRecord(int pos, List *l){
    List_Entry view;
    printf("Your data\n");
    Get_Element(pos,&view,l);
            printf("Name: %s\n", view.Name);
            printf("Password: %s\n", view.password);
            printf("Id: %d\n", view.ID);
            printf("Age: %f\n", view.age);
            printf("Gender: %c\n", view.gender);
            printf("Grades: %f\n", view.grade);

}

void Edit_student_name(int Entared_id,Student *STD,List *l){
        int new_name;
        char name[30];
            while(l->Head != NULL){

                printf("\nEnter the New Name: ");
                 fflush(stdin);
                fgets(STD->Name, 20, stdin);
                name[strcspn(STD->Name, "\n")] = '\0';
                Replace(Entared_id,STD,l);

                printf("_____________________\n");
				printf("\n              Name is updated succesfully               \n");
                printf("\n");
				printf("_____________________\n");
				printf("               Student InfO                            \n");
				printf("_____________________\n");
				printf("ID: "); printf("%d\n",STD->ID);
				printf("Password: "); printf("%s",STD->password);
				printf("Gender: "); printf("%c\n",STD->gender);
				printf("Age: "); printf("%.2f\n",STD->age);
				printf("Grade: "); printf("%.2f\n",STD->grade);
				printf("Name: "); printf("%s\n",STD->Name);
				printf("_____________________\n");
				break;}
}

void EditPassword(int ID, List* students) {
Node* current = students->Head;
int pos = 0;
while (current != NULL) {
if (current->value.ID == ID) {
 char new_password[20];
 printf("Enter new password: ");
scanf("%s", new_password);
strcpy(current->value.password, new_password);
printf("Password updated successfully!\n");
Replace(pos, &(current->value), students);
}
current = current->next;
pos++;
}
printf("Student with ID %d not found.\n", ID);
}
