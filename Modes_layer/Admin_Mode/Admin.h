#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
typedef struct admin
{
    char *adminName[30]; char *adminPassword[20];
    int adminID;
}Admin;
typedef  Admin Entry;
typedef struct Node_Admin{
    Entry Value;
    struct Node_Admin *Next;
}nodeAdmin;

typedef struct{
    nodeAdmin *head;
    int Size;
}LIST;

void vViewAllRecords(List *l);
void vAddStudentRecord(int pos, List_Entry *element, List *l);
void EditAdminPassword(List* list);
void RemoveStudentRecord(int ID, List* Students);
void View_student_record(int Entared_id,Student *STD,List *l);
void Edit_student_grade(int Entared_id,Student *STD,List *l);
void Create_list_Admin(LIST *l);
int list_Empty(LIST *l);
int list_Full(LIST *l);
void Get_Admin(int pos, Entry *element, LIST *l);
void add_admin( LIST *L,Admin *_admin);
void Admin_Mode();

#endif
