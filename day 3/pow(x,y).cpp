#include<bits/stdc++.h>
using namespace std;

double power(double n,int p2){
    double ans=1;
    int p=abs(p2);
    // if(p<0) ans=-1*ans;
    while(p>0){
        if(p%2){
            ans *= n;
            p--;
        }else{
            n*=n;
            p/=2;
        }
    }
    return p2>=0?ans:((double)1.0/ans);
}

int main(){
    cout<<"Enter N value and power value:";
    double n;int p;
    cin>>n>>p;
    cout<<n<<"^"<<p<<" is :"<<power(n,p)<<"\n";
}