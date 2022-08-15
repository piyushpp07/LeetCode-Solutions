class Solution
{
    public:
        int romanToInt(string s)
        {
            int n = 0;
            if (s.size() == 0)
                return 0;
            unordered_map<char, int> table = {
		{
                    'I',
                    1
                },
                {
                    'V',
                    5
                },
                {
                    'X',
                    10
                },
                {
                    'L',
                    50
                },
                {
                    'C',
                    100
                },
                {
                    'D',
                    500
                },
                {
                    'M',
                    1000
                }
            };
            int no = 0;
            for (int i = 0; i < s.size() - 1; i++)
            {
                if (table[s[i]] < table[s[i + 1]])
                    no -= table[s[i]];
                else
                    no += table[s[i]];
            }
            no += table[s.back()];
            return no;
        }
};