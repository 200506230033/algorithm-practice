#include<bits/stdc++.h>
using namespace std;


const int N = 1e6 + 9;
char s[N], p[N];
int nex[N];


int main(){
    cin >> (p + 1);
    int m = strlen(p + 1);
    cin >> (s + 1);
    int n = strlen(s + 1);
//get the next array
    nex[0] = nex[1] = 0;
    for(int i = 2, j = 0; i <= m; ++i){
        while(j && p[i] != p[j + 1]){
            j = nex[j];
        }
        if(p[i] == p[j + 1]){
            ++j;
        }
        nex[i] = j;
    }
//模式串和文本串的匹配
    int ans = 0;
    for(int i = 1, j = 0; i <= n; ++i){
        while(j && s[i] != p[j + 1]){
            j = nex[j];
        }
        if(s[i] == p[j + 1]){
            ++j;
        }
        if(j == m){
            ans++;
            j = nex[j];
        }
    }
    cout << ans << endl;
    return 0;
}