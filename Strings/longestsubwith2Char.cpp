#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int getLongestSubstringLengthExactly2DistinctChars(string s) {
 	int len = s.length();
	int sublen =0;
	map<char,int> map;
	vector<int> res;
	int charlen=0;
	for (int i=0; i<len; i++) {
		// cout << map.size() << endl;
		if (!map[s[i]] && map.size()<=2) {
			map[s[i]] = 1;
			sublen++;
			// cout<< sublen<< endl;
		} 
		else if(map[s[i]] && map.size()<=2) {
			// cout << "I am here 2" << endl;
			sublen++;
		}

		// } 
		else if (!map[s[i]] && map.size() == 2) {
			//push the result
			res.push_back(sublen);

			// clear the old data
			map.clear();
			sublen = 0;
			
			// add the new data;
			map[s[i]] = 1;
			sublen++;
		} 
	}
	res.push_back(sublen);
	if (map.size()==1) {
		return 0;
	}

	int max = 0;
	for (int j = 0; j<map.size(); j++) {
		if (max<res[j]) {
			max = res[j];
		}
	}
	return max;

}

int main()
{
	string s = "e";	
	cout <<	getLongestSubstringLengthExactly2DistinctChars(s)<<endl;
    return 0;
}
