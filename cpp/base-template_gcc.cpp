#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, begin, end) for(int i = begin; i < end; i++)
#define per(i, n) for(int i = n - 1; i >= 0; i--)
#define all(c) c.begin(), c.end()
#define cout(n) cout << fixed << setprecision(n)
#define si(x) int(x.size())
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

constexpr int INF = 1e9 + 7;
constexpr long long LINF = 1e18 + 1;

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template <class H> void debug(H &&h) {cout << h << endl;;}
template <class H, class... Ts> void debug(H &&h, Ts &&...ts) {cout << h << " ";debug(forward<Ts>(ts)...);}
template <typename T> void dv(vector<T> &a) {int siz = a.size();for(int i = 0; i < siz; i++) cout << a[i] << " ";cout << endl;}
template <typename T> void dvv(vector<vector<T>> &a) {int h = a.size();int w = a[0].size();rep(i, h) {rep(j, w) {cout << a[i][j];cout << " ";}cout << endl;}cout << endl;}
//-----------------------------------------------------------------------------------------------------------------

int main() {}
