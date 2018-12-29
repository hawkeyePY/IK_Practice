#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#if 1
#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%s:%d) " M "\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define log_msg(M, ...) fprintf(stderr, "" M "\n", ##__VA_ARGS__)
#define log_data(M, ...) fprintf(stderr, "" M " ", ##__VA_ARGS__)
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%s:%d: errno: %s) " M "\n", __FILE__, __func__, __LINE__, clean_errno(), ##__VA_ARGS__)
#endif

#define RESULT_ARRAY_SIZE 2
#define INVALID -1
#define MAX_INVALID 0xFFFF
#define INT_MAX 2147483647 
/*
 * Assumptions
 * limiting the input size to int32_t
 * if the input size is > int_MAX will return error
 */

void printData (int data[],int dataLen) 
{
    for(int i=0; i<dataLen; i++) {
        log_data("%d",data[i]);
    }
    log_msg("");
}


int findIndexOfNumber(int inp[],int inp_size, int num, int ind) 
{
    int j = ind;
    if (j<0) {
        j =0;
    }

    for ( ;j<inp_size; j++) {
        if (num == inp[j]) {
            log_msg("Found %d at %d",num,j);
            break;
        }
    }
    if (j == inp_size) {
        return INVALID;
    }
    return j;
}

bool findIndexofSubset(int inp[],int inp_size, int elem_seq[], int elem_seq_size, int res[])
{
    bool retVal = true;
    int numIndex = 0;
    int firstIndex = INVALID;
    int lastIndex = INVALID;
    int j=0;
    int minDiff = MAX_INVALID;
    int max_inp_size = inp_size;
    if (elem_seq_size > inp_size) {
        return NULL;
    }
    while (inp_size) {
        numIndex = findIndexOfNumber(inp, max_inp_size, elem_seq[j], lastIndex);
        if (numIndex == INVALID) {
            retVal = false;
            goto RETURN;
        } 
        if (j==0) { 
            firstIndex = numIndex;
        }
        if (j==(elem_seq_size-1) ) {
            lastIndex = numIndex;
        }
        ++j;
        if (j==elem_seq_size) {
            j = 0;
            int diff = (lastIndex - firstIndex); 
            if (diff < minDiff) {
                res[RESULT_ARRAY_SIZE-2] = firstIndex;
                res[RESULT_ARRAY_SIZE-1] = lastIndex;
                minDiff = diff;
            }
        }
        if(firstIndex > lastIndex) {
            lastIndex = firstIndex;
        }
        inp_size--;
    }
    RETURN:
        return retVal;
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
                case 1: log_msg("Please enter the array size");
                        if(userInpSize !=0) {
                            log_msg("Looks like you were already here");
                            continue;
                        }

                        scanf("%lu",&userInpSize);
                        if (userInpSize > INT_MAX) {
                            log_err("Not supported now!!");
                            continue;
                        }                    
                        *a_size = (int)userInpSize;
                        entryCount++;
                        break;

                case 2: log_msg("Please enter the Elem Seq size");
                        if(elemSeqSize != 0) {
                            log_msg("Looks like you were already here");
                            continue;
                        }
                        scanf("%lu",&elemSeqSize);
                        if (elemSeqSize > INT_MAX) {
                            log_err("Not supported now!!");
                            continue;
                        }
                        if (elemSeqSize > userInpSize) {
                            log_err("Please enter correctly");
                            continue;
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
    return a;
}

void scanUserArray(int a[],int len, char *s)
{
    log_msg("Please Enter %s [%d] elements", s,len);
    for (int i=0; i<len; i++) {
        scanf("%d", &a[i]);
    }
}

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
    int res[RESULT_ARRAY_SIZE] = {0};
    int *userData = NULL, *elemSeq = NULL;
    int userDataLen = 0, elemSeqSize = 0;
    /*
     * function to read user inputs
     */
    scanUserInput(&userDataLen, &elemSeqSize);
    userData = allocateMem(userDataLen);
    elemSeq = allocateMem(elemSeqSize);

    scanUserArray(userData, userDataLen, "Input Array");
    scanUserArray(elemSeq, elemSeqSize, "Elem Sequence Array");
//    printData(userData, userDataLen);
//    printData(elemSeq, elemSeqSize);

    findIndexofSubset(userData, userDataLen, elemSeq, elemSeqSize, res);

    for (int i=0; i<RESULT_ARRAY_SIZE; i++) {
        log_data("%d",res[i]);
    }
    log_msg(" ");
    return 0;
}
