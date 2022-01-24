#include<bits/stdc++.h>
using namespace std;


// O(2*N) time and O(N) space
int LCSwithoutRepeat(string &s){
    int left=0,right=0;
    int ans=0;
    unordered_set<char> st;
    while(right < s.size()){
        if(st.find(s[right])!=st.end()){
            while(st.find(s[right]) != st.end()){
                st.erase(s[left++]);
            }
        }
        ans = max(ans,right-left+1);
        st.insert(s[right]);
        right++;
    }
    return ans;

}

// O(N) time and O(N) space
int LCSoptimized(string &s){
    int left = 0,right=0;
    int ans=0;
    unordered_map<char,int> mp;
    while(right < s.size()){
        if(mp.find(s[right])!=mp.end()){
            left = max(mp[s[right]] + 1,left);
        }
        ans = max(ans,right-left+1);
        mp[s[right]] = right;
        right ++;
    }
    return ans;
}


int main(){
    cout<<"Enter String s:";
    string s;cin>>s;

    int LCS = LCSwithoutRepeat(s);
    cout<<"Longest common substring with out repeat character is :"<<LCS<<"\n";
    cout << "Longest common substring with out repeat character is :" << LCSoptimized(s) << "\n";
}