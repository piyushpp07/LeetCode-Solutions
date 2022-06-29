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
vi tree(100001, 0);
vi a(100001, 0);
void build(int n, int tl, int tr)
{
	if (tl == tr)
		tree[n] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(2 * n, tl, tm);
		build(2 * n + 1, tm + 1, tr);
		tree[n] = min(tree[2 * n], tree[2 * n + 1]);
	}
}
void update(int n, int tl, int tr, int pos, int new_val)
{
	if (tl == tr)
		tree[n] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(2 * n, tl, tm, pos, new_val);
		else
			update(2 * n + 1, tm + 1, tr, pos, new_val);
		tree[n] = min(tree[2 * n], tree[2 * n + 1]);
	}
}
int minimum(int n, int tl, int tr, int l, int r)
{
	if (l > r)
		return INT_MAX;
	else if (tl == l && tr == r)
		return tree[n];
	else {
		int mid = (tl + tr) / 2;
		int a = minimum(2 * n, tl, mid, l, min(r, mid));
		int b = minimum(2 * n + 1, mid + 1, tr, max(mid + 1, l), r);
		return min(a, b);
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
		char a;
		int l, r;
		cin >> a >> l >> r;
		if (a == 'q')
		{
			cout << minimum(1, 0, n - 1 , l - 1 , r - 1 ) << endl;
		}
		else
		{
			update(1, 0, n - 1, l - 1, r  );
		}
	}

}





