// Problem link:- https://leetcode.com/problems/design-linked-list/
// Difficulty:- Medium


struct Node {
    int val;
    Node *next;
    
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class MyLinkedList {
    Node *head, *tail;
    int len;
public:
    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->len = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= len) return -1;
        
        Node *temp = head;
        
        while(index--) temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val, head);
        head = newNode;
        
        if(head->next == nullptr) {
            tail = head;
        }
        len++;
    }
    
    void addAtTail(int val) {
        if(tail == nullptr) {
            addAtHead(val);
            return;
        }
        
        Node *newNode = new Node(val);
        tail->next = newNode;
        
        tail = newNode;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > len) return;
        
        if(index == 0) {
            addAtHead(val);
            return;
        }
        
        if(index == len) {
            addAtTail(val);
            return;
        }
        
        Node *temp = head;
        
        while(--index && temp) temp = temp->next;
        
        Node *newNode = new Node(val, temp->next);
        temp->next = newNode;
        len++;
    }
    
    void deleteAtIndex(int index) {
        Node *temp = head;
        
        if(index >= len || index < 0) return;
        
        if(index == 0) {
            head = head->next;
        } else {
            temp = head;
            while(--index) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            if(temp->next == nullptr) tail = temp;
        }
        
        len--;
    }
};
