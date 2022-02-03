#include<bits/stdc++.h>
using namespace std;

double mul(double x,int n){
    double ret = 1.0;
    for(int i=1;i<=n;i++){
        ret *= x;
    }
    return ret;
}

void nthRootofM(int n,int m){
    double low=1;
    double high = m;
    double esp = 1e-6;
    while((high-low)>esp){
        double mid = (low+high)/2.0;
        if(mul(mid,n) < m){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout<<"low :"<<low<<" high :"<<high<<"\n";
    cout<<"pow(low,n):"<<pow(low,n)<<" pow(high,n):"<<pow(high,n)<<"\n";
}


int main(){
    cout<<"N and M value:";
    int n,m;cin>>n>>m;
    nthRootofM(n,m);
}