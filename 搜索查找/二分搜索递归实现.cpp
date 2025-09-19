#include<iostream>
using namespace std;


int binarySearch(int arr[] , int i , int  j , int value){
    if( i  > j ){
        return -1;
    }
    int mid = i + ( j - i ) / 2;
    if( arr[mid] == value ){
        return mid;
    }else if( arr[mid] < value ){
        return binarySearch(arr, mid + 1 , j , value);
    }else{
        return binarySearch(arr, i , mid - 1 , value);
    }
}


int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;
    int result = binarySearch(arr, 0, size - 1, target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    }else{
        cout << "Element not found in the array." << endl;
    }
    return 0;
}