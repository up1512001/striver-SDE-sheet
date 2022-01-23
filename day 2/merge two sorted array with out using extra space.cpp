#include<bits/stdc++.h>
using namespace std;

void mergeWithoutSpace(vector<int> &a1,vector<int> &a2){
    int i=a1.size()-1,j=0;
    while(i>=0 && j<a2.size()){
        if(a1[i]>a2[j]){
            swap(a1[i],a2[j]);
            i--;
            j++;
        }else{
            break;
        }
    }
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
}

int main(){

    cout<<"Enter length of first array:";
    int n;cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++) cin>>arr1[i];
    cout<<"Enter length of second array:";
    int m;cin>>m;
    vector<int> arr2(m);
    for(int i=0;i<m;i++) cin>>arr2[i];

    mergeWithoutSpace(arr1,arr2);

    cout<<"Sorted array output is :\n";
    for(int i=0;i<arr1.size();i++) cout<<arr1[i]<<" ";
    for(int i=0;i<arr2.size();i++) cout<<arr2[i]<<" ";

}