#include <bits/stdc++.h>
#define MAX 200007
#define SIG 27
#define INI 'a'

using namespace std;
typedef long long ll;

struct AC {
	int next[MAX][SIG], fail[MAX];
	ll end[MAX], cnt[MAX];

	int root, L;
	int newNode() {
		for(int i = 0; i < SIG; i++) next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	void init() {
		L = 0;
		root = newNode();
	}
	void add(char buf[]) {
		int len = strlen(buf);
		int now = root;
		for(int i = 0; i < len; i++) {
			if(next[now][buf[i]-INI] == -1) next[now][buf[i]-INI] = newNode();
			now = next[now][buf[i]-INI];
		}
		end[now]++;
	}
	void build() {
		queue<int> que;
		fail[root] = root;
		for(int i = 0; i < SIG; i++) {
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				que.push(next[root][i]);
			}
		}
		while(!que.empty()) {
			int now = que.front();
			que.pop();
			for(int i = 0; i < SIG; i++) {
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					end[next[now][i]] += end[next[fail[now]][i]];
					que.push(next[now][i]);
				}
			}
		}
	}
	void matches(char buf[]) {
		int len = strlen(buf);
		int now = root;
		for(int i = 0; i < len; i++) {
			now = next[now][buf[i]-INI];
			cnt[i] = end[now];
		}
	}
	void debug() {
		for(int i = 0; i < L; i++) {
			printf("id = %3d, fail = %3d, end = %3d, chi = [", i, fail[i], end[i]);
			for(int j = 0; j < SIG; j++) printf("%2d", next[i][j]);
			printf("]\n");
		}
	}
};
 
AC ac;
int main() {
	ac.init(); ac.build();
    return 0;
}