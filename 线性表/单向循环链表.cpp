#include<iostream>
using namespace std;


class CircleClink{
private:
    struct Node{
        int data_;
        Node* next_;

        Node(int data = 0): data_(data), next_(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    CircleClink(){
        head_ = new Node();
        tail_ = head_;
        head_->next_ = head_; // 初始化时，尾节点指向头节点(相当于自己一个循环)
    }
    ~CircleClink(){
        Node* p = head_ -> next_;
        while(p != head_){
            head_ -> next_ = p -> next_;
            delete p;
            p = head_ -> next_;
        }
        delete head_; // 删除头节点
    }



// 尾插法
    void insertTail(int val){
        Node* node = new Node(val);
        tail_->next_ = node; // 尾节点指向新节点
        node->next_ = head_; // 新节点指向头节点
        tail_ = node; // 更新尾节点为新节点
    }

// 头插法
    void insertHead(int val){
        Node* node = new Node(val);
        node -> next_ = head_ -> next_;
        head_ -> next_ = node; // 头节点指向新节点
        if(node -> next_ == head_){
            tail_ = node; // 如果新节点是唯一节点，更新尾节点
        }
    }

// 删除指定值的节点
    void Remove(int val){
        Node* q = head_;
        Node* p = head_->next_;
        while (p != head_){
            if(p -> data_ == val){
                q->next_ = p->next_; // 前一个节点指向下一个节点
                delete p; // 删除当前节点
                if(q -> next_ == head_){
                    tail_ = q; // 如果删除的是尾节点，更新尾节点
                }
                return ;
            }else{
                q = p;
                p = p -> next_;
            }
        }
    }

// 查询
    bool FInd(int val){
        Node* p = head_ -> next_;
        while (p != head_) {
            if (p->data_ == val) {
                return true; // 找到值          
            }
        }
        return false; // 未找到值
    }

// 打印
    void show(){
        Node* p = head_->next_;
        if (p == head_) {
            cout << "List is empty." << endl;
            return;
        }
        do {
            cout << p->data_ << " ";
            p = p->next_;
        } while (p != head_);
        cout << endl;
    }
};



int main(){

    CircleClink clink;
    clink.insertTail(1);
    clink.insertTail(2);
    clink.insertTail(3);

    clink.insertHead(100);
    clink.show();

    clink.insertTail(100);
    clink.insertTail(200);
    clink.show();

    clink.Remove(100);// 只删除了一个100
    clink.show();
    
    
    return 0;
}




