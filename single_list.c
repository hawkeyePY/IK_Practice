#include <stdio.h>
#include <stdlib.h>
#define log(M, ...) fprintf(stderr, ""M"\n", ##__VA_ARGS__)
#define debug(M, ...) fprintf(stderr, "[DEBUG] %s:%s:%d: " M "\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)

typedef struct __node__
{
    int data;
    struct __node__ *next;
}Node;


Node *create_new(int data)
{
    Node *new = NULL;
    new = malloc(sizeof(Node));
    if(new)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

int insertAtFront(Node **head, int data)
{
    int val = 0;
    Node *new = NULL;
    new = create_new(data);
    if(new == NULL){
        val = -1;
    }
    if(*head==NULL){
         *head = new;
    } else {
        new->next = *head;
        *head = new;
    }
    return val;
}

int searchMylist(Node *head, int s_data)
{
    int rval=0;
    Node *temp;
    do
    {
        if(head==NULL) {
            log("Why am I breaking now?");
            rval=-1;
            break;

        }
        log("Data to search is %d",s_data);
        temp = head;
        while(temp){
            if(temp->data == s_data){
                log("Hurray you found me!");
            }
            temp = temp->next;
        }
    }while(0);
    return rval;
}

int insertAtBack(Node **head, int data)
{
    Node *new = NULL;
    new = create_new(data);
    if(new == NULL) {
        return -1;
    }
    if(*head==NULL){
        *head = new;
        return 0;
    }
    Node *temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;

    return 0;
}

Node * return_list(int num)
{
    int data = 0;
    Node *list = NULL;
    if (num==0)
        insertAtBack(&list,data);
    while(num)
    {
        data = num%10;
        num = num/10;
     //   insertAtFront(&list, data);
        insertAtBack(&list, data);
    }

    return list;
}


int print_list(Node *head)
{
    Node *temp = head;
    while (temp) {
        log("list contains %d", temp->data);
        temp = temp->next;
    }
    log("");
}

int reverse_list(Node *list)
{
    Node *cur=NULL, *prev=NULL, *next=NULL;
    cur = list;
    while(cur!=NULL){
        next        = cur->next;
        cur->next   = prev;
        prev        = cur;
        cur         = next;
    }
    list = prev;

    return 0;
}


Node *convert_numbers_to_list(int num1)
{
    Node *list1 = NULL;
    list1 = return_list(num1);
    return list1;
}

int list_len(Node *l)
{
    int len=0;
    while(l->next!=NULL){
        ++len;
        l = l->next;
    }
    return len+1;
}

int add_two_lists(Node *l1, Node *l2)
{
    int carry=0, res=0, len=0, a=0,b=0, choice=0;
    int carry_add=0;
    Node *temp_l1 = l1;
    Node *temp_l2 = l2;
    a = list_len(temp_l1);
    b = list_len(temp_l2);
    log("Len_a %d, Len_b %d", a, b);
    Node *result = NULL;
    if (a>b){
        while(a){
            int l1_data=0, l2_data=0;
            if(l1){
                l1_data = l1->data;
                if(l1->next !=NULL) {
                    l1 = l1->next;
                }
            } else {
                l1_data = 0;
            }
            if(l2){
                l2_data = l2->data;
                l2 = l2->next;
            } else {
                l2_data = 0;
            }

            res += l1_data + l2_data;
            if(res>=10){
                carry = res-10;
                log("carry is %d", carry);
                res = 1;
                insertAtBack(&result, carry);
            } else {
                log("adding res to list %d", res);
                insertAtBack(&result, res);
                res = 0;
            }
        a--;
        }
        if(res) {
            insertAtBack(&result, res);
        }
    } else if(b>a){
        while(b){
            int l1_data=0, l2_data=0;
            if(l1){
                l1_data = l1->data;
                    l1 = l1->next;
            } else {
                l1_data = 0;
            }
            if(l2){
                l2_data = l2->data;
                l2 = l2->next;
            } else {
                l2_data = 0;
            }

            res += l1_data + l2_data;
            if(res>=10){
                carry = res-10;
                log("carry is %d", carry);
                res = 1;
                insertAtBack(&result, carry);
            } else {
                log("adding res to list %d", res);
                insertAtBack(&result, res);
                res = 0;
            }
        b--;
        }
        if(res){
            insertAtBack(&result, res);
        }
    } else {
        while(b){
            int l1_data=0, l2_data=0;
            if(l1){
                l1_data = l1->data;
                    l1 = l1->next;
            } else {
                l1_data = 0;
            }
            if(l2){
                l2_data = l2->data;
                l2 = l2->next;
            } else {
                l2_data = 0;
            }

            res += l1_data + l2_data;
            if(res>=10){
                carry = res-10;
                log("carry is %d", carry);
                res = 1;
                insertAtBack(&result, carry);
            } else {
                log("adding res to list %d", res);
                insertAtBack(&result, res);
                res = 0;
            }
        b--;
        }
        if(res){
            insertAtBack(&result, res);
        }
    }
    print_list(result);


}


int main(int argc, char *argv[])
{
    int choice=0,data=0, s_data=0, num1=0, num2=0;
    Node *head = NULL;
    Node * list1=NULL, *list2=NULL;
    while(1){
    log("Enter your choice");
    log("1: Insert at front\n2:Insert at end\n3:Search\n4:Delete\n5:Add two numbers");
    scanf("%d",&choice);

        switch(choice){
            case 1:
                log("Please insert some data! You don't want your data to be zero :D");
                scanf("%d",&data);
                insertAtFront(&head,data);
                break;
            case 2:
                break;
            case 3:
                log("Let us search for the data!!");
                scanf("%d",&s_data);
                log("Am I Null %d",head->data);
                searchMylist(head, s_data);
                break;
            case 4:
                break;
            case 5:
                log("lets add two numbers, please type two numbers");
                scanf("%d %d",&num1, &num2);
                list1 = convert_numbers_to_list(num1);
                list2 = convert_numbers_to_list(num2);
                add_two_lists(list1,list2);
                break;
            case 6:
                exit(0);
                break;
            default:
                break;
    }
    }
    return 0;

}

