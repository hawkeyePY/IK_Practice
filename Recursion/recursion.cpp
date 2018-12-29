#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef struct _list_{
    int val;
    struct _list_ *next;
}List;

class Recursion 
{   
    List list;
    void print_array(string a){
        for(int i=0;i<a.length();i++) {
            cout << a[i] ;
        }
        cout << endl;
    }
    
    void print_array_until(string a, int j){
        for(int i=0;i<j;i++) {
            cout << a[i] ;
        }
        cout << endl;
    }

    void permute_helper(string a, int i){
        int len = a.length();
        if(i==len-1) {
            print_array(a);
            return;
        }
        for(int j = i; j<len; j++){
           swap(a[i],a[j]);
           permute_helper(a, i+1);
           swap(a[i],a[j]);
        }
    }

    void subset_helper(string a, int i, string sub, int j) {
        int n = a.size();
        if (i==n) {
            print_array_until(sub,j);
            return;
        }
        subset_helper(a, i+1, sub, j);
        sub[j] = a[i];
        subset_helper(a, i+1, sub, j+1);
        return;
    }

    void binary_search_helper(int arr[], int key, int low, int high) {
        if (low < high) {
            int mid = (low + high)/2;
            if (arr[mid]==key) {
                cout << "found" <<endl;
                return;
            }
            if(arr[mid]>key) {
                binary_search_helper(arr, key, low, mid);
            } else {
                binary_search_helper(arr, key, mid+1, high);
            }
        }
    }

    public:

        void permute(string a)
        {
            int i = 0;
            permute_helper(a,i);
        }

        void subset(string a) {
            string sub = a;
            sub.empty();
            // cout <<sub.length() <<endl;
            subset_helper(a, 0, sub, 0);
        }

        void binary_search(int arr[], int key, int length) {
            binary_search_helper(arr, key, 0, length-1);
        }
};

int main()
{
    // Recursion permute;
    Recursion subset;
    //string a = {'b','c','e','f','g','h'};
    string a = "bcef";
    //subset.subset(a);
    int arr[6] = {20, 30, 40, 50, 60, 70};
    subset.binary_search(arr, 30, 6);
    // permute.permute(a);
    return 0;
}
