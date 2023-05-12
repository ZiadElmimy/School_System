#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#define MAX 500
struct stude{
    char* name;
    int id;
    int age;
    char gender[10];
    int grade;
    char* password;
}stud[MAX];

void unique_id(int n);
void add_std(void);
void view_all_records(void);
#endif // PROJECT_H_INCLUDED
