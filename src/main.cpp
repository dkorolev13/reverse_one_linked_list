#include <iostream>
#include <cstdlib>

using namespace std;


struct Node {

    char data;
    
    Node* next;

    Node(char data) {
    
        this->data = data;
        
        this->next = NULL;
    }
};


struct OneLinkedList {

    Node* head;

    Node* tail;

    OneLinkedList() {
    
        this->head = this->tail = NULL;
    }

    ~OneLinkedList() {
    
        while (head != NULL) pop_front();
    }

    void pop_front() {

        if (head == NULL) return;

        if (head == tail) {

            delete tail;

            head = tail = NULL;

            return;
        }

        Node* node = head;

        head = node->next;

        delete node;
    }

    void pop_back() {

        if (tail == NULL) return;

        if (head == tail) {

            delete tail;

            head = tail = NULL;

            return;
        }

        Node* node = head;

        for(; node->next != tail; node = node->next);

        node->next = NULL;

        delete tail;

        tail = node;
    }

    void push_back(char data) {
    
        Node* node = new Node(data);
        
        if (head == NULL) head = node;
        
        if (tail != NULL) tail->next = node;
        
        tail = node;
    }

    void print() {
    
        Node* temp = head;
        
        while (temp != NULL) {
        
            cout << temp->data << "-->";
            
            temp = temp->next;
        }
    }

    void reverse() {
    
        Node* current = head;
        
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            
            next = current->next;
           
            current->next = prev;
            
            prev = current;
            
            current = next;
         }

        head = prev;
    }
};


int main(int argc, char *argv[])
{
    OneLinkedList ll;

    string data;

    cout << "Input data without \"spaces\": " << endl;
    
    getline(cin, data);

    for (int i : data) {
    
        ll.push_back(i);
    }

    cout << "Input linked list:\n";
    
    ll.print();

    ll.pop_front();

    ll.pop_back();

    cout << "\nList after removing extreme elements:\n";

    ll.print();

    cout << "\nReversed linked list:\n";

    ll.reverse();

    ll.print();
    
    cout << "\n";

    return 0;
}
