#include<bits/stdc++.h>
using namespace std;

void pri(vector<vector<int>> mat)
{
    cout << "Printing matrix:\n";
    for (auto x : mat)
    {
        for (auto i : x)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "End of matrix:\n";
}


// only works for n X n matrix and perform clockwise rotation
vector<vector<int>> rotateMat(vector<vector<int>> mat){
    for(int i=1;i<mat.size();i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<mat.size();i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    return mat;
}

int main(){
    cout<<"Enter row and column size:";
    int r,c;cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

    pri(mat);
    pri(rotateMat(mat));


}