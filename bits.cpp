#include <iostream>
using namespace std;


int main()
{
    bool parity =0;
    int x = 36;
    int rem = 0;
    while (x) {
        rem = x%2;
        x = x/2;
    }

    cout << (1 << 1) << endl;
    return 0;
}
