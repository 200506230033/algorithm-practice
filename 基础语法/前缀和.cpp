#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n + 1], sum[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << endl;
    return 0;
}



//蓝桥3419,3382