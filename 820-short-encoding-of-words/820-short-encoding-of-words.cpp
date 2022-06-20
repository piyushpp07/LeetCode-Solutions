bool comp(string &a, string &b)
{
    return a.size() > b.size();
}
class Solution
{
    public:
        int minimumLengthEncoding(vector<string> &words)
        {
            unordered_map<string, int> mp;
            int ans = 0;
            sort(words.begin(), words.end(), comp);
            for (int i = 0; i < words.size(); i++)
            {
                mp[words[i]]++;
            }

           	//For each word if it exist in hash map then add its length+1 to ans as # is also included.
            for (int i = 0; i < words.size(); i++)
            {
                int k = words[i].size();
                if (mp[words[i]] > 0)
                {
                    ans += (k + 1);
                }

               	//Deleting record of any suffix of the word from hash map as it is already covered.
                for (int j = k - 1; j >= 0; j--)
                {
                    string s = words[i].substr(j, k - j);
                    mp[s] = 0;
                }
            }
            return ans;
        }
};