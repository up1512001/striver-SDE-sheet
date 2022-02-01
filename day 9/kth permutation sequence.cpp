/*

class Solution {
public:

// approach one using recursion    
    void f(string s,vector<string> &ans,string t){
        if(t.size()==s.size()){
            ans.push_back(t);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                t+=s[i];
                s[i] = '.';
                f(s,ans,t);
                s[i] = t[t.size()-1];
                t.pop_back();
            }
            
        }
    }
    
    string getPermutation(int n, int k) {
        vector<string> ans;
        string t="";
        string s="";
        for(int i=1;i<=n;i++) s += (i+'0');
        f(s,ans,t);
        return ans[k-1];
    }
    
    
// approach two using concept of next greter element    
void p(vector<int> arr){
    cout<<"printing\n";
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}

    string getPermutation(int n,int k){
        string s="";
        for(int i=1;i<=n;i++){
            s += (i+'0');
        };
        while(k>1){
            int ind=-1;
            for(int i=s.size()-1;i>0;i--){
                if(s[i]>s[i-1]){
                    ind=i-1;
                    break;
                }
            }
            if(ind==-1){
                sort(s.begin(),s.end());
            }
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]>s[ind]){               
                    swap(s[i],s[ind]);
                    reverse(s.begin()+ind+1,s.end());
                    break;
                }
            }
            k--;
        }
        return s;
    }
    
};

*/