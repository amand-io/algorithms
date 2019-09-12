#include <bits/stdc++.h>
#define MAX 400400

using namespace std;

struct AHO {
    int c = 1;
    int to[MAX][26];
    int fail[MAX];
    
    void init(){
        memset(to, 0, sizeof to);
        memset(fail, 0, sizeof fail);
    }
    int add(const string &str) {
    	int on = 0;
    	for(auto ch : str) {
    		if(to[on][ch-'a'] == 0) {
    			to[on][ch-'a'] = c++;
    		}
    		on = to[on][ch-'a'];
    	}
    	return on;
    }
    
    void build() {
    	queue<int> que;
    	que.push(0);
    	while(!que.empty()) {
    		int on = que.front();
    		que.pop();
    		for(int i = 0; i < 26; i++) {
    			if(to[on][i]) {
    				fail[to[on][i]] = on == 0 ? 0 : to[fail[on]][i];
    				que.push(to[on][i]);
    			} else {
    				to[on][i] = to[fail[on]][i];
    			}
    		}
    	}
    }
} dict;

struct BIT {} tree;

vector<int> edges[MAX];
int in[MAX], out[MAX], tt = 0;

// make a graph of fails
void dfs(int on) {
	in[on] = tt++;
	for(auto too : edges[on]) {
		dfs(too);
	}
	out[on] = tt;
}

int ans[MAX];
vector<pair<int, int>> graph2[MAX];
vector<pair<int, int>> qries[MAX];

// count the number of occurrences of string t in si
void solve(int on, int st) {
	tree.upd(in[st]+1, 1);
	for(auto e : graph2[on]) {
		solve(e.first, dict.to[st][e.second]);
	}
	for(auto q : qries[on]) {
		ans[q.first] = tree.qry(out[q.second]) - tree.qry(in[q.second]);
	}
	tree.upd(in[st]+1, -1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	dict.init();
	for(int i = 1; i <= n; i++) {
		int t; cin >> t;
		char ch;
		int ha;
		if(t == 1) {
			cin >> ch;
			ha = 0;
		} else {
			cin >> ha >> ch;
		}
		graph2[ha].emplace_back(i, ch-'a');
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int on; cin >> on;
		string str; cin >> str;
		qries[on].emplace_back(i, dict.add(str));
	}
	dict.build();
	for(int i = 1; i < dict.c; i++) {
		edges[dict.fail[i]].push_back(i);
	}
	dfs(0);
	tree.init(dict.c + 10);
	solve(0, 0);
	for(int i = 0; i < m; i++) {
		cout << ans[i] << '\n';
	}
}