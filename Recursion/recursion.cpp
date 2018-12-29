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
        } else {
            cout << "not found" <<endl;
        }
    }

    void targetSum_helper(int a[], int pos, int diff_so_far, vector<bool> &b_arr) {
//diff_so_far == 0 ||
        
        if (diff_so_far==0) {
            //for the array length print whatever is true in bool array
            for(int i=0; i<pos; i++) {
                if(b_arr[i]) {
                    cout << a[i] << " ";
                }
            } cout << endl;
            return;
        } else if(pos == b_arr.size()|| diff_so_far <0) {
            return;
        }
        
        b_arr[pos] = true;
        diff_so_far -= a[pos];
        targetSum_helper(a, pos+1, diff_so_far, b_arr);
        
        b_arr[pos] = false;
        diff_so_far += a[pos];
        // cout << diff_so_far << endl;
        // return;
        targetSum_helper(a, pos+1, diff_so_far, b_arr);
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

        void targetSum(int a[], int sum, int arr_size) {
            //cout << sum << endl;
            if(sum ==0) {
                cout << "nothing to find" << endl;
                return;
            }
            vector<bool> bool_arr(arr_size,false);
            targetSum_helper(a, 0, sum, bool_arr);
        }
};

int main()
{
    // Recursion permute;
    Recursion subset;
    //string a = {'b','c','e','f','g','h'};
    //string a = "bcef";
    //subset.subset(a);
    int arr[6] = {20, 30, 40, 50, 60, 70};
    // int b[3] = {10}
    // subset.binary_search(arr, 90, 6);

    // permute.permute(a);
    subset.targetSum(arr,300, 6);
    return 0;
}
