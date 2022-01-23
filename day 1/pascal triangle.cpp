#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ret;
    ret.push_back({1});
    ret.push_back({1, 1});
    for (int i = 2; i < n; i++)
    {
        vector<int> t(i + 1, 0);
        t[0] = 1;
        t[t.size() - 1] = 1;
        for (int j = 1; j < i; j++)
        {
            t[j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        ret.push_back(t);
    }
    return ret;
}

void pri(vector<vector<int>> &mat)
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

int main()
{

    cout << "Enter N value to get pascal's triangle matrix:";
    int n;
    cin >> n;

    vector<vector<int>> ans = pascalTriangle(n);
    pri(ans);
}