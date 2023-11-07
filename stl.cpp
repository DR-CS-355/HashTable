#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> hashTable;

    cout << "Commands:" << endl;
    cout << "  +key : Insert (or update) data item with key value key" << endl;
    cout << "  -key : Remove the data item with the key value key" << endl;
    cout << "  ?key : Retrieve the item with the specified key and output it" << endl;
    cout << "  E    : Report whether the table is empty" << endl;
    cout << "  C    : Clear the table" << endl;
    cout << "  Q    : Quit the test program" << endl;

    do {
        cout << endl << "Command: ";
        char cmd;
        cin >> cmd;

        string key;
        cin >> key;

        switch (cmd) {
            case '+':
                int value;
                cin >> value;
                hashTable[key] = value;
                cout << "Inserted data item with key (" << key << ") and value (" << value << ")" << endl;
                break;

            case '-':
                if (hashTable.erase(key)) {
                    cout << "Removed data item with key (" << key << ")" << endl;
                } else {
                    cout << "Could not remove data item with key (" << key << ")" << endl;
                }
                break;

            case '?':
                if (hashTable.find(key) != hashTable.end()) {
                    cout << "Retrieved data item with key (" << key << ") and value (" << hashTable[key] << ")" << endl;
                } else {
                    cout << "Could not retrieve data item with key (" << key << ")" << endl;
                }
                break;

            case 'C':
            case 'c':
                cout << "Clear the hash table" << endl;
                hashTable.clear();
                break;

            case 'E':
            case 'e':
                cout << "Hash table is " << (hashTable.empty() ? "" : "NOT") << " empty" << endl;
                break;

            case 'Q':
            case 'q':
                return 0;

            default:
                cout << "Invalid command" << endl;
        }
    } while (1);

    return 0;
}
