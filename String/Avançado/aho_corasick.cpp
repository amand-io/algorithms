// by: Emiso
#include <bits/stdc++.h>
#define MAX 1000100
#define ALP 26

using namespace std;

int C(char c) { return c - 'a'; }

struct aho {
    int parent[MAX], suffix[MAX], to[MAX][ALP], super[MAX];
    char from[MAX];
    int id[MAX], cnt, built;
    long long ending[MAX], lazy[MAX];

    int new_node(int _parent = 0, char _from = ' ') {
        parent[cnt] = _parent; from[cnt] = _from; id[cnt] = -1;
        suffix[cnt] = super[cnt] = ending[cnt] = lazy[cnt] = 0;
        for(int i = 0; i < ALP; i++) to[cnt][i] = 0;
        return cnt++;
    }

    aho() {
        cnt = built = 0;
        new_node();
    }

    int add(string &word, int _id = 0) {
        int node = 0;
        for(int i = 0; i < word.size(); i++) {
            int nxt = C(word[i]);
            if(!to[node][nxt]) to[node][nxt] = new_node(node, word[i]);
            node = to[node][nxt];
        }
        ending[node]++;
        if(id[node] == -1) id[node] = _id;
        return id[node];
    }

    void build() {
        built = 1;
        queue<int> q;
        for(int i = 0; i < ALP; i++)
            if(to[0][i]) q.push(to[0][i]);

        while(!q.empty()) {
            int v = q.front(); q.pop();
            if(parent[v]) suffix[v] = to[suffix[parent[v]]][C(from[v])];

            if(id[v] != -1) super[v] = v;
            else super[v] = super[suffix[v]];

            ending[v] += ending[suffix[v]];
            for(int i = 0; i < ALP; i++) {
                if(!to[v][i]) to[v][i] = to[suffix[v]][i];
                else q.push(to[v][i]);
            }
        }
    }

    long long search_text(string &text) {
        if(!built) build();
        int prefix = 0;
        long long count = ending[0];
        for(char c : text) {
            prefix = to[prefix][C(c)];
            count += ending[prefix];
        }
        return count;
    }

    /// array of number of occurrences of pattern with id = i
    void search_text(string &text, int *ans) {
        if(!built) build();
        int prefix = 0;
        for(char c : text) {
            prefix = to[prefix][C(c)];
            for(int u = super[prefix]; u; u = super[suffix[u]])
                ans[id[u]]++;
        }
    }

    void search_text_linear(string &text, int *ans) { /// O(N+M)
        if(!built) build();
        int prefix = 0;
        for(char c : text) {
            prefix = to[prefix][C(c)];
            lazy[prefix]++;
        }
        push_lazy(ans);
    }

    void push_lazy(int *ans) {
        vector<int> deg(cnt, 0);
        for(int i = 1; i < cnt; i++)
            deg[suffix[i]]++;

        queue<int> fila;
        for(int i = 1; i < cnt; i++)
            if(deg[i] == 0) fila.push(i);

        while(!fila.empty()) {
            int u = fila.front(); fila.pop();

            if(id[u] != -1) ans[id[u]] += lazy[u];
            lazy[suffix[u]] += lazy[u];

            deg[suffix[u]]--;
            if(suffix[u] && deg[suffix[u]] == 0) fila.push(suffix[u]);
        }
    }
} dict;

int main() {
    string str = "aa";
    dict.add(str);

    str = "a";
    dict.add(str);

    dict.build();

    string cmon = "aaaaa";
    printf("%d\n", dict.search_text(cmon));
    return 0;
}