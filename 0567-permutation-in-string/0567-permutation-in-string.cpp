class Solution {
public:
    bool checkInclusion(string s2, string s) {
        if(s2.size()>s.size())
            return false;
        int k = s2.size();
        int i = 0,j = 0,n = s.size();
        int arr[26] = {0};
        sort(s2.begin(),s2.end());
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
            if(mu == s2)
                return true;
            arr[s[i++]-'a']--;
        }
        return false;
    }
};