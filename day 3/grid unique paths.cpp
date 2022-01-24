#include<bits/stdc++.h>
using namespace std;

/*
 ( ie: (m+n-2)C(n-1) or (m+n-2)C(m-1) )

int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
*/

int uniquepaths(int r,int c){
    // if(r<1 && c<1) return 0;
    // dp can be easily be applied
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