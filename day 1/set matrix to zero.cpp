#include<bits/stdc++.h>
using namespace std;

void setmatrixzero(vector<vector<int>> &mat){

    bool fr=false,fc=false;
    for(int i=0;i<mat.size();i++){
        if(mat[i][0] == 0) fc=true;
    }
    for(int j=0;j<mat[0].size();j++){
        if(mat[0][j] == 0) fr=true;
    }

    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j] == 0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    for(int i=1;i<mat.size();i++){
        for(int j=1;j<mat[0].size();j++){
            if(mat[i][0]==0 || mat[0][j]==0){
                mat[i][j] = 0;
            }
        }
    }

    if(fc){
        for(int i=0;i<mat.size();i++){
            mat[i][0] = 0;
        }
    }
    if(fr){
        for(int j=0;j<mat[0].size();j++){
            mat[0][j] = 0;
        }
    }


}
void pri(vector<vector<int>> &mat){
    cout<<"Printing matrix:\n";
    for(auto x : mat){
        for(auto i : x){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    cout<<"End of matrix:\n";
}

int main(){
    cout<<"Enter row and column size:";
    int r,c;cin>>r>>c;

    vector<vector<int>> mat(r,vector<int>(c,0));
    cout<<"Enter 0 or 1 value for matrix:";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    pri(mat);
    setmatrixzero(mat);
    pri(mat);
}