#include<bits/stdc++.h>
using namespace std;


// merge sort intuation 
// time complexity will be O(n Log n) + O(N) + O(N)
int merge(vector<int> &arr,int left,int mid,int right){
    int cnt=0;
    int i=left,j=mid+1;
    for(i;i<=mid;i++){
        while(j<=right && arr[i]>2*arr[j]){
            j++;
        }
        cnt += (j-mid-1);
    }
    vector<int> temp;
    int l=left,r=mid+1;
    while(l<=mid && r<=right){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l++]);
        }else{
            temp.push_back(arr[r++]);
        }
    }
    while(l<=mid){
        temp.push_back(arr[l++]);
    }
    while(r<=right){
        temp.push_back(arr[r++]);
    }
    for(int k=left;k<=right;k++){
        arr[k] = temp[k-left];
    }
    return cnt;
}

int mergeSort(vector<int> &arr,int left,int right){
    int ans=0;
    if(left<right){
        int mid = (left+right)/2;
        ans += mergeSort(arr,left,mid);
        ans += mergeSort(arr,mid+1,right);
        ans += merge(arr,left,mid,right);
    }
    return ans;
}

int reversePairs(vector<int> &arr){
    return mergeSort(arr,0,arr.size()-1);
}

int main(){
    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans = reversePairs(arr);

    cout<<"Total number of reverse pairs are :"<<ans<<"\n";
    
}