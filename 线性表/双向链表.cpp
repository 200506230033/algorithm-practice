#include<iostream>
using namespace std;

struct Node{
    int data_;
    Node* next_;
    Node* pre_;

    Node(int data = 0)
        : data_(data)
        , next_(nullptr)  
        , pre_(nullptr)
    {}

};

class DoubleLink{
private:
    Node *head_ ;

public:
    DoubleLink(){
        head_ = new Node() ;
    }
    ~DoubleLink(){
        Node *p = head_ ;
        while( p != nullptr){
            head_ = head_ -> next_ ;
            delete p ;
            p = head_ ;
        }
    }

//头插法
    void InsertHead(int val){
        Node *node = new Node(val) ;
        node->next_ = head_->next_ ;
        node->pre_ = head_ ;
        if( head_ -> next_ != nullptr){
            head_ -> next_ -> pre_ = node ;
        }
        head_ -> next_ = node ;
    }

//尾插法
    void InsertTail(int val){
        Node* p = head_ ;
        while( p -> next_ != nullptr){
            p = p -> next_ ;
        }
        Node * node = new Node(val) ;
        node -> pre_ = p ;
        p -> next_ = node ;
    }

//节点删除
    void Remove(int val){
        Node* p = head_ -> next_ ;
        while( p != nullptr){
            if( p-> data_ = val){
                p -> pre_ -> next_ = p -> next_ ;
                if( p -> next_ != nullptr){
                p -> next_ -> pre_ = p -> pre_ ;
                delete p ;
                return ;
                }
            }else{
                p = p -> next_ ;
            }
        }

    }

//节点查询
    bool Find(int val){
        Node * p = head_ -> next_ ;
        while(p != nullptr){
            if(p -> data_ == val){
                cout << "查询到了" << endl ;
                return true;
            }else{
                p = p -> next_ ;
            }
        }
    }

//输出函数
    void show(){
        Node* p = head_ -> next_ ;
        while(p != nullptr){
            cout << p -> data_ << " " ;
            p = p -> next_ ;
        }
        cout << endl;
    }
};





int main(){
    DoubleLink dlink1 ;
    dlink1.InsertHead(10);
    dlink1.InsertHead(20);
    dlink1.InsertHead(40);
    dlink1.InsertHead(30);
    dlink1.show();

    DoubleLink dlink2 ;
    dlink2.InsertTail(2);
    dlink2.InsertTail(4);
    dlink2.InsertTail(6);
    dlink2.InsertTail(8);
    dlink2.show();
    dlink2.Remove(2);
    dlink2.show();


    dlink1.Find(20);
    return 0;
}