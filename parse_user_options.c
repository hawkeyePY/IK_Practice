#include <stdio.h>
#include <parse_user.h>

uint8_t parse_user_choice(int ch)
{
    do{
        switch(ch):
            case 1: /*list the functionalities for linked list*/
            log("You chose Linked list. Hurray! Let's begin");
            log("1: Insert at front\n
            \2: Insert at end");
            break;

            case 2: /*list the functionalities for trees*/
            break;

            case 3: /*list the functionalities for hash*/
            break;
    
    }while(0); /*end of while loop*/

    return 0;
}

uint8_t user_options_for_choice(int ch)
{
    return 0;
}


uint8_t parse_user_options(int op)
{
    return 0;
}
