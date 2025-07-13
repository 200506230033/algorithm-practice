#include<iostream>
#include<cstring>
#include<time.h>
#include<stdlib.h>

using namespace std;

// 数组实现
class Array{
private:
    int *mpArr;
    int mCap;  //指向可扩容的数组内存
    int mCur;   //数组有效元素的个数
public:
    Array(int size = 10): mCur(0) , mCap(size){
        mpArr = new int[mCap]();
    }
    ~Array(){
        delete[] mpArr;
        mpArr = nullptr;    
    };

private:
    //内部数组扩容接口
    void expand(int size){
        int *p = new int[size];
        memcpy(p , mpArr , sizeof(int) *mCur);
        delete []mpArr;

        mpArr = p;
        mCap = size;
    }


public:
//末尾增加元素
    void push_back(int val){
        if(mCur == mCap){
            expand(mCap * 2);
        }   
        mpArr[mCur++] = val;
    };
//末尾删除元素
    void pop_back(){
        if(mCur == 0){
            return ;
        }
        mCur--;
    };
//按位置增加元素
    void insert(int pos , int val){
        if(pos < 0 || pos > mCur){
            return ;
        }
        if(mCur == mCap){
            expand(mCap * 2);
        }
        for(int i = mCur - 1 ; i >= pos ; --i){
            mpArr[i + 1] = mpArr[i];
        }  
        mpArr[pos] = val;
        mCur++;
    };
//按元素删除
    void erase(int pos){
        if(pos < 0 || pos >=mCur){
            return ;
        }
        for(int i = pos ; i < mCur - 1 ; ++i){
            mpArr[i] = mpArr[i + 1];
        }
        mCur--;
    }
// 元素查询
    int find(int val){
        for(int i = 0 ; i < mCur ; i++){
            if(mpArr[i] == val){
                return i;
            }
        }
        return -1;
    }
// 打印数据
    void print(){
        for(int i = 0 ; i < mCur ; i++){
            cout << mpArr[i] << " ";
        }  
        cout << endl;
    }
};

int main(){
    Array arr;
    srand(time(0));
    for (int i = 0 ; i < 10 ; ++i){
        arr.push_back(rand() % 100);
    }
    arr.print();

    arr.pop_back();
    arr.print();

    arr.insert(0 , 100);
    arr.print();

    arr.insert(10 , 200);
    arr.print();

    int pos = arr.find(100);
    if(pos != -1){
        arr.erase(pos);
        arr.print();
    }

}
   