#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    bool parity = 0;
    while (n) {
        parity = !parity;
        cout << parity << endl;
        n = n & (n-1);
    }
    cout << parity<< endl;
    return 0;
}
