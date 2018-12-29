#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void powerSet(vector<int> inp) 
{
    int size = pow(2,inp.size());
    cout << size << endl;
    int setSize = inp.size();
    vector<int> res = {};
    for (int i=0; i<size ; i++) {
            for (int j=0; j<setSize; j++){
                if (i & (1<<j)) {
                        cout << inp[j];
                }
                cout << "\n" ;
            }
            

    }


}

int main()
{
    vector<int> inp = { 1,2,3 };
    powerSet(inp);
    return 0;
}
