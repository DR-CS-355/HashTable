// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType, typename KeyType>
class HashTable {
public:
    HashTable(int initTableSize);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void insert(const DataType& newDataItem, const KeyType& key);
    bool remove(const KeyType& deleteKey);
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    void clear();

    bool isEmpty() const;

    void showStructure() const;

private:
    void copyTable(const HashTable& source);

    int tableSize;
    LinkedList<DataType, KeyType>* dataTable;
};
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize) : tableSize(initTableSize) {
    // Initialize the hash table with the given size
    dataTable = new LinkedList<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other) {
    // Copy constructor - use the copyTable method
    copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other) {
    // Overloaded assignment operator - use the copyTable method
    if (this != &other) {
        clear(); // Clear current data
        copyTable(other);
    }
    return *this;
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() {
    clear();
    delete[] dataTable;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem, const KeyType& key) {
    // Insert a key-value pair into the hash table
    int index = DataType::hash(key) % tableSize;
    dataTable[index].insert(newDataItem, key);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const {
    // Retrieve the data item with the matching key
    int index = DataType::hash(searchKey) % tableSize;
    return dataTable[index].retrieve(searchKey, returnItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& key) {
    // Remove the data item with the specified key
    int index = DataType::hash(key) % tableSize;
    return dataTable[index].remove(key);
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {
    // Remove all data items in the hash table
    for (int i = 0; i < tableSize; i++) {
        dataTable[i].clear();
    }
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const {
    // Check if the hash table is empty
    for (int i = 0; i < tableSize; i++) {
        if (!dataTable[i].isEmpty()) {
            return false;
        }
    }
    return true;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
    // Output the data items in the hash table
    for (int i = 0; i < tableSize; i++) {
        cout << "Bucket " << i << ": ";
        dataTable[i].showStructure();
    }
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) {
    // Copy data from the source hash table
    tableSize = source.tableSize;
    dataTable = new LinkedList<DataType, KeyType>[tableSize];

    for (int i = 0; i < tableSize; i++) {
        dataTable[i] = source.dataTable[i]; // Assuming LinkedList supports assignment
    }
}
#endif // ifndef HASHTABLE_H
