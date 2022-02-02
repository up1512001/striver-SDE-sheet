#include<bits/stdc++.h>
using namespace std;


vector<int> allAnagramIndex(string &s,string &p){
    // vector<int> v1(26,0),v2(26,0);
    // for(int i=0;i<p.size();i++){
    //     v1[p[i]-'a']++;
    // }
    // int j=0;
    // vector<int> ans;
    // for(int i=0;i<=s.size();i++){
    //     // if(v1 == v2){
    //     //     cout<<s.substr(j,i)<<"\n";
    //     //     ans.push_back(j);
    //     //     v2[s[j]-'a']--;
    //     //     j++;
    //     // }else if(v1 != v2 && i-j == p.size()){
    //     //     v2[s[j]-'a']--;
    //     //     j++;
    //     // }
    //     // v2[s[i]-'a']++;
    //     if(i<p.size()){
    //         v2[s[i]-'a']++;
    //     }else{
    //         if(v1 == v2){
    //             ans.push_back(j);
    //             v2[s[j]-'a']--;
    //             j++;
    //         }else if(v1 != v2 && i-j == p.size()){
    //             v2[s[j]-'a']--;
    //             j++;
    //         }
    //         v2[s[i]-'a']++;
    //     }
    // }
    // return ans;

    vector<int> v1(26, 0), v2(26, 0);
    for (int i = 0; i < p.size(); i++)
    {
        v1[p[i] - 'a']++;
    }
    int j = 0;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < p.size())
        {
            v2[s[i] - 'a']++;
        }
        else
        {
            if (v1 == v2)
            {
                ans.push_back(j);
                v2[s[j] - 'a']--;
                j++;
            }
            else if (v1 != v2 && i - j == p.size())
            {
                v2[s[j] - 'a']--;
                j++;
            }
            v2[s[i] - 'a']++;
        }
    }
    if (v1 == v2)
    {
        ans.push_back(j);
    }
    return ans;
}


int main(){
    string s = "abab";
    string p = "ab";
    vector<int> ans = allAnagramIndex(s,p);
    cout<<"your answer is :";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}