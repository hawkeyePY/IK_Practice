#include <iostream>
#include <vector>
#include <string>

using namespace std;


void pre_process(int *pre, int len, string p) {
    int n = 0;
    pre[0] = 0;
    int i =1;
    while (i<len) {
        if (p[i] == p[n]) {
            n++;
            pre[i] = n;
            i++;
        }
        else {
            if (n!=0) {
                n = pre[n-1];
            } else {
                pre[i] = 0;
                i++;
            }
        }
    }
}


vector<int> KMP(string t, string p) {
    vector<int> res;
    int t_len = t.length();
    int p_len = p.length();

    if (t_len == 0 || p_len == 0) {
        res.push_back(-1);
        return res;
    }
    int pre[p_len];

    pre_process(pre, p_len, p);

    int i=0;
    int j=0;

    while(i<t_len) {

        if (t[i]==p[j]) {
            ++j;
            ++i;
        }
        if (j==p_len) {
            res.push_back(i-j);
            j = pre[j-1];
        } 
        else if(i<t_len &&p[j]!=t[i]) {
            if (j!=0) {
                j = pre[j-1];
            } else {
                i +=1;
            }
        }
    } 
    if(res.size()==0) {
        res.push_back(-1);
    }
    return res;
}


void printArray(vector<int> a) {
    for(int i=0; i<a.size();i++) {
        cout << a[i] << endl; ;
    }
}

int main()
{
    string t = "aaaaaab";
    string p = "aaab";
    //string s = "a";
    // string r = "CCCCCD";

    vector<int>arr = kmp_algo(t,p);
   // vector<int>arr1 = kmp_algo(t,s);
    // vector<int>arr2 = kmp_algo(t,r);
    printArray(arr);
    //printArray(arr1);
    // printArray(arr2);
}
