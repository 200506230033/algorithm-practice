#include<iostream>
#include <cstring>
using namespace std;


//顺序栈

class SeqStack{
private:
  int *mpStack;
  int mtop;           //栈顶
  int mcap;           //空间


private:
  void expand(int size){
    int *p = new int[size];
    memcpy(p,mpStack,mtop*sizeof(int));
    delete[]mpStack;
    mpStack = p;
    mcap = size;
  }


public:
  SeqStack(int size = 10): mtop(0), mcap(size){
        mpStack = new int[mcap];
      }
  ~SeqStack(){
    delete[]mpStack;
    mpStack = nullptr;
  }


public:
//入栈
  void push(int val){
    if(mtop == mcap){
      expand(2*mcap);
    }
    mpStack[mtop++] = val;
  }

//出栈
  void pop(){
    if(mtop == 0){
      throw "Stack is empty!";
    }
    mtop--;
  }

//获取栈顶元素
  int top () const{
    if(mtop == 0){
      throw "Stack is empty!";
    }
    return mpStack[mtop - 1];
  }

//判断栈空
  bool empty() const {
    return mtop == 0;
  }

//栈元素个数
  int size() const {
    return mtop;
  }
};




int main(){ 
  SeqStack s;
  int arr[] = {12,4,56,7,89,31,53,75};

  for(int v : arr){
    s.push(v);
  }
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}