#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to delete the given node (cannot delete the last node this way)
void deleteNode(Node* node) {
    if (node == NULL || node->next == NULL) {
        cout << "Cannot delete this node (it might be the last node)." << endl;
        return;
    }
    node->data = node->next->data;
    Node* temp = node->next;
    node->next = node->next->next;
    delete temp;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes.";
        return 0;
    }

    cout << "Enter the values of the linked list: ";
    int val;
    cin >> val;
    Node* head = new Node(val);
    Node* current = head;

    // Create linked list
    for (int i = 1; i < n; i++) {
        cin >> val;
        current->next = new Node(val);
        current = current->next;
    }

    cout << "Enter the position (1-based) of node to delete: ";
    int pos;
    cin >> pos;

    if (pos <= 0 || pos >= n) {
        cout << "Invalid position (cannot delete last node using this method)." << endl;
        return 0;
    }

    // Traverse to the node to delete
    Node* nodeToDelete = head;
    for (int i = 1; i < pos; i++) {
        nodeToDelete = nodeToDelete->next;
    }

    // Before deletion
    cout << "Before deletion: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    // Delete the node
    deleteNode(nodeToDelete);

    // After deletion
    cout << "After deletion: ";
    temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
