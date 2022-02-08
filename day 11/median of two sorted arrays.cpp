#include<bits/stdc++.h>
using namespace std;

double medinOfTwoSortedArray(vector<int> &a1,vector<int> &a2){

}

int main(){
    cout<<"enter first sorted array size :";
    int n;cin>>n;
    vector<int> a1(n);
    for(int i=0;i,n;i++) cin>>a1[i];
    cout<<"enter second sorted array size :";
    int m;cin>>m;
    vector<int> a2(m);
    for(int i=0;i<m;i++) cin>>a2[i];

    cout<<"median of two sorted array is :"<<medinOfTwoSortedArray(a1,a2)<<"\n";
}