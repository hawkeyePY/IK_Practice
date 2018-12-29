#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



class Solution {
public:
    void grayCodeUtil(vector<int> res, int n,int num) {
		    // base case when we run out bits to process
		    // we simply include it in gray code sequence.
		    if (n == 0) {
			cout << num << endl;
		        res.push_back(num);
		        return;
		    }
 
		    // ignore the bit.
		    grayCodeUtil(res, n - 1, num);
 
		    // invert the bit.
		    num = num ^ (1 << (n - 1));
			grayCodeUtil(res, n - 1, num);	
	}
    vector<int> grayCode(int n) {
	vector<int> ret;
	int num=0;
	grayCodeUtil(ret,n,num);
	return ret;
        
    }
};

int main()
{
	Solution S;
	vector<int> res = S.grayCode(3);
	for (int i=0; i<res.size();i++) {
		cout << res[i] << endl;
	}
	return 0;
}
