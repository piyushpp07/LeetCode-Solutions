class Solution
{
    public:
        string mergeAlternately(string word1, string word2)
        {
            string t = "";
            int n = word1.size();
            int m = word2.size();
            int first = 0;
            int second = 0;
            for (int i = 0; i < n + m ; i++)
            {
                if (i % 2 == 0)
                {
                    if (first < n)
                    {
                        t += word1[first++];
                    }
                    else
                    {
                        t += word2[second++];
                    }
                }
                else
                {
                    if (second < m)
                    {
                        t += word2[second++];
                    }
                    else
                    {
                        t += word1[first++];
                    }
                }
            }
            return t;
        }
};