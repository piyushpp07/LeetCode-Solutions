//Keep Calm and जय श्री राम
#include<bits/stdc++.h>
using namespace std;
#define lli                         long long int
#define vi                          vector<int>
#define pii                          pair<int,int>
#define all(v)                      v.begin(),v.end()
#define getunique(v)                {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pb                          push_back
#define ff                          first
#define ss                          second
#define endl                        "\n"
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(NULL)
#define inf 0x7fffffff
const lli INF = 1e18;
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
{
	return b == 0 ? a : gcd(b, a % b);
}


int csb(int n )
{
	return  __builtin_popcount(n);
}
int isPrime(int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}
// code starts here
bool coprime(int a, int b)
{
	return (__gcd(a, b) == 1);
}

lli ans = 0;
pii tree[4000001];
vi a(4000001, 0);
pair<int, int> combine(pii m, pii b)
{
	if (m.first > b.first)
		return b;
	else if (m.first < b.first)
		return m;
	else
		return {m.first, m.second + b.second};
}
void build(int n, int tl, int tr)
{
	if (tl == tr)
		tree[n] = {a[tl], 1};
	else {
		int tm = (tl + tr) / 2;
		build(2 * n, tl, tm);
		build(2 * n + 1, tm + 1, tr);
		tree[n] = combine(tree[2 * n], tree[2 * n + 1]);
	}
}
void update(int n, int tl, int tr, int pos, int new_val)
{
	if (tl == tr)
		tree[n] = {new_val, 1};
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(2 * n, tl, tm, pos, new_val);
		else
			update(2 * n + 1, tm + 1, tr, pos, new_val);
		tree[n] = combine(tree[2 * n], tree[2 * n + 1]);
	}
}
pii minc(int n, int tl, int tr, int l, int r)
{
	if (l > r)
		return {INT_MAX, 0};
	else if (tl == l && tr == r)
		return tree[n];
	else {
		int mid = (tl + tr) / 2;
		pii a = minc(2 * n, tl, mid, l, min(r, mid));
		pii b = minc(2 * n + 1, mid + 1, tr, max(mid + 1, l), r);
		return combine(a, b);
	}

}


int main() {
	int n, q ;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n - 1);
	while (q--)
	{

		int t, l, r;
		cin >> t >> l >> r;
		if (t == 2)
		{
			pii ans =  minc(1, 0, n - 1 , l  , r - 1 ) ;
			cout << ans.first << " " << ans.second << endl;
		}
		else
		{
			update(1, 0, n - 1, l , r  );
		}
	}

}




