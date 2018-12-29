#include "debug.h"
#include "linked_list.h"
#include <stdint.h>

int main(int argv, char *argc)
{
	unsigned int val;
    log("Enter your choice");
	log("1:Linked list\n2: Trees\n3:Hash\n4:Cryptography");
	scanf("%x",&val);
	log("%x",val);
    return 0;
}
