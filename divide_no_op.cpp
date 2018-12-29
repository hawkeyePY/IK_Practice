#include <iostream>

using namespace std;

unsigned int divideNoOp(unsigned int x,unsigned int y)
{
        //cout << x << " " << y << endl;
        if (x<y) {
                return 0;
        }
        int power = 0;
        while ((1U<<power)*y <= x) {
                ++power;
                cout << power << endl;
        }
        int part = (1U<<(power-1));
        cout <<"part" <<part << endl;
        return part + divideNoOp(x-part*y,y);

}


int main()
{
        int x = 5, y = 5;
        cout<< divideNoOp(x,y)<< endl;
        return 0;
}

