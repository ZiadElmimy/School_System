#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
void vViewAllRecords(List *l);
void vAddStudentRecord(int pos, List_Entry *element, List *l);
void EditAdminPassword(List* list);
void RemoveStudentRecord(int ID, List* Students);
void View_student_record(int Entared_id,Student *STD,List *l);
void Edit_student_grade(int Entared_id,Student *STD,List *l);
#endif
