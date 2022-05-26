class Solution
{
private:
	int solve(vector<string> &arr, map<char, int> &mp, vector< int > &wt, int i, int n)
	{
		if (i == n)
		{
			return 0;
		}
		int a = 0, b = 0;
		map<char, int> ch = mp;
		int brk = 0;
		string s = arr[i];
		int temp = 0;
		for (int j = 0; j < s.size(); j++)
		{
			ch[s[j]]--;
			if (ch[s[j]] < 0)
			{
				brk = 1;
				break;
			}
			temp += wt[s[j] - 'a'];
		}
		if (brk == 0)
			a = temp + solve(arr, ch, wt, i + 1, n);
		b = solve(arr, mp, wt, i + 1, n);

		return max(a, b);
	}
public:
	int maxScoreWords(vector<string> &words, vector<char> &letters, vector< int > &score)
	{
		map<char, int> mp;
		int n = words.size();
		for (int i = 0; i < letters.size(); i++)
			mp[letters[i]]++;
		return solve(words, mp, score, 0, n);
	}
};