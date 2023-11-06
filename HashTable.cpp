#include "HashTable.h"
#include "LinkedList.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize) : tableSize(initTableSize) {
	// Initialize the hash table 
	dataTable = new LinkedList<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other) {
	// Copy constructor 
	copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other) {
	// Overload assignment operator 
	if (this != &other) {
		clear(); // clear current data
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
	// Implement insert method
	int index = DataType::hash(key) % tableSize;
	dataTable[index].insert(newDataItem, key);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const {
	// Implement retrieve method
	int index = DataType::hash(searchKey) % tableSize;
	return dataTable[index].retrieve(searchKey, returnItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& key) {
	// Implement remove method
	int index = DataType::hash(key) % tableSize;
	return dataTable[index].remove(key);
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {
	//Implement clear method
	for (int i = 0; i < tableSize; i++) {
		dataTable[i].clear();
	}
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const {
	// Implement isEmpty method
	for (int i = 0; i < tableSize; i++) {
		if ( !dataTable[i].isEmpty()) {
			return false;
		}
	}
	return true;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
	// Implement showStructure method
	for (int i=0; i < tableSize; i++) {
		cout << "Bucket" << i << ": ";
		dataTable[i].showStructure();
	}
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) {
	// Implement copyTable method
	tableSize = source.tableSize;
	dataTable = new LinkedList<DataType, KeyType>[tableSize];

	for (int i = 0; i < tableSize; i++) {
		dataTable[i] = source.dataTable[i];
	}
}


