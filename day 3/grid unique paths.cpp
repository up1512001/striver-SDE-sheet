#include<bits/stdc++.h>
using namespace std;

int uniquepaths(int r,int c){
    // if(r<1 && c<1) return 0;
    if(r==1 && c==1){
        return 1;
    }
    if(r==1 && c>1){
        return uniquepaths(r,c-1);
    }
    if(r>1 && c==1){
        return uniquepaths(r-1,c);
    }
    return uniquepaths(r-1,c) + uniquepaths(r,c-1);
}

int main(){
    cout<<"Enter number of row and column :";
    int r,c;cin>>r>>c;
    int path = uniquepaths(r,c);
    cout<<"Unique paths are :"<<path<<"\n";
}