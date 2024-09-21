#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int value){
        data = value;
        next = NULL;
        }
    
    Node* insert(int x,Node*head) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
        return head;
    }

   void del(int pos,Node*head) {
        if (head == NULL) return;

        Node* temp = head;
        if (pos == 0) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) return;

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    void display(Node*head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class stack{
    public:
    int top;
    int *a;
    int size;
    stack(int s){
        top=-1;
        size=s;
        a=new int[s];
    }
    void push(int x){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            a[++top]=x;
            }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            int  x=a[top--];
            }
    }
};

    class queue{
        public:
        int front, rear;
        int *a;
        int size;
        queue(int s){
            front=-1;
            rear=-1;
            size=s;
            a=new int[s];
        }
        void enqueue(int x){
            if(rear==size-1){
                cout<<"Queue Overflow"<<endl;}
                else{
                    a[++rear]=x;
                }
        }
        void dequeue(){
            if(front==-1 && rear==-1){
                cout<<"Queue Underflow"<<endl;}
                else{
                    int x=a[front++];
                    }
        }
    };

int main() {
    Node* head = NULL;
    Node node(0);  
   head= node.insert(1, head);
    head=node.insert(2, head);
    head=node.insert(3, head);
   head= node.insert(4, head);

    node.display(head);


    return 0;
}