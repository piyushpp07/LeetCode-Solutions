//Keep Calm and जय श्री राम
#include<bits/stdc++.h>
using namespace std;
#define lli                         long long int
#define vi                          vector<int>
#define ii                          pair<int,int>
#define all(v)                      v.begin(),v.end()
#define getunique(v)                {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pb                          push_back
#define ff                          first
#define ss                          second
#define endl                        "\n"
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(NULL)
const int MS = 1000001;
const lli INF = 1e9 + 7;
bool isVowel(char ch )
{
	if (ch == 'A' || ch == 'O' || ch == 'Y' || ch == 'U' || ch == 'E' ||
	        ch == 'I' || ch == 'a' || ch == 'o' || ch == 'y'
	        || ch == 'u' || ch == 'i' || ch == 'e')
		return true;
	return false;
}

bool isUppercase(char ch)
{
	if (ch >= 65 && ch <= 90)
		return true;
	return false;
}

string decToBinary(int n)
{	string s = "";
	for (int i = 31; i >= 0; i--) {
		int k = n >> i;
		if (k & 1)
			s += '1';
		else
			s += '0';
	}
	return  s;
}

// cntrl alt f and cntl shift b

int gcd(int a, int b)
{return b == 0 ? a : gcd(b, a % b);}

int parent[100001]; // contains the parent of each node
int s[100001]; // union by size
multiset<int>sizes;
void make(int n)
{
	parent[n]  = n;
	s[n] = 1;
	sizes.insert(1);
}
int fi(int a)
{
	if (parent[a] == a)
		return a;
	// path compression
	return parent[a] = fi(parent[a]);
}
void Union(int a, int b)
{
	a = fi(a);
	b = fi(b);
	if (a != b)
	{	//union by size adding smaller node to larger one
		if (s[a] < s[b])
			swap(a, b);
		parent[b] = a;

		s[a] += b;
	}
}

int main()
{

	int n = 0, m = 0;
	cin >> n >> m;
	vector < pair<int, pair<int, int>>>v;
	for (int i =  0; i < m; i++)
	{
		int  a = 0, b = 0, wt = 0;
		cin >> a >> b >> wt;
		v.pb({wt, {a, b}});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		make(i);
	int mstwt = 0;
	for (auto i : v)
	{
		int wt = i.first;
		int a = i.second.first;
		int b = i.second.second;
		if (fi(a) == fi(b))
			continue;
		Union(a, b);
		mstwt += wt;
		cout << a << "->" << b << "->" << "weight " << wt << "->" << " mstwt = " << mstwt;
		cout << "\n";
	}

}




