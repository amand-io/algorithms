#include <bits/stdc++.h>
#define alpha 26

using namespace std;

struct node{
    int word[alpha], go[alpha];
    int link = -1;
    int parent = -1;
    char parentC;
    bool end = false; 

    node(int parent = -1, char parentC = '$') : parent(parent), parentC(parentC) {
        fill(word.begin(),word.end(), -1);
        fill(go.begin(),go.end(), -1);
    }
};

vector<node> ac(1);

void add(string s){
    int current = 0;
    for(int i = 0; i < s.size(); i++){
        int c = s[i]-'a';
        if(ac[current].word[c] == -1){
            ac[current].word[c] = ac.size();
            ac.emplace_back(current, s[i]);
        }

        current = ac[current].word[c];
    }
    ac[current].end = true;
}

int go(int v, char ch);

int link(int v){
    if(ac[v].link == -1){
        if(v == 0 || ac[v].parent == 0) ac[v].link = 0;
        else ac[v].link = go(link(ac[v].parent), ac[v].parentC);
    }
    return ac[v].link;
}

int go(int v, char ch){
    int c = ch-'a';
    if(ac[v].go[c] == -1){
        if(ac[v].next[c] != -1) ac[v].go[c] = ac[v].next[c];
        else ac[v].go[c] = v == 0 ? 0 : go(link(v), ch); 
    }
    return ac[v].go[c];
}
int main(){
    return 0;
}