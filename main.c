#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "list.h"

typedef struct Student_s
{
    char Name[12];
    int Age;
    struct list_head Head;
}Student_t;


int main(int argc,char** argv)
{
    Student_t std_Header;
    INIT_LIST_HEAD(&std_Header.Head);
    printf("pre  address =%p \n",std_Header.Head.prev);
    printf("next address =%p \n",std_Header.Head.next);    
    for (size_t index = 0; index < 999; index++)
    {
        Student_t *st=malloc(sizeof(Student_t));    
        
        sprintf(st->Name,"st-%03zd",index+1);
        st->Age=index+1;
        //list_add(&st->Head,&std_Header.Head);
        list_add_tail(&st->Head,&std_Header.Head);
    }
    struct list_head *pos;
    list_for_each(pos,&std_Header.Head)
    {
        Student_t *item=list_entry(pos,Student_t,Head);
        printf("Name = %s  Age  = %03d \n",item->Name,item->Age);        
    }
    return 0;
}