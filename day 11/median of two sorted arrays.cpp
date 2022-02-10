#include<bits/stdc++.h>
using namespace std;

double medinOfTwoSortedArray(vector<int> &a1,vector<int> &a2){
    if(a2.size() < a1.size()){
        return medinOfTwoSortedArray(a2,a1);
    }
    int low=0,high=a1.size(),medianPosition = (a1.size()+a2.size()+1)/2;
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = medianPosition - mid1;

        int l1 = (mid1==0)?INT_MIN:a1[mid1-1];
        int l2 = (mid2==0)?INT_MIN:a2[mid2-1];
        int r1 = (mid1==a1.size())?INT_MAX:a1[mid1];
        int r2 = (mid2==a2.size())?INT_MAX:a2[mid2];

        if(l1<=r2 && l2<=r1){
            if((a1.size()+a2.size())%2 != 0){
                return max(l1,l2);
            }
            return (max(l1,l2)+min(r1,r2))/2.0;
        }else if(l1>r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }
    return 0.0;
}

int main(){
    cout<<"enter first sorted array size :";
    int n;cin>>n;
    vector<int> a1(n);
    for(int i=0;i<n;i++) cin>>a1[i];
    cout<<"enter second sorted array size :";
    int m;cin>>m;
    vector<int> a2(m);
    for(int i=0;i<m;i++) cin>>a2[i];

    cout<<"median of two sorted array is :"<<medinOfTwoSortedArray(a1,a2)<<"\n";
}