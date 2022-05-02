class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
        if(s.size()==1)
            return 1;
        if(s.size()==0)
            return 0;
		for (int i = 0; i < s.size(); i++)
		{	int sz = 1;
			map<char, int>mp;
            mp[s[i]]++;
			for (int j = i + 1; j < s.size(); j++)
			{
				if (mp.find(s[j]) != mp.end())
				{
					break;
				}
				else {
					sz++;
					mp[s[j]]++;
				}

			}
			if (ans < sz)
				ans = sz;

		}
		return ans;
	}
};