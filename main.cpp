#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/* Doubly Linked List Node */
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

/* LRU Cache Class */
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Add node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove a node from the list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move node to front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Remove least recently used node
    Node* removeLRU() {
        Node* lru = tail->prev;
        removeNode(lru);
        return lru;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);  // dummy head
        tail = new Node(-1, -1);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            cout << "Cache Miss: " << key << endl;
            return -1;
        }
        Node* node = cache[key];
        moveToFront(node);
        cout << "Cache Hit: " << key << " -> " << node->value << endl;
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
            cout << "Updated: " << key << " -> " << value << endl;
        } else {
            if (cache.size() == capacity) {
                Node* lru = removeLRU();
                cout << "Evicted: " << lru->key << endl;
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = newNode;
            cout << "Inserted: " << key << " -> " << value << endl;
        }
    }

    void displayCache() {
        cout << "Cache State (MRU -> LRU): ";
        Node* curr = head->next;
        while (curr != tail) {
            cout << "[" << curr->key << ":" << curr->value << "] ";
            curr = curr->next;
        }
        cout << endl;
    }
};

/* Main function: Request Simulation */
int main() {
    int capacity;
    cout << "Enter cache capacity: ";
    cin >> capacity;

    LRUCache cache(capacity);

    cout << "\nCommands:\n";
    cout << "put key value\n";
    cout << "get key\n";
    cout << "exit\n\n";

    while (true) {
        string command;
        cin >> command;

        if (command == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
            cache.displayCache();
        } 
        else if (command == "get") {
            int key;
            cin >> key;
            cache.get(key);
            cache.displayCache();
        } 
        else if (command == "exit") {
            break;
        } 
        else {
            cout << "Invalid command\n";
        }
    }

    return 0;
}
