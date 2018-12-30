#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
class Sum{

	int precedence(char op) {
		if (op == '\0') {
			return 3;
		} else if (op =='*') {
			return 2;
		}	else if (op =='+') {
			return 1;
		} else {
			return 0;
		}
	}

	int applyOperation(int a, int b, char op) {
		switch(op) {
			case '\0': return a*10+b;
			break;
			case '*': return a*b;
			break;
			case '+':return a+b;
			break;
		}
	}

	bool process_string(string so_far, int target) {
		bool res = false;
		stack<int> st;
		stack<char> ops;
		int value =0;
		for(int i=0; i<so_far.length(); i++) {
			if (isdigit(so_far[i])){
				// push to stack
				st.push(so_far[i] - '\0');
			} else {
				while(!ops.empty() && precedence(ops.top())>=precedence(so_far[i])){
					int value2 = st.top();
					st.pop();
					int val1 = st.top();
					st.pop();
					value = applyOperation(value2, val1, ops.top());
					ops.pop();
				}
				ops.push(so_far[i]);
			}
		}
		if (value == target) {
			res = true;
		}
		return res;
	}

	void targetSum_helper(string s, string str_so_far, int index, char op, vector<string> &res, int target){
		int len = s.length() + s.length()-1;
		if(index == len-1){
			str_so_far += s[s.length()-1];

			if(process_string(str_so_far, target)){
				res.push_back(str_so_far);
			}
			return;
		}

		op = '\0';
		str_so_far += s[index-1] + op;
		targetSum_helper(s, str_so_far, index+2, op, res, target);
		return;
		str_so_far.pop_back();
		op = '*';
		str_so_far += s[index-1] + op;
		targetSum_helper(s, str_so_far, index+2, op, res, target);
		str_so_far.pop_back();
		op = '+';
		str_so_far += s[index-1] + op;
		targetSum_helper(s, str_so_far, index+2, op, res, target);
		//str_so_far.pop_back();
	}

	public:

		vector<string> targetSum(string s, int target){
			vector<string> res;
			string str_so_far(2*s.length(),'\0');
			cout << "calling helper" << endl;
			targetSum_helper(s, str_so_far, 1, '\0', res, target);
			return res;
		}
};


int main()
{
	Sum target;
	string s = "222";
	target.targetSum(s,24);
	return 0;
}