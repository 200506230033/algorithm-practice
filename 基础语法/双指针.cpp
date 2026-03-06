#include<bits/stdc++.h>
using namespace std;

/*
----------------------------------------
蓝桥1371
回文判断
----------------------------------------
*/
bool ifhuiwen(const string& s){
  int left = 0;
  int right = s.size() - 1;

  while(left < right){
    if(s[left] != s[right])
        return false;

    left++;
    right--;
  }

  return true;
}

void lanqiao1371(){
  string s;
  cin >> s;
  cout << (ifhuiwen(s) ? 'Y' : 'N') << endl;
}


/*
----------------------------------------
蓝桥1372
美丽的区间
----------------------------------------
*/
void lanqiao1372(){
    const int N = 1e5 + 10;
    int a[N];

    int n, S;
    cin >> n >> S;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int l = 1, r = 1;
    int sum = 0;
    int ans = 1e9;

    while(r <= n){
        sum += a[r];

        while(sum >= S){
            ans = min(ans, r - l + 1);
            sum -= a[l];
            l++;
        }

        r++;
    }

    if(ans == 1e9)
        cout << 0 << endl;
    else
        cout << ans << endl;

}

/* 
----------------------------------------
蓝桥1621
挑选子串
----------------------------------------
*/
void lanqiao1621(){
    const int N = 1e5 + 10;
    int a[N];

    int n,m,k;
    cin >> n >> m >> k;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    int l = 0;
    int cnt = 0;
    long long ans = 0;

    for(int r = 0 ; r < n ; r++){

        if(a[r] >= m) cnt++;

        while(cnt >= k){

            // 以 l 为起点，r 及以后都合法
            ans += n - r;

            if(a[l] >= m) cnt--;
            l++;
        }
    }

    cout << ans << endl;
}


int main(){
  lanqiao1371();
  lanqiao1372();
  lanqiao1621();
}