#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#define Max 100
typedef struct
{
    char* name;
    int ID, pass;
    float age, grade;
    char gender;
}Student;

Student student[Max];

void add_student(Student s);

#endif // PROJECT_H_INCLUDED
