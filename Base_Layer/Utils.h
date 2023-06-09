#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
typedef struct{
    char Name[30];
    char password[20];
    int ID;
    float grade, age;
    char gender;
}Student;

typedef Student List_Entry;
typedef struct node{
    List_Entry value;
    struct node *next;
}Node;

typedef struct{
    Node *Head;
    int list_size;
}List;



void create_list(List *l);
int Insert(int pos, List_Entry *element, List *l);
void Delete(int pos, List_Entry *element, List *l);
int List_Full(List *l);
int List_Empty(List *l);
void Replace(int pos, List_Entry *element, List *l);
void Get_Element(int pos, List_Entry *element, List *l);
void Traverse_List(List *l,void (*pf)(List_Entry));
int Check_Password(char *password);
void Login(void);
void Start_Program();
#endif
