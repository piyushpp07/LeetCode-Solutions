class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>pre(26,0);
        vector<vector<int>>post(n,vector<int>(26,0));
        for(int i =n-1;i>=0;i--)
        {
            if(i == n-1)
                post[i][s[i]-'a']++;
            else{
                post[i] = post[i+1];
                post[i][s[i]-'a']++;
            }
        }
        int cnt = 0;
        vector<int>v;
        for(int i = 0;i<n;i++)
        {
            if(i == n-1)
            {
                cnt++;
                v.push_back(cnt);
                continue;
            }
            pre[s[i]-'a']++;
            cnt++;
            bool ans = true;
            for(int j = 0;j<26;j++)
            {
                if(pre[j]  && post[i+1][j] && pre[j]!=0)
                    ans = false;
            }
            if(ans)
            {
                v.push_back(cnt);
                vector<int>k(26,0);
                pre = k;
                cnt = 0;
            }
        }

        return v;
        
    }
};