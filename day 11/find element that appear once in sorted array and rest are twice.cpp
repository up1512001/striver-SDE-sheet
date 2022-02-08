#include<bits/stdc++.h>
using namespace std;


// O(N) time and O(1) space complexity
int onceInArray(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        arr[0] ^= arr[i];
    }
    return arr[0];
}

// using binary search
int binarySearch(vector<int> &arr){
    int l=0,r=arr.size()-2;
    while(l<=r){
        int mid = (l+r) >> 1;
        if(arr[mid] == arr[mid^1]){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return arr[l];
 }

int main(){
    cout<<"enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Element that appear once is :"<<onceInArray(arr)<<" XOR used"<<"\n";
    cout << "Element that appear once is :" << binarySearch(arr) <<" Binary Search"<< "\n";
}