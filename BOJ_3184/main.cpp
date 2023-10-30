#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int r, c;
vs bd;

int ansO, ansV;
vvb visit;
const auto dx = vi{ -1,1,0,0 };
const auto dy = vi{ 0,0,-1,1 };
void dfs(int i, int j) {
	auto st = stack<pii>{};
	st.push({ i, j });
	visit[i][j] = true;

	auto ctO = 0;
	auto ctV = 0;
	while (!st.empty()) {
		const auto [y, x] = st.top();
		st.pop();

		if ('o' == bd[y][x]) {
			++ctO;
		}
		else if ('v' == bd[y][x]) {
			++ctV;
		}

		for (auto d = 0; d < 4; ++d) {
			const auto ny = y + dy[d];
			const auto nx = x + dx[d];

			if (ny < 0 || r <= ny ||
				nx < 0 || c <= nx) {
				continue;
			}

			if ('#' == bd[ny][nx]) {
				continue;
			}

			if (visit[ny][nx]) {
				continue;
			}

			st.push({ ny, nx });
			visit[ny][nx] = true;
		}
	}

	if (ctV < ctO) {
		ansO += ctO;
	}
	else {
		ansV += ctV;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> r >> c;

	bd = vs(r);
	for (auto&& s : bd) {
		cin >> s;
	}

	ansO = 0;
	ansV = 0;
	visit = vvb(r, vb(c, false));
	for (auto i = 0; i < r; ++i) {
		for (auto j = 0; j < c; ++j) {
			if (visit[i][j]) {
				continue;
			}

			if ('#' == bd[i][j]) {
				continue;
			}

			dfs(i, j);
		}
	}

	cout << ansO << ' ' << ansV;

	return 0;
}