#ifndef LIST_H
#define LIST_H

#include <vector>
#include <unordered_map>

using namespace std;
typedef struct __node__ {
    int data;
    struct __node__ *next;
} Node;


class List
{
    private:
        Node *head;
    public:
        List()  {
            head = NULL;
        } 

        Node *gethead() {
            return head;
        }

        Node *createNew(int val) {
            Node *newNode = new Node;
            Node *temp = head;
            newNode->data = val;
            newNode->next = NULL;
            return newNode;
        }

        void insert_end(int val) {
            Node *newNode = createNew(val);
            
            if(head == NULL) {
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            return;
        }

        void insert_beg(int val) { 
            Node *newNode = createNew(val);
	        if(head == NULL) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }
        void removeNode(int val) {
            Node *temp = head;
            Node *prev = NULL;
            if(temp == NULL && temp->data == val) {
                head = temp->next;
                delete(temp);
                return;
            } 
            while(temp!=NULL && temp->data !=val) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete(temp);
            return;

        }
        void display(Node *head) {
            Node *temp = head;
            while(temp!=NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        void reverseList()
        {
            Node *cur = head;
            Node *next = NULL, *prev = NULL;
            if(cur ==NULL || cur->next == NULL) {
                return;
            }
            
            while(cur!=NULL) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            head = prev;
        }

        Node *removeAllElements(int val)
        {
            Node *temp = head;
            Node *prev = NULL;
            if(temp == NULL || temp->data == val) {
                head = temp->next;
                delete(temp);
            }
            temp = head;
            while(temp!=NULL) {
                if(temp->data == val && prev == NULL) {
                    Node *cur = temp;
                    temp = temp->next;
                    delete(cur);
                    head = temp;
                } else if( temp->data == val && prev != NULL) {
                    Node *cur = temp;
                    prev->next = temp->next;
                    temp = temp->next;
                    delete(cur);
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            
            return head;
        }

        Node *intersectNode(Node *headA, Node *headB)
        {
            
            if(!headA && !headB) {
                return NULL;
            } else if(!headA) {
                return headB;
            } else if(!headB) {
                return headA;
            } else {
                /*Mark all the nodes of headA visited*/
                
                cout << "entered" << endl;
                unordered_map<int,int> visited;
                Node *tempA;
                int i = 0;
                tempA = headA;
                while(tempA != NULL) {
                    if(visited[tempA->data]) {
                        continue;
                    }
                    ++visited[tempA->data];
                    cout << visited[tempA->data] << endl;
                    tempA = tempA->next;
                    
                }

                cout << visited[0] << endl;
                Node *tempB = headB;
                while(tempB != NULL) {
                    if(visited[tempB->data]) {
                        head = tempB;
                        return head;
                    }
                    tempB = tempB->next;
                }
            }
            return NULL;
        }

        bool palindromList(Node *head)
        {
            
            vector<int> pal;
         
            Node *L = head;
            if(L == NULL) {
                return true;
            }
            if(L->data && L->next == NULL) {
                return true;
            }
            
            while(L!=NULL) {
                pal.push_back( L->data);
               
                L = L->next;
            }
            int i = pal.size();
            Node *temp = head;
            while(temp!=NULL) {
                
                --i;
                //cout << i << endl;
                if(temp->data!=pal[i]) {
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }

        Node  *mergeTwoLists(Node *headA, Node *headB)
        {
            Node *tempA = headA;
            Node *tempB = headB;
            Node *tempC = NULL;
            if(!tempA && !tempB) {
                return NULL;
            }
            
            while(tempA && tempB) {
                if(tempA->data < tempB->data) {
                    if(!tempC) {
                        tempC = tempA;
                        head = tempC;
                    } else {
                        tempC->next = tempA;
                        tempA = tempA->next;
                        tempC = tempC->next;
                        continue;
                    }
                }
                if(tempB->data < tempA->data) {
                    if(!tempC) {
                        tempC = tempB;
                        head = tempC;
                    } else {
                        tempC->next = tempB;
                        tempB = tempB->next;
                        tempC = tempC->next;
                        continue;
                    }
                } 

                tempA = tempA->next;
                tempB = tempB->next;
            }

            if(!tempA) {
                if(tempC) {
                    tempC->next = tempB;
                    return tempC;
                } 
                return tempB;
            }

            
            if(!tempB) {
                if(tempC) {
                    tempC->next = tempA;
                    return tempC;
                } 
                return tempA;
            }

        }

        Node *removeDuplicate(Node *head) 
        {
            Node *temp = head;
            //Node *tempC = head;
            head = temp;
            while(temp && temp->next) {
                if(temp->data == temp->next->data) {
                    temp->next = temp->next->next;
                    continue;
                }
                temp = temp->next;
            }
            return head;

        }

        Node *evenOddList(Node *head)
        {
            if (!head) {
                return NULL;
            }
            Node *even = NULL;
            Node *odd = NULL;
            Node *temp = head;
            Node *newOddHead = NULL;
            Node *newEvenHead = NULL;
            while (temp) {
                if (temp->data & 1) {
                    if (!odd) {
                        odd = temp;
                        newOddHead = odd;
                        cout << "Hello1" << endl;
                    } else {
                        cout << "Hello2" << endl;
                        odd->next = temp;
                        odd = odd->next;
                    }
                } else {
                    if (!even) {
                        even = temp;
                        newEvenHead = even;
                    } else {
                        even->next = temp;
                        even = even->next;
                    }
                }
                temp = temp->next;
            }

            if (!even && !odd) {
                return NULL;
            }
            if (!odd) {
                even->next = NULL;
                head = newEvenHead;
            }
            if (!even) {
                odd->next = NULL;
                head = newOddHead;
            }
            if (even && odd) {
                odd->next = newEvenHead;
                even->next = NULL;
                head = newOddHead;
            }
            this->display(head);
            //this->display(newEvenHead);
            return head;
        }
        
        Node *evenOddListIndex(Node *head)
        {
            if (!head) {
                return NULL;
            }
            Node *even = NULL;
            Node *odd = NULL;
            Node *temp = head;
            Node *newOddHead = NULL;
            Node *newEvenHead = NULL;
            int count = 1;
            while (temp) {
                if (count & 1) {
                    if (!odd) {
                        odd = temp;
                        newOddHead = odd;
                    } else {
                        odd->next = temp;
                        odd = odd->next;
                    }
                } else {
                    if (!even) {
                        even = temp;
                        newEvenHead = even;
                    } else {
                        even->next = temp;
                        even = even->next;
                    }
                }
                count++;
                temp = temp->next;
            }

            if (!even && !odd) {
                return NULL;
            }
            if (!odd) {
                even->next = NULL;
                head = newEvenHead;
            }
            if (!even) {
                odd->next = NULL;
                head = newOddHead;
            }
            if (even && odd) {
                odd->next = newEvenHead;
                even->next = NULL;
                head = newOddHead;
            }
            this->display(head);
            //this->display(newEvenHead);
            return head;
        }
        
};



#endif /*End*/
