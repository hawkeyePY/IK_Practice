#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define log_msg(M, ...) fprintf(stderr, "" M "\n", ##__VA_ARGS__)
#define log_data(M, ...) fprintf(stderr, "" M " ", ##__VA_ARGS__)
#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%s:%d) " M "\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%s:%d: errno: %s) " M "\n", __FILE__, __func__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define RESULT_ARRAY_SIZE 2
#define INVALID -1
#define MAX_INVALID 0xFFFF
#define INT_MAX 2147483647 

int res[RESULT_ARRAY_SIZE];
/*
 * Assumptions
 * limiting the input size to int32_t
 * if the input size is > int_MAX will return error
 */
int top = -1; 

int isStackempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == INT_MAX)
      return 1;
   else
      return 0;
}

void pop(int stack[]) {

   if(!isStackempty()) {
      top = top - 1;
   } else {
      log_err("Could not retrieve data, Stack is empty.\n");
   }
}

void push(int stack[],int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      log_err("Could not insert data, Stack is full.\n");
   }
}


void scanUserInput(int *a_size,int*b_size)
{
    int inp=0;
    size_t elemSeqSize=0;
    size_t userInpSize=0;
    unsigned char entryCount = 0;
    
    while(1) {
        if (entryCount < 2) {
            log_msg("Please input the following in correct order");
            log_msg("1:User Input Size\n2:Elem Seq Size\n");
            scanf("%d", &inp);
            switch(inp) {
                case 1: log_msg("Please enter the array size positive only");
                        if(userInpSize != 0 && userInpSize > 0) {
                            log_msg("Looks like you already entered InpArray size");
                            break;
                        }

                        scanf("%lu",&userInpSize);
                        if (userInpSize > INT_MAX || userInpSize==0 ) {
                            log_msg("Please enter correct value Inp cannot be 0 or negative");
                            userInpSize = 0;
                            continue;
                        }                    
                        *a_size = (int)userInpSize;
                        entryCount++;
                        break;

                case 2: log_msg("Please enter the Elem Seq size");
                        if(elemSeqSize != 0 && elemSeqSize > 0) {
                            log_msg("Looks like you already entered Elem Seq size");
                            break;
                        }
                        scanf("%lu",&elemSeqSize);
                        if (elemSeqSize > INT_MAX || elemSeqSize ==0) {
                            log_err("Please enter correct value Inp cannot be 0 or negative");
                            elemSeqSize = 0;
                            continue;
                        }
                        if ((elemSeqSize > userInpSize )){
                            log_err("Please enter correctly elemSeqSize is always less than userInpSize");
                            elemSeqSize = 0;
                            break;
                        }
                        *b_size = (int)elemSeqSize;
                        entryCount++;
                        break;

                    default:
                         if (entryCount >= 2) {
                             log_msg("All values filled, Returning from the function");
                             return;
                        }
                        log_msg("Some data needs to be filled");
                        continue;
            }
        } else {
            break;
        }
    }
}

int * allocateMem(int len) 
{
    int *a;
    a = malloc(sizeof(int) *len);
    if(!a) {
        return NULL;
    }
    return a;
}

void scanUserArray(int a[],int len, char *s)
{
    log_msg("Please Enter %s [%d] elements", s,len);
    for (int i=0; i<len; i++) {
        scanf("%d", &a[i]);
    }
}

bool checkVisited(int visitedPos[], int elemSeqPos) {
    if (!visitedPos[elemSeqPos]) {
        //log_info("Visited is false");
        return false;
    }
    return true;
}

int getElemSeqIndex(int elemSeq[], int elemSeqSize, int num)
{
    for(int i=0; i<elemSeqSize; i++){
        if(num == elemSeq[i]) {
            return i;
        }
    }
    return -1;
}

bool checkStack(int stack[],int visitedPos[],int elemSeq[],int elemSeqSize, int inputPos, int userData[]) 
{
    //log_info("ENTRY ");

    if(top == INVALID && (!checkVisited(visitedPos,inputPos))) {
        //log_info("Pushing to stack [%d]",inputPos);
        // First push
        push(stack,inputPos);
        visitedPos[inputPos] = 1;
    } else {
        if (top == INVALID && (inputPos > 0)) {
            return false;
        }
        if (checkVisited(visitedPos,inputPos)){
            // already on stack but still pushing
            push(stack,inputPos);
        } else {
            // code for backtracking
            /*
            UserInp - 10 5 8 2 12 5 1 5 6 8 5 13 5 3 5 8 2 3
            ElemSeq - 5 8 2 3
            Push all 5, 8 , 2, 3 on stack but, if 3 is not after 2 then pop the stack. such that
            stack always 5 8 2 3 in correct order 
            */
            while (true) {
                if (top == INVALID) {
                    return false;
                }
                int elemSeqIndex = getElemSeqIndex(elemSeq,elemSeqSize, userData[inputPos]);
                if (elemSeqIndex!=-1) {
                    if (userData[stack[top]] == elemSeq[elemSeqIndex-1]) {
                        visitedPos[inputPos] =1;
                        push(stack, inputPos);
                        break;
                    } else {
                        pop(stack);
                    }

                } else {
                    return false;
                }


            }
        }
    }
    //log_info("EXIT:%d",true);
    return true;
}

/*
Function to find the Number in ElemSeq
*/
bool findNumInElemSeq(int userNum, int elemSeq[], int elemSeqSize )
{
    for(int i=0;i<elemSeqSize; i++)
    {
        if(userNum == elemSeq[i]) { 
            return true;
        }
    }
    return false;
}


/*
Function to find the minimum distance between first and last index
*/
bool checkMinDiff (int stack[],int elemSeq[], int userData[],int elemSeqSize, int *diff)
{
    //log_info("****ENTRY****");

    int j = 0;
    if (userData[stack[top]] == elemSeq[elemSeqSize-1]) {
        if (userData[stack[top-(elemSeqSize-1)]] == elemSeq[0]) {
            int tempDiff = stack[top] - stack[top-(elemSeqSize-1)];
            if (*diff > tempDiff ){
                *diff = tempDiff;
                res[j] = stack[top-(elemSeqSize-1)];
                res[++j] = stack[top];
      //          log_info("****EXIT***");
                return true;
            }
        }
    }
    //log_info("****EXIT***");
    return false;
}

/*
Wrapper function that calls all other functions. 
*/
bool findIndexofSubset(int userData[],int userDataLen, int elemSeq[], int elemSeqSize, int stack[])
{
    int inputPos= -1;
    bool retval = false;
    int visitedPos[userDataLen];
    memset(visitedPos, 0, sizeof(visitedPos[0] * userDataLen));
    int minDiff = INT_MAX-1;
    for (int i=0; i<userDataLen; i++) {
        if(findNumInElemSeq(userData[i], elemSeq, elemSeqSize)) {
            inputPos = i;
            if (checkStack(stack,visitedPos, elemSeq, elemSeqSize,inputPos, userData)) {
                if(checkMinDiff(stack,elemSeq,userData,elemSeqSize,&minDiff)) {
                    retval = true;
                }
            }
        }
    }
    return retval;
}

/*
Function used when only one element is present in ElemSeq
*/

int findIndexInInput(int userData[], int userDataLen, int num) {
    for(int i=0; i<userDataLen; i++) {
        if (num == userData[i]) {
            return i;
        }
    }
    return -1;
}


/*
main
*/
int main( int argv, char **argc)
{
    /*
    int a[] = {1,5,7,2,6,9,1,4,2};
    int b[] = {1,2};
    int c[] = {1,8};
    int d[] = {1,5,2};
    
     size_t inp_size = (sizeof(a)/sizeof(a[0]));
    size_t elem_seq_size = (sizeof(d)/sizeof(d[0]));
    */
    int *userData = NULL, *elemSeq = NULL;
    int userDataLen = 0, elemSeqSize = 0;
    int stack[userDataLen] ;
    /*
     * function to read user inputs
     */
    scanUserInput(&userDataLen, &elemSeqSize);

    memset(stack, 0, sizeof(stack[0] * userDataLen));
    userData = allocateMem(userDataLen);
    if (!userData) {
        log_err("Could not allocate memory");
        return 0;
    }
    elemSeq = allocateMem(elemSeqSize);
    if (!elemSeq) {
        log_err("Could not allocate memory");
        return 0;
    }

    scanUserArray(userData, userDataLen, "Input Array");
    scanUserArray(elemSeq, elemSeqSize, "Elem Sequence Array");
//    printData(userData, userDataLen);
//    printData(elemSeq, elemSeqSize);
    if (elemSeqSize == 1) {
        int pos = findIndexInInput(userData, userDataLen, elemSeq[0]); 
        log_msg("[%d] Found at indexes [%d]", elemSeq[0], pos);
        return 0;
    }
    if(findIndexofSubset(userData, userDataLen, elemSeq, elemSeqSize, stack )) {
        log_data("Found at indexes");
        for (int i=0; i<RESULT_ARRAY_SIZE; i++) {
            log_data("[%d] ",res[i]);
        }
        log_msg(" ");
    } else {
        log_err("NOT FOUND");
    }



    return 0;
}

