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

