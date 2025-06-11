#include <iostream>
using namespace std;

// Node definition
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Delete node by value (first occurrence)
    void deleteNode(int val) {
        if (!head) return;

        // If head needs to be deleted
        if (head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Find node before the one to delete
        ListNode* curr = head;
        while (curr->next && curr->next->val != val) {
            curr = curr->next;
        }

        // If found, delete it
        if (curr->next && curr->next->val == val) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    // Print the list
    void print() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        ListNode* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Example usage
int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Before Deletion: ";
    list.print();

    list.deleteNode(30); // Deletes the node with value 30

    cout << "After Deletion of 30: ";
    list.print();

    return 0;
}
