//singly linked list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free of node having value "<<value<<endl;
    }
};

void Insertathead(Node* &head , int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void Insertattail(Node* &tail,int d ){
    Node* temp = new Node(d);
    tail -> next =temp;
    tail = temp;
}

void Insertatposition(Node* &head,Node* &tail,int position,int d){
    Node* nodemid = new Node(d);
    Node* temp = head;

    if(position == 1){
        Insertathead(head,d);
        return;
    }

    int count =1;
    while(count < position-1)
    {
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL)
    {
        Insertattail(tail,d);
        return;
    }

    nodemid-> next =temp -> next;
    temp -> next = nodemid;
}

//Node deletion
void Deletenode(int position,Node* &head){

    if(position == 1){
        Node* temp = head;
        head = head-> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;

        //middle or last node delete 
        int count =1;
        while(count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

//Traversing
void print(Node* &head)
{
    Node* temp;
    temp =head;
    
    while(temp != NULL)
    {
        cout<<temp ->data<<" ";
        temp = temp -> next;
    }
}

int main()
{
    Node* node1 = new Node(10);
    // cout<<node1 -> data<<endl<<node1 -> next;
    Node* head = node1;
    Node* tail= node1;
    
    Insertathead(head,11);

    Insertattail(tail,15);

    Insertatposition(head,tail,2,22);

    print(head);

    Deletenode(2,head);

    print(head);

    Deletenode(3,head);
    print(head);

    cout<<endl<<head->data<<" ";
    cout<<tail->data;

    return 0;
}