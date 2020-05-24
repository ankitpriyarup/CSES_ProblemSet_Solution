## Sorting and Searching

### [Distinct Numbers](https://cses.fi/problemset/task/1621/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    set<int> st;
    int x;
    for (int i = 0; i < n; ++i) { cin >> x; st.insert(x); }
    cout << st.size() << '\n';
    return 0;
}
```

### [Apartments](https://cses.fi/problemset/task/1084/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    vec<1, int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a)); sort(all(b));
    int res = 0;
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (abs(a[i] - b[j]) <= k) i++, j++, res++;
        else if (a[i] > b[j]+k) j++;
        else i++;
    }
    cout << res << '\n';
    return 0;
}
```

### [Ferris Wheel](https://cses.fi/problemset/task/1090/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x; cin >> n >> x;
    vec<1, int> arr(n);
    for (auto &v : arr) cin >> v;
    sort(all(arr));
    int res = 0;
    for (int i = 0, j = n-1; i <= j; ++i, --j)
    {
        if (i == j) { res++; continue; }
        while (i < j && arr[i]+arr[j] > x) --j, ++res;
        res++;
    }
    cout << res << '\n';
    return 0;
}
```

### [Concert Tickets](https://cses.fi/problemset/task/1091/)

We want atmost x value for that we can add greater&lt;int&gt; comparator in our multiset making our lowerbound give atmost x instead of atleast x.

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    multiset<int, greater<int>> st;
    while (n--) { int x; cin >> x; st.insert(x); }
    while (m--)
    {
        int x; cin >> x;
        auto it = st.lower_bound(x);
        if (it == st.end()) cout << "-1\n";
        else { cout << *it << '\n'; st.erase(it); }
    }
    return 0;
}
```

### [Restaurant Customers](https://cses.fi/problemset/task/1619/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vec<1, pii> a(n);
    for (auto &x : a) cin >> x.F >> x.S;
    sort(all(a));
    priority_queue<int, vector<int>, greater<int>> pq;
    int res = 0;
    for (auto &x : a)
    {
        while (!pq.empty() && pq.top() < x.F) pq.pop();
        pq.push(x.S);
        res = max(res, (int)pq.size());
    }
    cout << res << '\n';
    return 0;
}
```

### [Movie Festival](https://cses.fi/problemset/task/1629/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vec<1, pii> a(n);
    for (auto &x : a) cin >> x.S >> x.F;
    sort(all(a));
    int prev = -1, res = 0;
    for (auto &x : a)
    {
        if (x.S < prev) continue;
        res++;
        prev = x.F;
    }
    cout << res << '\n';
    return 0;
}
```

### [Sum of Two Values](https://cses.fi/problemset/task/1640/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x; cin >> n >> x;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) { int v; cin >> v; a[i] = {v, i}; }
    sort(all(a));
    for (int i = 0, j = n-1; i < j;)
    {
        if (a[i].F + a[j].F == x) { cout << a[i].S+1 << " " << a[j].S+1 << '\n'; return 0; }
        if (a[i].F + a[j].F < x) i++;
        else j--;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
```

### [Maximum Subarray Sum](https://cses.fi/problemset/task/1643/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;
	vec<1, int> dp(n);
	dp[0] = arr[0];
	for (int i = 1; i < n; ++i) dp[i] = max(arr[i], dp[i-1]+arr[i]);
	cout << *max_element(all(dp)) << '\n';
	return 0;
}
```

### [Stick Lengths](https://cses.fi/problemset/task/1074/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> a(n);
	for (auto &x : a) cin >> x;
	sort(all(a));
	int m = a[n/2], res = 0;
	for (int i = 0; i < n; i++) res += abs(a[i]-m);
	cout << res << endl;
	return 0;
}
```

### [Playlist](https://cses.fi/problemset/task/1141/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;
	map<int, int> cnt;
	int res = 0;
	for (int i = 0, j = 0; j < n; ++j)
	{
		while (cnt[arr[j]] > 0) cnt[arr[i++]]--;
		cnt[arr[j]]++;
		res = max(res, j-i+1);
	}
	cout << res << '\n';
	return 0;
}
```

### [Towers](https://cses.fi/problemset/task/1073/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	multiset<int> st;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		auto it = st.upper_bound(x);
		if (it != st.end()) st.erase(it);
		st.insert(x);
	}
	cout << st.size() << '\n';
	return 0;
}
```

### [Traffic Lights](https://cses.fi/problemset/task/1163/)

Maintain a timeline initially 0------x then say a cut 0-----z z-----x  
We can represent it like this \(x, x\) -&gt; \(z, z\) \(x-z, x\)  
Here first means length of the segment and second means end point, if processed under a set rbegin first will store the desired result and processing can be done in logN. However to do processing we need to find segment with second atleast v \(query num\) for that we have to maintain a reverse set with first and second swapped.

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int x, n; cin >> x >> n;
	set<pii> a, b;
	a.insert({x, x}); b.insert({x, x});
	while (n--)
	{
		int v; cin >> v;
		auto it = a.lower_bound({v, 0});
		auto cur = *it;

		a.erase(it);
		a.insert({v, cur.S - (cur.F-v)});
		a.insert({cur.F, cur.F - v});

		b.erase({cur.S, cur.F});
		b.insert({cur.S - (cur.F-v), v});
		b.insert({cur.F - v, cur.F});

		cout << b.rbegin()->F << ' ';
	}
	cout << '\n';
	return 0;
}
```

### [Room Allocation](https://cses.fi/problemset/task/1164/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, pair<pii, int>> arr(n);
	for (int i = 0; i < n; ++i) { cin >> arr[i].F.F >> arr[i].F.S; arr[i].S = i; }
	sort(all(arr));

	set<int> rooms;
	for (int i = 1; i <= n; ++i) rooms.insert(i);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vec<1, int> res(n);
	int mx = 0;
	for (auto &x : arr)
	{
		while (!pq.empty() && pq.top().F < x.F.F) { rooms.insert(pq.top().S); pq.pop(); }
		int cur = *rooms.begin(); rooms.erase(cur);
		res[x.S] = cur;
		pq.push({x.F.S, cur});
		mx = max(mx, cur);
	}
	cout << mx << '\n';
	for (auto &x : res) cout << x << " "; cout << '\n';
	return 0;
}
```

### [Factory Machines](https://cses.fi/problemset/task/1620/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, t; cin >> n >> t;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;
	int l = -1, r = 1e18;
	auto check = [&](int mid)
	{
		int cur = 0;
		for (auto &x : arr)
		{
			cur += (mid/x);
			if (cur >= t) return true;
		}
		return false;
	};
	while (l+1 < r)
	{
		int mid = l + (r-l)/2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << r << '\n';
	return 0;
}
```

### [Tasks and Deadlines](https://cses.fi/problemset/task/1630/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, pii> arr(n);
	for (auto &x : arr) cin >> x.F >> x.S;
	sort(all(arr));
	int cur = 0, res = 0;
	for (auto &x : arr)
	{
		cur += x.F;
		res += (x.S - cur);
	}
	cout << res << '\n';
	return 0;
}
```

### [Reading Books](https://cses.fi/problemset/task/1631/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int mx = 0, sm = 0;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		mx = max(mx, x);
		sm += x;
	}
	cout << (mx > (sm-mx) ? 2*mx : sm) << '\n';
	return 0;
}
```

### [Sum of Three Values](https://cses.fi/problemset/task/1641/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	vec<1, pii> arr(n);
	for (int i = 0; i < n; ++i) { cin >> arr[i].F; arr[i].S = i+1; }
	sort(all(arr));
	for (int i = 0; i < n; ++i)
	{
		int reqd = x - arr[i].F;
		for (int j = i+1, k = n-1; j < k; )
		{
			if (arr[j].F+arr[k].F == reqd) { cout << arr[i].S << " " << arr[j].S << " " << arr[k].S << '\n'; return 0; }
			else if (arr[j].F+arr[k].F < reqd) ++j;
			else --k;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
```

### [Sum of Four Values](https://cses.fi/problemset/task/1642/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	vec<1, pii> arr(n);
	for (int i = 0; i < n; ++i) { cin >> arr[i].F; arr[i].S = i+1; }
	sort(all(arr));
	for (int p = 0; p < n; ++p)
	{
		for (int q = p+1; q < n; ++q)
		{
			int reqd = x - arr[p].F - arr[q].F;
			for (int r = q+1, s = n-1; r < s;)
			{
				if (arr[r].F+arr[s].F == reqd) { cout << arr[p].S << " " << arr[q].S << " " << arr[r].S << " " << arr[s].S << '\n'; return 0; }
				else if (arr[r].F+arr[s].F < reqd) ++r;
				else --s;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
```

### [Nearest Smaller Values](https://cses.fi/problemset/task/1645/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	deque<pii> dq;
	dq.push_back({INT_MIN, 0});
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		while (dq.back().F >= x) dq.pop_back();
		cout << dq.back().S << ' ';
		dq.push_back({x, i+1});
	}
	cout << '\n';
	return 0;
}
```

### [Subarray Sums I](https://cses.fi/problemset/task/1660/) \(and [Subarray Sums II](https://cses.fi/problemset/task/1661/)\)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	map<int, int> cnt;
	cnt[0]++;
	int sm = 0, res = 0;
	while (n--)
	{
		int v; cin >> v;
		sm += v;
		res += cnt[sm-x];
		cnt[sm]++;
	}
	cout << res << '\n';
	return 0;
}
```

### [Subarray Divisibility](https://cses.fi/problemset/task/1662/)

If we keep prefix sum, X denotes prefix sum at some point x and Y denotes prefix sum at some other point y. y is always &lt; x. Now we want \(X-Y\) % n = 0 for the condition to hold. opening it we have \(X%n - Y%n + n\) % n = 0.

So for a point we are simply looking for previously looking reqd var and adding its count.

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vec<1, int> arr(n+1); arr[0] = 0;
	map<int, int> cnt; cnt[0]++;
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		(arr[i] += arr[i-1]) %= n;
		if (arr[i] < 0) arr[i] += n;

		int reqd = (arr[i] + n) % n;
		res += cnt[reqd];

		cnt[arr[i]]++;
	}
	cout << res << '\n';
	return 0;
}
```

### [Array Division](https://cses.fi/problemset/task/1085/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;

	auto check = [&](int x)
	{
		int cur = 0, cnt = 0;
		for (auto &v : arr)
		{
			if (v > x) return false;
			if (cur+v > x) cnt++, cur = v;
			else cur += v;
		}
		if (cur) cnt++;
		return (cnt <= k);
	};

	int l = 0, r = accumulate(all(arr), 0LL);
	while (l+1 < r)
	{
		int mid = l + (r-l)/2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	cout << r << '\n';
	return 0;
}
```

### [Sliding Median](https://cses.fi/problemset/task/1076/)

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;

	orderedMultiset st;
	auto median = [&]() { return (k&1) ? *st.find_by_order(k/2) : (*st.find_by_order(k/2 - 1) + *st.find_by_order(k/2 - 1))/2; };
	for (int i = 0; i < k; ++i) st.insert(arr[i]);
	cout << median() << ' ';
	for (int i = k; i < n; ++i)
	{
		st.erase(st.upper_bound(arr[i-k]));
		st.insert(arr[i]);
		cout << median() << ' ';
	}
	cout << '\n';
	return 0;
}
```

### [Sliding Cost](https://cses.fi/problemset/task/1077/)

Extending the code of previous problem, we can iterate over k after finding median to find cost for first window now we have to find subsequent costs by some mathematical logic in constant time.

First thing we do is add abs\(m - arr\[i\]\) because that's the cost of new element to the window and remove abs\(oldM - arr\[i-k\]\) because that's the cost of old element. Now what about middle common one's?

![](res/image%20%2850%29.png)

Consider above \*artistic\* drawing. Median is nothing but distance first \(black\) was our median so red lines are distance sum of them is our cost. When we shift the median, individually their distances change but they will cancel out except one \(if it's odd element common otherwise there won't be any affect\). So we are checking k%2 \(k means k-1 common so if k is even we have common elements and we need to manually adjust it.

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vec<1, int> arr(n);
	for (auto &x : arr) cin >> x;

	orderedMultiset st;
	auto median = [&]() { return (k&1) ? *st.find_by_order(k/2) : (*st.find_by_order(k/2 - 1) + *st.find_by_order(k/2 - 1))/2; };
	for (int i = 0; i < k; ++i) st.insert(arr[i]);

	int oldM = median(), d = 0;
	for (int i = 0; i < k; ++i) d += abs(arr[i]-oldM);
	cout << d << ' ';
	for (int i = k; i < n; ++i)
	{
		st.erase(st.upper_bound(arr[i-k]));
		st.insert(arr[i]);
		int m = median();
		d += abs(m - arr[i]) - abs(oldM - arr[i-k]);
		if (k%2 == 0) d -= (m - oldM);
		oldM = m;
		cout << d << ' ';
	}
	cout << '\n';
	return 0;
}
```

### [Movie Festival II](https://cses.fi/problemset/task/1632/)

Extending traditional variant of this problem, multiset denotes persons last watch time initially zero we iterate over all movie and see if there's any person available with atmost current movie start time then take it. For atmost we just use greater comparator initially lower\_bound means atleast due to this comparator its atmost now.

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vec<1, pii> arr(n);
	for (auto &x : arr) cin >> x.S >> x.F;
	sort(all(arr));
	multiset<int, greater<int>> cur;
	while (k--) cur.insert(0);
	int res = 0;
	for (auto &x : arr)
	{
		auto it = cur.lower_bound(x.S);
		if (it != cur.end())
		{
				cur.erase(it);
				cur.insert(x.F);
				res++;
		}
	}
	cout << res << '\n';
	return 0;
}
```

### [Maximum Subarray Sum II](https://cses.fi/problemset/task/1644/)

If we keep prefix sum \(1 based keeping arr\[0\] = 0\) then at some point j we want to find a point i such that i is atleast a index away from b for that we will maintain a sliding window minimum of length k = b-a+1.

```cpp
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b; cin >> n >> a >> b;
	vec<1, int> arr(n+1);
	arr[0] = 0;
	for (int i = 1; i <= n; ++i) { cin >> arr[i]; arr[i] += arr[i-1]; }

	deque<int> dq;
	int k = b-a+1;
	int res = LONG_LONG_MIN;
	for (int i = 0, j = a; j <= n; ++i, ++j)
	{
		while (!dq.empty() && dq.front() < i-k+1) dq.pop_front();
		while (!dq.empty() && arr[i] < arr[dq.back()]) dq.pop_back();
		dq.push_back(i);
		res = max(res, arr[j]-arr[dq.front()]);
	}
	cout << res << '\n';
	return 0;
}
```