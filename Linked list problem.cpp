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

void deleteNode(Node* node) {
    node->data = node->next->data;
    Node* temp = node->next;
    node->next = node->next->next;
    delete temp;
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);

    cout << "Before deletion: 4 -> 5 -> 1 -> 9\n";
    deleteNode(head->next); // delete node with value 5

    cout << "After deletion: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    return 0;
}
