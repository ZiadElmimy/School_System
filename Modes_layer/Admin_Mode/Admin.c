
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "Admin.h"

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
            printf("Age: %f\n", current->value.age);
            printf("Gender: %c\n", current->value.gender);
            printf("Grades: %f\n", current->value.grade);

            printf("\n");
            pos++;
            current=current->next;
        }
    }
}
void vAddStudentRecord(int pos, List_Entry *element, List *l){

    printf("Enter student%d data\n", pos);

    printf("Name: ");
    scanf("\n");
    scanf("%[^\n]c", &element->Name);


    printf("Password: ");
    scanf(" %s", &element->password);


    printf("ID: ");
    scanf(" %d", &element->ID);


    printf("Age: ");
    scanf(" %f", &element->age);

    printf("Gender: ");
    scanf(" %c", &element->gender);

    printf("Grades: ");
    scanf(" %f", &element->grade);
    printf("\n");
    Insert(pos, element, l);


}
void EditAdminPassword(List* list) {
    if (list->Head == NULL) {
        printf("No admin record found.\n");
        return;
    }

    char newPassword[20];
    int attempts = 3;

    while (attempts > 0) {
        char enteredPassword[20];
        printf("Enter the current admin password: ");
        scanf("%s", enteredPassword);

        if (strcmp(enteredPassword, list->Head->value.password) == 0) {
            printf("correct Password\nEnter the new admin password: ");
            scanf("%s", newPassword);

            strncpy(list->Head->value.password, newPassword, sizeof(list->Head->value.password) );
            list->Head->value.password[sizeof(list->Head->value.password)] = NULL;

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

void RemoveStudentRecord(int ID, List* Students) {
    Node* current = Students->Head;
    Node* old = NULL;
    int pos = 0;

    while (current != NULL) {
        if (current->value.ID == ID) {
            List_Entry removedStudent;
            Delete(pos, &removedStudent, Students);
            printf("Student record removed successfully.\n");
            printf("Name: %s\n", removedStudent.Name);
            printf("ID: %d\n", removedStudent.ID);
            return;
        }
        old = current;
        current = current->next;
        pos++;
    }


    printf("Student with ID %d does not exist.\n", ID);
}
void View_student_record(int Entared_id,Student *STD,List *l){

                while(l->Head != NULL){
                printf("_____________________\n");
				printf("The record of the student..\n");
                printf("_____________________\n");
				printf(" ID: ");
                printf("%d\n",STD->ID);
                printf(" password: ");
                printf("%s",STD->password);
                printf(" age: ");
                printf("%.2f\n",STD->age);
                printf(" grade: ");
                printf("%.2f\n",STD->grade);
                printf(" gender: ");
                printf("%c\n",STD->gender);
                printf(" name: ");
                printf("%s\n",STD->Name);
                printf("_____________________\n");
                break;
				}

}

void Edit_student_grade(int Entared_id,Student *STD,List *l){

              int new_grade;
               while(l->Head != NULL){
               printf("\nNote: The student grade should be between 0 to 100.\n");
               printf("\nEnter the New Grade: ");
               scanf("%d",&new_grade);
               if(new_grade>=0 && new_grade<=100){
               STD->grade = new_grade;
                Replace(Entared_id,STD,l);

                printf("_____________________\n");
                printf("\n              Grade is updated succesfully               \n");
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
				break;
				}
				else {
                        printf("\n*Invalid Grade*\n");}
                 printf("_____________________\n");
				break;}}
