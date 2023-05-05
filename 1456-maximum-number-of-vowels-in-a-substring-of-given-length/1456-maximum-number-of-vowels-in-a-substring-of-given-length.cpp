class Solution {
public:
    bool isVowel(int no)
    {
        char ch = no + 'a';
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int mp[26] = {0};
        for(;i<k;i++)
        {
            mp[s[i]-'a']++;
        }
        int j = 0;
        int ans = 0, cnt = 0;
        while(i<n)
        {
            cnt = 0;
            for(int k = 0;k<26;k++)
            {
                if(mp[k] && isVowel(k))
                   cnt+=mp[k];
            }
            ans = max(cnt,ans);
            mp[s[j++]-'a']--;
            mp[s[i++]-'a']++;
        }
        cnt = 0;
            for(int j = 0;j<26;j++)
            {
                if(mp[j] && isVowel(j))
                   cnt+= mp[j];
            }
            ans = max(cnt,ans);
        return ans;

      }
};