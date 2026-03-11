#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;
const ll p = 1e9 + 7;

ll feibonaqi1(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    return feibonaqi1(n - 1) + feibonaqi1(n - 2);
}

ll feibonaqi2(int n){
    if(n <= 2)return 1;
    return feibonaqi2(n - 1) + feibonaqi2(n - 2);
}


const int M = 20;
int a[M];
int dfs(int dep){
    int res = 1;
    for(int i = 1 ; i <= a[dep - 1] / 2 ; i++){
        a[dep] = i;
        res += dfs(dep + 1);
     }
    return res;
}




int main(){
    cout << feibonaqi1(10) << endl;
    cout << feibonaqi2(10) << endl;
    int n;
    cin >> n;
    a[1] = n;
    cout << dfs(2) << '\n';
    return 0;
}