#include<bits/stdc++.h>
using namespace std;

// 4 5 1 2 3 only unique elements
int BinarySearchRotatedSorted(vector<int> &arr,int key){
    int l=0,r=arr.size()-1;
    while(l<=r){
        int mid = (l+r) >> 1;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[l]<=arr[mid]){
            if(arr[mid]>key && arr[l]<=key) r= mid-1;
            else l = mid+1;
        }else{
            if(arr[mid]<key && arr[r]<=key) l=mid+1;
            else r=mid-1;
        }
    }
    return -1;
}

int main(){
    cout<<"enter rotated sorted size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"enter value to find:";
    int k;cin>>k;

    cout<<"given value present at :"<<BinarySearchRotatedSorted(arr,k)<<"\n";

}