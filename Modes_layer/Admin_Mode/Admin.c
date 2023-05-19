
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
