#include<iostream>

using namespace std;

struct Node{
    int value;
    Node * next;
};

void insertAtEnd(Node **headptr, int val);
void insertAtBegin(Node **headptr, int val);
void insert(Node **headptr, int pos, int val);
void deleteNode(Node **headptr, int pos);
void reverse(Node **headptr);
void printNode(Node *head);


int main(){
    Node * head = nullptr ;
    insertAtBegin(&head, 0); // 0->nullptr
    insertAtBegin(&head, 1); // 1-> 0 -> nullptr
    insertAtBegin(&head, 2); // 2->1->0->nullptr
    insertAtBegin(&head, 3); // 3->2->1->0->nullptr
    insert(&head, 2, 4); // 3->2->4->1->0->nullptr
    insertAtEnd(&head, 10); // 3->2->4->1->0->10->nullptr
    deleteNode(&head, 2); // 3->2->1->0->10->nullptr
    deleteNode(&head, 0); // 2->1->0->10->nullptr
    printNode(head);

    reverse(&head);
    printNode(head);

    return 0; 
}


void insertAtEnd(Node **headptr, int val){
     Node * temp = *headptr;
     while(temp->next != nullptr){
         temp = temp->next;
     }
     Node * newNode = new Node;
     newNode->value = val;
     newNode->next = nullptr;
     temp->next = newNode;
}

void insertAtBegin(Node **headptr, int val){
    Node * temp = new Node;
    temp->value = val;
    temp->next = *headptr;
    *headptr = temp;
}

void insert(Node **headptr, int pos, int val){
    if (pos == 0){ 
        insertAtBegin(headptr, val);
    } 
    else{   
        Node * temp = *headptr;
        for (int i = 0; i<pos-1; i++){
            temp = temp->next;
        }
        Node * newNode = new Node;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->value = val;
    }    
}

void deleteNode(Node **headptr, int pos){
    if (pos == 0){ 
        Node * temp = *headptr;
        *headptr = temp->next;
        delete temp;
    }
    else{ 
        Node * temp = *headptr;
        for (int i {0}; i<pos-1; i++){
            temp = temp->next;
        }
        Node * temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }    
}

void reverse(Node **headptr){
    // head-> 1,2,3,4,5 -> Nullptr
    // nullptr <-1,2,3,4,5 <-head

    Node *prev, *current, *nextNode;
    prev = nullptr;
    current = *headptr;
    nextNode = *headptr;

    while(current!=nullptr){
        nextNode = nextNode->next; // &2
        current->next = prev;      // 1->nullptr
        prev = current;            // 1
        current = nextNode;        // 2
    }
    *headptr = prev;
}

void printNode(Node *head){
    Node * temp = head;
    do{
        cout << temp->value << ", "; 
        temp = temp->next;             
    }while (temp != nullptr);
    cout << endl;
}