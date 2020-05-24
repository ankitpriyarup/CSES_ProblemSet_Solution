#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiset;
#define bug(args ...) cerr << __LINE__ << ">> ", err(new istringstream(string(#args)), args), cerr << '\n'
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define int ll
#define sz(x) (int)x.size()
typedef unsigned long long ull; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pll; typedef cc_hash_table<int, int, hash<int>> intHashTable; typedef tuple<int, int, int> tiii;
struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
inline int powMod(int a, int b) { int x = 1; while (b > 0) { if (b&1) x = (x*a) % MOD; a = (a*a) % MOD; b >>= 1; } return x; }
inline int multiply(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline int divide(int x, int y) { return ((x % MOD) * powMod(y % MOD, MOD-2)) % MOD; }
inline int ceil(int a, int b) { return (a+b-1)/b; }
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }
void err(istringstream *iss) {} template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) { string _name; *iss >> _name; if (_name.back()==',') _name.pop_back(); cerr << _name << " = " << _val << "; ", err(iss, args ...); }
int str_replace(string& str, const string& from, const string& to, int limit = -1) { if(from.empty()) return 0; size_t start_pos = 0; int cnt = 0; while((start_pos = str.find(from, start_pos)) != std::string::npos) { str.replace(start_pos, from.length(), to); start_pos += to.length(); cnt++; if (cnt == limit) break; } return cnt; }
template<int D, typename T> struct vec : public vector<vec<D - 1, T>> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    return 0;
}
