#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int pre[N];


int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}


int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        pre[i] = i;
    }
    while(m--){
        int op , x , y;
        cin >> op >> x >> y;
        if(op == 1){
            pre[root(x)] = root(y);
        }else{
            cout << (root(x) == root(y) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}