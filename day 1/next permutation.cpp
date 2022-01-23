#include<bits/stdc++.h>
using namespace std;

void nextPermu(vector<int> &arr){
    int ind=-1;
    for(int i=arr.size()-1;i>0;i--){
        if(arr[i]>arr[i-1]){
            ind=i-1;
            break;
        }
    }
    if(ind==-1){
        sort(arr.begin(),arr.end());
        return;
    }
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());
    return;
}

int main(){

    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];

    nextPermu(arr);
    cout<<"Your out put:->";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}