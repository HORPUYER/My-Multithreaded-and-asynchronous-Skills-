#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
typedef long long ll;

#define int ll

const int LL_INF = int(1e17);
const int p = 31;
const int MAXN = (int)1e6;
const int mod = int(1e9) + 7;

vector<int> p_pow(MAXN);
vector<int> h;

int mul(int a, int b) {
	return (int)a * b % mod;
}

int add(int a, int b) {
	int res = (ll)a + b;
	while (res < 0)
		res += mod;
	while (res > mod)
		res -= mod;
	return (res % mod);
}

void count_pow() {
	p_pow[0] = 1;
	for (int i = 1; i < p_pow.size(); i++) {
		p_pow[i] = mul(p_pow[i - 1], p);
	}
}

void count_hash(string& s) {
	int sz = (int)s.size();
	h.clear();
	h.resize(sz);
	for (int i = 0; i < sz; i++) {
		h[i] = mul((s[i] - '0' + 1), p_pow[i]); if (i) h[i] = add(h[i], h[i - 1]);
	}
}
int get_substring_hash(int idx, int len) {
	// s[idx… idx + len - 1]
	int hash = h[idx + len - 1];
	if (idx) hash = add(hash, -h[idx - 1]);
	return hash;
}

unordered_map<char, string> sym; 
unordered_map<int, string> dict; 
unordered_map<int, string> enc;

void encode() {
	vector<string> st = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
	int cnt = 2;
	for (auto& s : st) {
		string add = to_string(cnt), res = add;
		int sz = int(s.size());
		for (auto& x : s) {
			sym[x] = res;
			res += add;
		}
		cnt++;
	}
}

string encode_string(string& s) {
	int sz = int(s.size());
	string res = "";
	for (int i = 0; i < sz; i++) res += sym[s[i]];
	return res;
}

void solve() {
	encode();
	count_pow();

	string s;
	cin >> s;
	int n = int(s.size());

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		string t;
		cin >> t;

		string code = encode_string(t);
		count_hash(code);
		int sz = int(code.size());

		int hash = h[sz - 1];
		dict[hash] = t;
		enc[hash] = code;
	}
	count_hash(s);
	vector<int> dp(n + 1, LL_INF);
	map<int, bool> is;
	is[-1] = 1;

	for (int i = 0; i < n; i++) {
		if (!is[i - 1]) continue;
		for (auto& [key, val] : enc) {
			int sz = int(val.size());
			if (i + sz - 1 >= n) continue;

			int h1 = get_substring_hash(i, sz), h2 = key;
			h2 = mul(h2, p_pow[i]);
			if (h1 == h2) {
				dp[i + sz - 1] = i;
				is[i + sz - 1] = 1;
			}
		}
	}
	vector<string> ans;
	int idx = n - 1;

	while (idx >= 0) {
		int st = dp[idx];
		string add = s.substr(st, idx - st + 1);
		count_hash(add);
		int hash = h[idx - st];
		ans.push_back(dict[hash]);

		idx = st - 1;
	}

	reverse(ans.begin(), ans.end());
	for (auto& x : ans) cout << x << " ";
	cout << "\n";
}

#undef int
int main() {
	solve();
	return 0;
}