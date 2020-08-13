## Dynamic Programming

### [Dice Combinations](https://cses.fi/problemset/task/1633/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> dp(n+1, 0);
	dp[0] = 1;
	for (int i = 0; i <= n; ++i)
	{
		if (dp[i] == 0) continue;
		for (int j = i+1; j <= min(i+6, n); ++j) (dp[j] += dp[i]) %= MOD;
	}
	cout << dp[n] << '\n';
	return 0;
}
```

### [Minimizing Coins](https://cses.fi/problemset/task/1634/)

```cpp
#define INF (1LL<<30)
vec<2, int> dp(105, 1000005, INF);
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;

	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 0; j <= x; ++j)
		dp[i][j] = (j < arr[i-1]) ? dp[i-1][j] : min(dp[i-1][j], 1 + dp[i][j-arr[i-1]]);
	if (dp[n][x] == INF) cout << "-1\n";
	else cout << dp[n][x] << '\n';
	return 0;
}
```

### [Coin Combinations I](https://cses.fi/problemset/task/1635/)

```cpp
vec<1, int> dp(1000005, 0);
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;

	dp[0] = 1;
	for (int i = 0; i < x; ++i)
		for (int j : arr)
			if (i+j <= x) (dp[i+j] += dp[i]) %= MOD;
	cout << dp[x] << '\n';
	return 0;
}
```

### [Coin Combinations II](https://cses.fi/problemset/task/1636/)

```cpp
/* We want to make this type of dp now (eg: [2 3 5] 9)
          0 1 2 3 4 5 6 7 8 9
2    -    1 0 1 0 1 0 1 0 1 0 
3    -    1 0 1 1 1 1 2 1 2 2 
5    -    1 0 1 1 1 2 2 2 3 3 */
vec<1, int> dp(1000005, 0);
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;

	dp[0] = 1;
	for (int j : arr)
		for (int i = 0; i < x; ++i)
			if (i+j <= x) (dp[i+j] += dp[i]) %= MOD;
	cout << dp[x] << '\n';
	return 0;
}
```

### [Removing Digits](https://cses.fi/problemset/task/1637/)

```cpp
#define INF (1<<30)
vec<1, int> dp(1000005);
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i <= 9; ++i) dp[i] = 1;
	for (int i = 10; i <= n; ++i)
	{
		int x = i;
		dp[i] = INF;
		while (x)
		{
			dp[i] = min(dp[i], 1 + dp[i - (x%10)]);
			x /= 10;
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
```

### [Grid Paths](https://cses.fi/problemset/task/1638/)

```cpp
vec<2, int> dp(1005, 1005);
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str; cin >> str;
		for (int j = 0; j < n; ++j) dp[i][j] = (str[j] == '*') ? -1 : 0;
	}
	dp[0][0] = (dp[0][0] != -1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 && j == 0) continue;
			if (dp[i][j] == -1) { dp[i][j] = 0; continue; }
			if (i-1 >= 0) (dp[i][j] += dp[i-1][j]) %= MOD;
			if (j-1 >= 0) (dp[i][j] += dp[i][j-1]) %= MOD;
		}
	}
	cout << dp[n-1][n-1] << '\n';
	return 0;
}
```

### [Book Shop](https://cses.fi/problemset/task/1158/)

```cpp
vec<2, int> dp(1005, 100005, 0);
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	vec<1, int> h(n), s(n);
	for (auto &x : h) cin >> x;
	for (auto &x : s) cin >> x;

	for (int j = h[0]; j <= x; ++j) dp[0][j] = s[0];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= x; ++j)
			dp[i][j] = (j < h[i]) ? dp[i-1][j] : max(dp[i-1][j], s[i] + dp[i-1][j-h[i]]);
	cout << dp[n-1][x] << '\n';
	return 0;
}
```

### [Array Description](https://cses.fi/problemset/task/1746/)

```cpp
vec<2, int> dp(105, 100005, -1);
int solve(int &m, vec<1, int> &arr, int prev = -1, int cur = 0)
{
	if (cur == arr.size()) return 1;
	if (cur != 0 && arr[cur] != 0 && abs(arr[cur]-prev) > 1) return 0;
	if (dp[prev+1][cur] != -1) return dp[prev+1][cur];

	int res = 0;
	if (arr[cur] == 0)
	{
		if (cur == 0)
		{
			for (int i = 1; i <= m; ++i)
				(res += solve(m, arr, i, cur+1)) %= MOD;
		}
		else
		{
			for (int i : {prev-1, prev, prev+1})
				if (i >= 1 && i <= m) (res += solve(m, arr, i, cur+1)) %= MOD;
		}
	}
	else (res += solve(m, arr, arr[cur], cur+1)) %= MOD;
	return dp[prev+1][cur] = res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;
	cout << solve(m, arr) << '\n';
	return 0;
}
```

### [Edit Distance](https://cses.fi/problemset/task/1639/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string x, y; cin >> x >> y;
	int n = x.size(), m = y.size();
	vec<2, int> dp(n+1, m+1);
	dp[0][0] = 0;
	for (int j = 1; j <= m; ++j) dp[0][j] = j;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j] = (x[i-1] == y[j-1]) ? dp[i-1][j-1] : min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
	cout << dp[n][m] << '\n';
	return 0;
}
```

### [Rectangle Cutting](https://cses.fi/problemset/task/1744/)

```cpp
#define INF (1<<30)
vec<2, int> dp(505, 505, -1);
int solve(int x, int y)
{
	if (x == y) return 0;
	if (x == 2*y || y == 2*x) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	int res = INF;
	for (int i = 1; i <= x/2; ++i)
		res = min(res, 1 + solve(i, y) + solve(x-i, y));
	for (int i = 1; i <= y/2; ++i)
		res = min(res, 1 + solve(x, i) + solve(x, y-i));
	return dp[x][y] = res;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int x, y; cin >> x >> y;
	cout << solve(x, y) << '\n';
	return 0;
}
```

#### Alternative Solution Rectangle Cutting
```cpp
//Complexity O(a*a*b + b*b*a)
#define lim 1e9+7
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
	fastio
	int a,b;
	cin>>a>>b;
	int dp[a+1][b+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(i==j)
				dp[i][j]=0;
 
			else
			{	
				dp[i][j]=lim;
				for(int k=1;k<i;k++)
				{
					dp[i][j] = min(dp[i-k][j]+dp[k][j]+1,dp[i][j]);
				}
			
				for(int k=1;k<j;k++)
					dp[i][j] = min(dp[i][j],dp[i][j-k]+dp[i][k]+1);
			}
		}
	}
 
	cout<<dp[a][b]<<endl;
}
```


### [Money Sums](https://cses.fi/problemset/task/1745/)

```cpp
vec<2, bool> dp(105, 100005, false);
set<int> st;
void solve(vec<1, int> &arr, int cur = 0, int sm = 0)
{
	if (dp[cur][sm]) return;
	if (cur == arr.size()) { st.insert(sm); return; }

	solve(arr, cur+1, sm + arr[cur]);
	solve(arr, cur+1, sm);
	dp[cur][sm] = true;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;
	solve(arr);
	st.erase(0);
	cout << st.size() << '\n';
	for (auto &x : st) cout << x << " ";
	return 0;
}
```

### [Removal Game](https://cses.fi/problemset/task/1097/)

```cpp
vec<2, pii> dp(5005, 5005, make_pair(0, 0));
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> dp[i][i].F;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0, k = i; k < n; ++j, ++k)
		{
			pii x = {dp[j][j].F + dp[j+1][k].S, dp[j][j].S + dp[j+1][k].F};
			pii y = {dp[k][k].F + dp[j][k-1].S, dp[k][k].S + dp[j][k-1].F};
			dp[j][k] = (x.F > y.F) ? x : y;
		}
	}
	cout << dp[0][n-1].F << '\n';
	return 0;
}
```

### [Two Sets II](https://cses.fi/problemset/task/1093/)

```cpp
vec<2, int> dp(505, 250005, -1);
int solve(int &n, int &m, int cur = 1, int sm = 0)
{
	if (cur == n) return (sm == m);
	if (dp[cur][sm] != -1) return dp[cur][sm];

	int res = 0;
	(res += solve(n, m, cur+1, sm)) %= MOD;
	(res += solve(n, m, cur+1, sm+cur)) %= MOD;
	return dp[cur][sm] = res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int m = (n*(n+1))/2;
	if (m&1) cout << "0\n";
	else
	{
		m /= 2;
		cout << solve(n, m) << '\n';
	}
	return 0;
}
```

### [Increasing Subsequence](https://cses.fi/problemset/task/1145/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;
	set<int> st;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (st.lower_bound(arr[i]) != st.end())
			st.erase(st.lower_bound(arr[i]));
		st.insert(arr[i]);
	}
	cout << st.size() << '\n';
	return 0;
}
```

### [Projects](https://cses.fi/problemset/task/1140/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, tuple<int, int, int>> arr(n);
	for (auto &x : arr) { int s, e, w; cin >> s >> e >> w; x = {e, s, w}; }
	sort(all(arr));

	vec<1, int> dp(n);
	dp[0] = get<2>(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		int e = get<0>(arr[i]), s = get<1>(arr[i]), w = get<2>(arr[i]);
		int optimal = lower_bound(all(arr), make_tuple(s, 0, 0)) - arr.begin() - 1;
		if (optimal >= 0) dp[i] = max({dp[i-1], dp[optimal] + w, w});
		else dp[i] = max(dp[i-1], w);
	}
	cout << dp[n-1] << '\n';
	return 0;
}
```