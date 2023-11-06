#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template <typename DataType, typename KeyType>
struct Node {
    DataType data;
    KeyType key;
    Node* next;

    Node(const DataType& newData, const KeyType& newKey)
        : data(newData), key(newKey), next(nullptr) {}
};

template <typename DataType, typename KeyType>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insert(const DataType& newData, const KeyType& newKey);
    bool remove(const KeyType& deleteKey);
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    void clear();

    bool isEmpty() const;
    Node<DataType, KeyType>* getHead() const;

    void showStructure() const;
private:
    Node<DataType, KeyType>* head;
};

template <typename DataType, typename KeyType>
LinkedList<DataType, KeyType>::LinkedList() : head(nullptr) {}

template <typename DataType, typename KeyType>
LinkedList<DataType, KeyType>::~LinkedList() {
    clear();
}

template <typename DataType, typename KeyType>
void LinkedList<DataType, KeyType>::insert(const DataType& newData, const KeyType& newKey) {
    Node<DataType, KeyType>* newNode = new Node<DataType, KeyType>(newData, newKey);
    newNode->next = head;
    head = newNode;
}

template <typename DataType, typename KeyType>
bool LinkedList<DataType, KeyType>::remove(const KeyType& deleteKey) {
    if (isEmpty()) {
        return false;
    }

    if (head->key == deleteKey) {
        Node<DataType, KeyType>* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node<DataType, KeyType>* current = head;
    while (current->next != nullptr) {
        if (current->next->key == deleteKey) {
            Node<DataType, KeyType>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }

    return false;
}

template <typename DataType, typename KeyType>
bool LinkedList<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const {
    Node<DataType, KeyType>* current = head;
    while (current != nullptr) {
        if (current->key == searchKey) {
            returnItem = current->data;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename DataType, typename KeyType>
void LinkedList<DataType, KeyType>::clear() {
    while (head != nullptr) {
        Node<DataType, KeyType>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename DataType, typename KeyType>
bool LinkedList<DataType, KeyType>::isEmpty() const {
    return head == nullptr;
}

template <typename DataType, typename KeyType>
Node<DataType, KeyType>* LinkedList<DataType, KeyType>::getHead() const {
    return head;
}

template <typename DataType, typename KeyType>
void LinkedList<DataType, KeyType>::showStructure() const {
    Node<DataType, KeyType>* current = head;

    while (current != nullptr) {
        cout << "[" << current->data.getKey() << ", " << current->data.getValue() << "] ";
	current = current->next;
    }

    cout << endl;
}

#endif // ifndef LINKEDLIST_H
