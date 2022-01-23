#include<bits/stdc++.h>
using namespace std;

void pri(vector<int> &arr){
    cout<<"Printing array:\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nEnd of printing:\n";
}

void sort012(vector<int> &arr){
    int z=0,o=0,t=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) z++;
        else if(arr[i]==1) o++;
        else t++;
    }
    int i=0;
    while(z--){
        arr[i++] = 0;
    }
    while(o--){
        arr[i++] = 1;
    }
    while(t--){
        arr[i++] = 2;
    }
}

int main(){
    cout<<"Enter n size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    pri(arr);
    sort012(arr);
    pri(arr);

}