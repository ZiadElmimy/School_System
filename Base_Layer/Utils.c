#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
void create_list(List *l){
   l->Head=NULL;
   l->list_size=0;
}
int List_Empty(List *l){
    return (l->list_size==0);
}
int List_Full(List *l){
return 0;
}
void Traverse_List(List *l,void (*pf)(List_Entry)){
    Node *p=l->Head;
while(p){
        (*pf) (p->value);
         p=p->next;}

}

int Insert(int pos, List_Entry *element, List *l){
     Node *p, *q;
     int i;
   if( p=(Node *)malloc(sizeof(Node))){
     p->value=*element;
     p->next=NULL;
    //printf("THE VALUE SET\n");
     if(pos==0){
        p->next=l->Head;
        l->Head=p;
     }
     else{
        for(q=l->Head,i=0;i<pos-1;i++)
            q=q->next;

            p->next=q->next;
            q->next=p;

     }
  l->list_size++;
  return 1;
}
else return 0;
}

void Delete(int pos, List_Entry *element, List *l){
       int i;
       Node *q, *tmp;
        if(pos==0){
        *element=l->Head->value;
        tmp=l->Head->next;
        free(l->Head);
        l->Head=tmp;
        }
        else{
           for(q=l->Head,i=0;i<pos-1;i++)
            q=q->next;

            *element=q->next->value;
            tmp=q->next->next;
            free(q->next);
            q->next=tmp;
        }

   l->list_size--;
}


void Replace(int pos, List_Entry *element, List *l){
 int i;

    Node *q;
    for(q=l->Head,i=0;i<pos;i++)
        q=q->next;
    q->value=*element;

}

void Get_Element(int pos, List_Entry *element, List *l){
if (pos<0 || pos>= l->list_size){

    printf("invalid position\n");
}
Node *current=l->Head;
int current_pos=0;

while(current!=NULL && current_pos!= pos){

    current=current->next;
    current_pos++;
}
if (current== NULL){
    printf("element not found\n");
}
*element=current->value;
}




