#include<iostream>



using namespace std;

// 节点类型
struct Node{
    int data_  ;
    Node *next_ ;

    Node(int data = 0) : data_(data) , next_(nullptr){}
};



// 单链表
class Clink{
private:
    Node *head_;

public:
    Clink(){
        head_ = new Node();
    }
    ~Clink(){
        Node *p = head_;
        while(p != nullptr){
            head_ = head_ -> next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }

// 在链表尾部插入元素
    void insertTail(int val){
        //找到末尾节点
        Node *p = head_;
        while( p -> next_ != nullptr){
            p = p -> next_;
        }
        //创建新节点
        Node *node = new Node(val);
        //指向新节点
        p -> next_ = node;
    }

// 头插法
    void insertHead(int val){
        // 创建新节点
        Node *node = new Node(val);
        // 新节点指向原头节点
        node->next_ = head_->next_;
        // 头节点指向新节点
        head_->next_ = node;
    }

// 搜索
    bool Find(int val){
        Node *p = head_-> next_;
        while(p != nullptr){
            if(p->data_ == val){
                return true; // 找到
            }else{
                p = p->next_; // 继续查找
            }
        }
        return false; // 未找到
    }


// 删除一个指定值的节点
    void Remove(int val){
        Node *p = head_ -> next_;
        Node *q = head_;
        while(p != nullptr){
            if(p -> data_ == val){
                q -> next_ = p -> next_;
                delete p; // 释放内存
                return ;
            }else{
                q = p;
                p = p -> next_;
            }
        }
    }

// 删除多个节点
    void RemoveAll(int val){
        Node *q = head_;
        Node *p = head_ -> next_;
        while( p != nullptr){
            if( p -> data_ == val){
                q -> next_ = p-> next_ ;
                delete p;
                p = q -> next_;
            }else{
                q = p;
                p = p -> next_;
            }
        }
    }

// 打印
    void show(){
        Node * p = head_->next_;
        while(p != nullptr){
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }



};




int main(){

    Clink clink ;
    clink.insertTail(1);
    clink.insertTail(2);
    clink.insertTail(3);
    clink.insertTail(4);
    clink.show();
    clink.insertHead(100);
    clink.insertTail(3);
    clink.show();

    clink.Remove(2);
    clink.show();


    clink.RemoveAll(3);
    clink.show();

    return 0;
}