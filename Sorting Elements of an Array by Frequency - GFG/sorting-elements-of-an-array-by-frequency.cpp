#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
void dosort(vector<int>&nums)
{
            map<int, int> mp;
            for (auto i: nums)
                mp[i]++;
            vector<pair<int, int>> v;
            for (auto i: mp)
                v.push_back({ i.second,
                    i.first });
            sort(v.begin(), v.end(), comp);
            vector<int> ans;
            for (auto i: v)
            {
                int times = i.first;
                while (times)
                {
                    ans.push_back(i.second);
                    times--;
                }
            }
            for(auto i : ans)
            cout<<i<<" ";
            cout<<endl;

}

int main() {
    int t = 0;
    cin>>t;
    while(t--)
    {
        int n = 0;
        cin>>n;
        vector<int>v(n,0);
        for(int i = 0;i<n;i++)
        cin>>v[i];
        dosort(v);
    }
	return 0;
}