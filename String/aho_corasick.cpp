#include <bits/stdc++.h>
#define MAX 1000007
#define SIG 27
#define INI '0'
using namespace std;

struct Aho{
    int states;
    int words[MAX][SIG];
    int out[MAX], fail[MAX];

    Aho(){
        states = 0;
        memset(out, 0, sizeof out);
        memset(fail, -1, sizeof fail);
        memset(words, -1, sizeof words);
    }

    void add(string &s){
        int curr = 0;
        for(int i = 0; i < s.size(); i++){
            int letter = s[i]-INI;
            if(words[curr][letter] == -1){
                words[curr][letter] = ++states;
            }

            curr = words[curr][letter];
        }

        out[curr] = 1;
    }

    void build(){
        queue<int> q;

        for(int i = 0; i < SIG; i++){
            if(words[0][i] == -1) words[0][i] = 0;
            else {
                fail[words[0][i]] = 0;
                q.push(words[0][i]);
            }
        }

        while(!q.empty()){
            int actual = q.front();
            q.pop();

            for(int i = 0; i < SIG; i++){
                int parent = words[actual][i];
                if(words[actual][i] != -1){
                    int failure = fail[actual];
                    while(words[failure][i] == -1) failure = fail[failure];

                    failure = words[failure][i];
                    fail[parent] = failure;
                    out[parent] |= out[failure];
                    q.push(parent);
                }
            }
        }
    }

    int next(int state, int letter){
        while(words[state][letter] == -1){
            state = fail[state];
        }
        return words[state][letter];
    }
};
Aho mine;
int main(){

    return 0;
}