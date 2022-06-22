bool comp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
}
class Solution
{
    public:
        string largestWordCount(vector<string> &messages, vector<string> &senders)
        {
            map<string, int> mp;
            int n = messages.size();
            for (int i = 0; i < messages.size(); i++)
            {
                string s = messages[i];
                int cnt = 1;

                for (int j = 0; j < s.size(); j++)
                {
                    if (s[j] == ' ')
                        cnt++;
                }
                mp[senders[i]] += cnt;
            }
            vector<pair<string, int>> cal;
            for (auto i: mp)
                cal.push_back(i);
            sort(cal.begin(), cal.end(), comp);
            return cal[0].first;
        }
};