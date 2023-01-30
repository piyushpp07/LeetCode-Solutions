class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int>ans;
        int k  = p.size(),cnt = 0;
        int arr[26];
        memset(arr,0,sizeof arr);
        sort(p.begin(),p.end());
        int i = 0, j = 0,n = s.size();
        while(j<n)
        {
            if(j>=k)
            {
                arr[s[j++]-'a']++;
            }
            while(j<k)
            {
                arr[s[j++]-'a']++;
            }
            string mu = "";
            for(int q = 0;q<26;q++)
            {
                for(int l  = 0;l<arr[q];l++)
                    mu+='a'+q;
            }
            if(mu == p)
                ans.push_back(i);
            arr[s[i++]-'a']--;
        }
        return ans;
    }
};