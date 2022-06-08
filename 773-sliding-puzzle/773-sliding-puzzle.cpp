class Solution
{
    private:
        string swappos(int idx, int des, string tp)
        {
            string s = tp;
            swap(s[idx], s[des]);
            return s;
        }
    public:
        int slidingPuzzle(vector<vector < int>> &v1)
        {
            vector<vector < int>> vs = {
		{ 1,
                    3 },
                { 0,
                    2,
                    4 },
                { 1,
                    5 },
                { 0,
                    4 },
                { 1,
                    3,
                    5 },
                { 2,
                    4 }
            };
            int n = 2;
            int m = 3;
            string start = "";
            for (auto i: v1)
            {
                for (auto ch: i)
                {
                    start += to_string(ch);
                }
            }

            set<string> st;
            st.insert(start);
            queue<string> q;
            q.push(start);

            string dest = "123450";

            int level = 0;
            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    string tp = q.front();
                    q.pop();
                    if (tp == dest)
                        return level;
                    int idx = -1;
                    for (int i = 0; i < tp.size(); i++)
                    {
                        if (tp[i] == '0')
                        {
                            idx = i;
                            break;
                        }
                    }
                    for (int i = 0; i < vs[idx].size(); i++)
                    {
                        string sv = swappos(idx, vs[idx][i], tp);
                        if (st.find(sv) == st.end())
                        {
                            q.push(sv);
                            st.insert(sv);
                        }
                    }
                }
                level++;
            }
            return -1;
        }
};