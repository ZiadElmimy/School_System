#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_viewall.h"

int i=0;

void unique_id(int n){ //n=i
    for(int k=n;k<MAX;k++){
        for(int j=n-1;j>=0;j--){
            if(stud[n].id==stud[j].id){
            printf("This ID already exists. please Enter another ID: ");
            scanf("%d", &stud[i].id);
            if(stud[i].id==stud[j].id) unique_id(i);
            }
        }
    }
}

void add_std(){
    printf("Enter student%d data\n", i+1);

    printf("Name: ");
    char newName[100];
    scanf("\n");
    gets(newName);
    stud[i].name=(char*)malloc(strlen(newName)+1);
    strcpy(stud[i].name, newName);

    printf("Password: ");
    char newPass[100];
    gets(newPass);
    stud[i].password=(char*)malloc(strlen(newPass)+1);
    strcpy(stud[i].password, newPass);

    printf("ID: ");
    scanf("%d", &stud[i].id);
    if(i!=0){
        //int n=i;
        unique_id(i);
    }

    printf("Age: ");
    scanf("%d", &stud[i].age);

    printf("Gender: ");
    scanf("%s", stud[i].gender);

    printf("Grades: ");
    scanf("%d", &stud[i].grade);
    printf("\n");
i++;
}
void view_all_records(){
    for(int x=0;x<MAX;x++){
        if(i==x) break;
        printf("Student%d data\n", x+1);
        printf("Name: %s\n", stud[x].name);
        printf("Password: %s\n", stud[x].password);
        printf("Id: %d\n", stud[x].id);
        printf("Age: %d\n", stud[x].age);
        printf("Gender: %s\n", stud[x].gender);
        printf("Grades: %d\n", stud[x].grade);
        printf("\n");
    }
}
