## Introductory Problems

### [Weird Algorithm](https://cses.fi/problemset/task/1068)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    while (n != 1)
    {
        cout << n << ' ';
        if (n&1) n = n*3 + 1;
        else n /= 2;
    }
    cout << "1\n";
    return 0;
}
```

### [Missing Number](https://cses.fi/problemset/task/1083)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    int sm = 0;
    for (int i = 0; i < n-1; ++i) { int x; cin >> x; sm += x; }
    cout << ((n*(n+1))/2 - sm) << '\n';
    return 0;
}
```

### [Repetitions](https://cses.fi/problemset/task/1069)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    int ans = 1;
    for (int i = 1, cnt = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i-1]) { cnt++; ans = max(ans, cnt); }
        else cnt = 1;
    }
    cout << ans << '\n';
    return 0;
}
```

### [Increasing Array](https://cses.fi/problemset/task/1094)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vec<1, int> arr(n);
    for (auto &x : arr) cin >> x;
    int ans = 0;
    for (int i = 1; i < n; ++i)
        if (arr[i] < arr[i-1]) { ans += (arr[i-1]-arr[i]); arr[i] = arr[i-1]; }
    cout << ans << '\n';
    return 0;
}
```

### [Permutations](https://cses.fi/problemset/task/1070/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    if (n == 1) cout << "1\n";
    else if (n < 4) cout << "NO SOLUTION\n";
    else
    {
        for (int i = 2; i <= n; i += 2) cout << i << " ";
        for (int i = 1; i <= n; i += 2) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
```

### [Number Spiral](https://cses.fi/problemset/task/1071/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int y, x; cin >> y >> x;
        int k = max(x, y);
        int ans = (k-1)*(k-1);
        if (k&1) ans += (x + (k-y));
        else ans += (y + (k-x));
        cout << ans << '\n';
    }
    return 0;
}
```

### [Two Knights](https://cses.fi/problemset/task/1072/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int res = ((i-1)*(i+4)*(i*i - 3*i + 4)) / 2;
        cout << res << '\n';
    }
    return 0;
}
```

### [Two Sets](https://cses.fi/problemset/task/1092/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    if ((n * (n+1)) % 4 == 0)
    {
        cout << "YES\n";
        set<int> a, b;
        for (int i = 1; i <= n; ++i) a.insert(i);
        int x = (n*(n+1))/4;
        
        for (int i = n; i >= 1; --i)
            if (i <= x) { x -= i; a.erase(i); b.insert(i); }
        cout << a.size() << '\n';
        for (auto &x : a) cout << x << " "; cout << '\n';
        cout << b.size() << '\n';
        for (auto &x : b) cout << x << " "; cout << '\n';
    }
    else cout << "NO\n";
    return 0;
}
```

### [Bit Strings](https://cses.fi/problemset/task/1617/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    cout << powMod(2, n) << '\n';
    return 0;
}
```

### [Trailing Zeros](https://cses.fi/problemset/task/1618/)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    int ans = 0;
    for (int x = 5; x <= n; x *= 5)
        ans += (n/x);
    cout << ans << '\n';
    return 0;
}
```

### [Coin Piles](https://cses.fi/problemset/task/1754)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        if ((2*a - b)%3 == 0 && (2*b - a)%3 == 0)
        {
            int x = (2*a - b)/3, y = (2*b - a)/3;
            if (x >= 0 && y >= 0 && x <= min(a, b) && y <= min(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
```

### [Palindrome Reorder](https://cses.fi/problemset/task/1755)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    vec<1, int> cnt(26, 0);
    for (auto &x : str) cnt[x-'A']++;
    bool allow = (str.size()%2 == 1);
    string side, m = "";
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i] == 0) continue;
        if (cnt[i]&1)
        {
            if (allow) { allow = false; m = string(cnt[i], ('A'+i)); }
            else { cout << "NO SOLUTION\n"; return 0; }
        }
        else side += string(cnt[i]/2, ('A'+i));;
    }
    string otherSide = side;
    reverse(otherSide.begin(), otherSide.end());
    cout << (side + m + otherSide) << '\n';
    return 0;
}
```

### [Creating Strings I](https://cses.fi/problemset/task/1622)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    sort(str.begin(), str.end());
    vector<string> res;
    do { res.push_back(str); }
    while (next_permutation(str.begin(), str.end()));
    cout << res.size() << '\n';
    for (auto &x : res) cout << x << '\n';
    return 0;
}
```

### [Apple Division](https://cses.fi/problemset/task/1623)

```cpp
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vec<1, int> arr(n);
    int sm = 0;
    for (auto &x : arr) { cin >> x; sm += x; }
    int res = INT_MAX;
    for (int i = 1; i < (1<<n); ++i)
    {
        int x = 0, y = 0, cur = i, pos = 0;
        while (cur)
        {
            if (cur&1) x += arr[pos];
            pos++; cur >>= 1;
        }
        y = sm-x;
        res = min(res, abs(y-x));
    }
    cout << res << '\n';
    return 0;
}
```

### [Chessboard and Queens](https://cses.fi/problemset/task/1624)

```cpp
vec<2, bool> board(8, 8);
int solve(int j = 0, int x = 0, int d1 = 0, int d2 = 0)
{
    if (j == 8) return 1;
    int res = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (board[i][j] && !(x&(1<<i)) && !(d1&(1<<(i+j))) && !(d2&(1<<(i-j+8))))
            res += solve(j+1, (x|(1<<i)), (d1|(1<<(i+j))), (d2|(1<<(i-j+8))));
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 0; i < 8; ++i)
    {
        string str; cin >> str;
        for (int j = 0; j < 8; ++j) board[i][j] = (str[j] != '*');
    }
    cout << solve() << '\n';
    return 0;
}
```

### [Grid Paths](https://cses.fi/problemset/task/1625)

Regular backtracking will time limit, requires pruning.

* If we reached last pos before last move then return 0
* If we hit a wall from where left and right both sides are unvisited then no matter which we will visit other will be unvisited so return 0.

```cpp
const int N = 7;
bool visited[N][N];
int dx[] = {0, +1, 0, -1}, dy[] = {-1, 0, +1, 0};
int solve(string &str, int cur = 0, int y = 0, int x = 0)
{
    if (y == N-1 && x == 0) return (cur == (N*N - 1));
    if (((y+1 == N || (visited[y-1][x] && visited[y+1][x])) && x-1 >= 0 && x+1 < N && !visited[y][x-1] && !visited[y][x+1]) ||
        ((x+1 == N || (visited[y][x-1] && visited[y][x+1])) && y-1 >= 0 && y+1 < N && !visited[y-1][x] && !visited[y+1][x]) ||
        ((y == 0 || (visited[y+1][x] && visited[y-1][x])) && x-1 >= 0 && x+1 < N && !visited[y][x-1] && !visited[y][x+1]) ||
        ((x == 0 || (visited[y][x+1] && visited[y][x-1])) && y-1 >= 0 && y+1 < N && !visited[y-1][x] && !visited[y+1][x]))
        return 0;

    visited[y][x] = true;
    int res = 0;
    for (int i = 0; i < 4; ++i)
    {
        if ((str[cur] == 'U' && i != 0) || (str[cur] == 'R' && i != 1) ||
            (str[cur] == 'D' && i != 2) || (str[cur] == 'L' && i != 3)) continue;
        int _y = y+dy[i], _x = x+dx[i];
        if (_y >= 0 && _x >= 0 && _y < N && _x < N && !visited[_y][_x]) res += solve(str, cur+1, _y, _x);
    }
    visited[y][x] = false;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    cout << solve(str) << '\n';
    return 0;
}
```
