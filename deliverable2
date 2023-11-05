#include <iostream> 
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node * prev;
        friend class DoublyLinkedList;
        Node(){
            next = prev = nullptr;
        }
};
/**
 * @brief The class create list, has head points to first element, tail ponts to last element
 * @tparam T 
 */
class DoublyLinkedList{
    public:
        Node *head = nullptr;
        Node *tail = nullptr;
        int count = 0;
        Node * createNewNode(int value){
            Node *node = new Node;
            node->data = value;
            return node;
        }
       
        //function to run deleteItem
        // void insertAfter ( Node<T> * prevNode, T value);
        DoublyLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        }
        DoublyLinkedList(const DoublyLinkedList &D);
        // ~DoublyLinkedList() {
        //     int data;
        //     while(pop_front(data));
        // } // destructor 
        void push_back(int value){
            Node * newNode = createNewNode(value);
            if(tail != nullptr) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
                count++;
            }
            else{
                head = newNode;
                tail = newNode;
                count++;
            }
        } // create and put a newNode at the back of list 
        void displayList(){
            Node * node = head;
            while(node != nullptr)
            {
                cout << node->data << "<=>";
                node = node->next;
            }
            tail = node;
            cout << "END" << endl; 
        }      
        void sorted_insert(Node ** head_ref, Node * newNode){
            Node * current;
            if(*head_ref == nullptr){*head_ref = newNode;}
            else if((*head_ref)->data >= newNode->data){
                newNode->next = *head_ref;
                newNode->next->prev = newNode;
                *head_ref = newNode;
            }
            else {
                current = *head_ref;
                while (current->next != nullptr && current->next->data < newNode->data)
                current = current->next;

                newNode->next = current->next;
                if (current->next != NULL)
                    newNode->next->prev = newNode;
                current->next = newNode;
                newNode->prev = current;
            }
        }
        void insertion_sort(DoublyLinkedList * ptr, int size){
        Node * sorted = nullptr;
        Node * current = head;
        while(current != nullptr){
            Node * next = current->next;
            current->prev = current->next = nullptr;
            sorted_insert(&sorted, current);
            current = next;
        }
        ptr->head = sorted;
        int key;
        }
};

int main() {
    int array [5] = {36,24,12,10,6};
    DoublyLinkedList collection;
    for (auto x : array){
        collection.push_back(x);
    }
    DoublyLinkedList * ptr = &collection;
    collection.displayList();
    int size = sizeof(array)/ sizeof(array[0]);
    cout << size << endl;
    ptr->insertion_sort(ptr, size);
    cout << "Insertion Sort" << endl;
    collection.displayList();
    return 0;
}


