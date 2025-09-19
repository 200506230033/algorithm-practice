#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = left + (right - left) / 2; // 防止溢出
        if(arr[mid] == target){
            return mid; // 找到目标值，返回索引
        }else if(arr[mid] < target){
            left = mid + 1; // 目标值在右半部分
        }else{
            right = mid - 1; // 目标值在左半部分
        }
    }
    return -1; // 未找到目标值
}


int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = binarySearch(arr, size, target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    }else{
        cout << "Element not found in the array." << endl;
    }
    return 0;
}