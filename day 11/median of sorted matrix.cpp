#include<bits/stdc++.h>
using namespace std;

 
// here note that given matrix will always contain's odd number of elements
// time complexity is O(32 * R Log C)
int lessEqual(vector<int> &row, int val){
    int l=0,r=row.size()-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(row[mid]<=val){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l;
}

int matrixMedian(vector<vector<int>> &mat){
    int low=1;
    int high=1e9;
    int r=mat.size();
    int c=mat[0].size();

    while(low <= high){
        int mid = (low + high)/2;
        int cnt=0;
        for(int i=0;i<r;i++){
            cnt+=lessEqual(mat[i],mid);
        }
        if(cnt <= (r*c)/2){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int main(){
    cout<<"enter row and column size:";
    int r,c;cin>>r>>c;
    cout<<"enter matrix value:\n";
    vector<vector<int>> mat(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"median of matrix is :"<<matrixMedian(mat)<<"\n";
}