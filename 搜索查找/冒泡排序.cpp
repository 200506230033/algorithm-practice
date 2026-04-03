#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
int a[N];

int main(){
    int n;
    cin >> n;
    //输入数组
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    //排序
    for(int i = n ; i >= 1; --i){
        for(int j = 0 ; j < i - 1 ; ++j){
            if(a[j] > a[j + 1]){
                swap(a[j] , a[j + 1]);
            }
        }
    }
    //输出结果
    for(int i = 0 ; i < n ; ++i){
        cout << a[i] << " ";
    }
    return 0;
}