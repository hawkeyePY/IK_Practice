#include <iostream>

using namespace std;

int foo(int*& a) 
{
        int* b = new int;
        *b = 10;
        a = b;

        return 0;
}

int main()
{
        int *a = NULL;
        int *b = a;
        foo(&a);
        cout << a << endl;
        cout << *a << endl;
        return 0;
}
