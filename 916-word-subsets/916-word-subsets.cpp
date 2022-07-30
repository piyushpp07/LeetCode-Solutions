class Solution
{
    public:
        vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
        {
            vector<int> arr(26, 0);
            for (int i = 0; i < words2.size(); i++)
            {
                vector<int> cnt2(26, 0);
                string q = words2[i];
                for (auto ch: q)
                    cnt2[ch - 'a']++;
                for (int j = 0; j < 26; j++)
                {
                    arr[j] = max(arr[j], cnt2[j]);
                }
            }
            vector<string> ans;
            for (int i = 0; i < words1.size(); i++)
            {
                string l = words1[i];
                vector<int> arr2(26, 0);
                bool flag = true;
                for (auto m: l)
                {
                    arr2[m - 'a']++;
                }
                for (int j = 0; j < 26; j++)
                {
                    if (arr2[j] < arr[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans.push_back(l);
            }
            return ans;
        }
};