#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];

// 修正后的 Partition 函数
int partition(int a[], int l, int r) {
    int pivot = a[r]; // 选择最右侧元素为基准
    int i = l - 1;    // i 指向小于等于 pivot 区域的最后一个元素

    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]); // 将 pivot 放到正确的位置
    return i + 1;
}

void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int mid = partition(a, l, r);
        QuickSort(a, l, mid - 1);
        QuickSort(a, mid + 1, r);
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; ++i) { // 建议习惯从 0 开始
        cin >> a[i];
    }

    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    return 0;
}
