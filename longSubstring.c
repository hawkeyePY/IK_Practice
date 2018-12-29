#include "debug.h"
#include <string.h>


typedef struct _longsub_
{
    char c;
    struct _longsub_ *next;
} longSubstring;




int lengthOfLongestSubstring(char *s)
{
    int len = 0, i=0;
    len = strlen(len);
    longSubstring *subString;;
    char *temp;


    return 0;
}

int main(int argc, char* argv[])
{
    char c[256] = {"abcabcbb"};
    log("%s", c);
    lengthOfLongestSubstring(c);

    return 0;
}
