#include <iostream>

using namespace std;

class BitWise {
    private:
        int x;
    public:
        BitWise(): x(0){}
        BitWise(int val): x(val) {}

        void setValue(int inp) {
            this->x = inp;
        }
       
        int getValue()
        {
            return x;
        }
        
        /*
         * Different functions start
         * */

        /*
         * count the number of bits in a given input 
         */
        short countBits(unsigned int inp) {
            short no_of_bits = 0;
            while(inp) {
                if (inp & 1) {
                    no_of_bits += 1;
                }
                inp >>= 1;
            }
            return no_of_bits;
        }

        /*
         * Function to do a bitwise AND
         * */
        short bitWiseAnd(int i, int j) {
            int shift =0;
            while(i!=j) {
                shift++;
                i = i>>1;
                j = j>>1;
            }
            i = i<< shift;
            cout << i << endl;
            return i;
        }

        /*
         * Function to reverse bits
         * */
        unsigned long int reverseBits(unsigned int i) {
            unsigned int b = 1;
            unsigned long int res = 0;
            unsigned int count = 0;
            for(int j=0;j<32; j++) {
                res <<= 1;
                res = res | (i & 1);
                i >>=1;
            }
            cout << res << endl;
        }
};


int main()
{
    BitWise B;
    while(1) {
        short choice =0;
        int num = 0;
        cout << "Please enter your choice\n"
            "1: countBits\n"
            "2: bitwise AND \n"
            "3: reverse Bits "<< endl;
        cin >> choice;

        switch(choice) {

            case 1: cout << "Please enter the number ";
                    cin >> num;
                    B.setValue(num);
                    cout <<B.countBits(B.getValue()) << endl;
                    break;
            case 2: cout << "Please enter range - two numbers";
                    int i,j;
                    cin >> i; 
                    cin >> j;
                    B.bitWiseAnd(i,j);
                    break;
            case 3: cout << "Please enter the number ";
                    int inp ;
                    cin >> inp;
                    B.reverseBits(inp);
                    break;
            default: break;
        }
        break;
    }
    return 0;
}
