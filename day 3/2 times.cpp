#include<bits/stdc++.h>
using namespace std;

int majority(vector<int> &arr){
    int cnt=0,maj=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==maj){
            cnt++;
        }else if(cnt==0){
            maj=arr[i];
            cnt=1;
        }else{
            cnt--;
        }
    }
    return maj;
}

int main(){
    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"majority element is :" <<majority(arr)<<"\n";

}