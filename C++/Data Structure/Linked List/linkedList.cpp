/*
    * Linked List implentation in C++    
*/
#include <iostream>
using namespace std;

struct node {

    int data;
    node *next;
};

class Linked_list {

    private:
        node *head, *tail;
    public:
        Linked_list() {

            head = NULL;
            tail = NULL;
        }
    
    void insert(int n) {
        node * tmp = new node;
        tmp -> data = n;
        tmp -> next = NULL;

        if(head == NULL) {
            
            head = tmp;
            tail = tmp;
        }else{

            tail->next =tmp;
            tail = tail->next;
        }
    }

    node* search(int key){
        
        if(head->data == key) return head;
        node* nextPtr = head, *prevPtr = NULL;

        while(nextPtr){
            if(nextPtr->data == key){
                return prevPtr;
            }
            prevPtr = nextPtr;
            nextPtr = nextPtr->next; 
        }
        return NULL;
    }

    void deleteNode(int n){
        node* ptr = search(n);
        if(ptr == head){
            head = head->next;
            free(ptr);
        }

        node* temp = NULL;
        if(ptr){
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }


    void sort(){
        if(!head || !head->next) return;
        
        node *nextPtr = head, *maxPtr = NULL, *boundPtr = NULL;
        node *temp, *maxPrevPtr = NULL, *prevPtr = NULL;
        int flag = 0;
        
        while(1){
            while(nextPtr){
                if(!maxPtr || (nextPtr && nextPtr->data > maxPtr->data)){
                    maxPrevPtr = prevPtr;
                    maxPtr = nextPtr;
                }
                if(!nextPtr) break;
                if(nextPtr && nextPtr->next == boundPtr){
                    if(nextPtr->data > maxPtr->data){
                        maxPtr = nextPtr;
                    }
                    break;
                }
                if(!nextPtr->next) break;
                prevPtr = nextPtr;
                nextPtr = nextPtr->next;
            }
            if(maxPtr == nextPtr){
                boundPtr = maxPtr;
                if(boundPtr == head){
                    break;
                }
            }
            else if(maxPtr){
                if(maxPtr == head){
                    head = head->next;
                }
                else{
                    maxPrevPtr->next = maxPtr->next;
                }
                if(!boundPtr){
                    tail = maxPtr;
                }
                nextPtr->next = maxPtr;
                maxPtr->next = boundPtr;
                boundPtr = maxPtr;
            }
            else{
                break;
            }
            nextPtr = head;
            maxPtr = NULL;
            prevPtr = NULL;
        }
    }

    void display() {
        node *tmp;
        tmp = head;
        while(tmp != NULL) {
            cout << tmp -> data << " ";
            tmp = tmp -> next;
        }
        cout<<"\n";
    }
};

int main() {
    
    Linked_list a;
    a.insert(2);
    a.insert(1);
    a.insert(4);
    a.insert(5);
    a.insert(3);
    cout << "The linked list is: " << endl;
    a.display();
    a.sort();
    cout << "The linked list is: " << endl;
    a.display();
    a.deleteNode(5);
    cout << "The linked list is: " << endl;
    a.display();
    a.deleteNode(3);
    cout << "The linked list is: " << endl;
    a.display();
    a.deleteNode(1);
    cout << "The linked list is: " << endl;
    a.display();    
    return 0;
}