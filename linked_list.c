#include "debug.h"
#include "linked_list.h"

#define OK 1
#define NOT_OK 0

int create_new_node(Llist *node)
{
    node = malloc(sizeof(Llist));
    if(node!=NULL){
        return OK;
    } else {
        return NOT_OK;
    }
}

int insert_at_front(Llist *head, int data)
{
    int val;
    Llist *node = NULL;
        
    if(head == NULL) {
        

    }
    return val;
}
