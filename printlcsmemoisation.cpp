//Keep Calm and Jai Shri Ram
#include<bits/stdc++.h>
using namespace std;
#define lli                         long long int
#define vi                          vector<int>
#define ii                          pair<int,int>
#define all(v)                      v.begin(),v.end()
#define getunique(v)                {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pb                          push_back
#define ff                          first
#define ss                          second
#define endl                        "\n"
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MS = 1000001;
const lli INF = 1e9 + 7;

int dp[1001][1001];

template<class T>
bool comp(T a, T b) {
    if (a < b)
        return true;
    return false;
}

int printlcs(string s1, string s2 ,  int n , int m)
{
    if (n == 0 || m == 0)
        return dp[n][m] = 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + printlcs(s1, s2, n - 1, m - 1);
    else {
        return dp[n][m] = max(printlcs(s1, s2, n - 1, m), printlcs(s1, s2, n, m - 1));
    }
}


int main() {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    memset(dp, -1, sizeof dp);
    cout << printlcs(s1, s2, n, m) << " ";
    string s;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s;

}
