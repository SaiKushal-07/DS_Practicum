#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int id) {
    Node* newNode = new Node();
    newNode->data = id;
    newNode->next = top;
    top = newNode;
    cout << "Kit " << id << " added." << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = top;
    cout << "Removed Kit: " << temp->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Top Kit: " << top->data << endl;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void search(int id) {
    Node* temp = top;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == id) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not Found!" << endl;
}

bool isEmpty() {
    return top == NULL;
}

void showMenu() {
    cout << "\n1.Push    2.Pop" << endl;
    cout << "3.Peek    4.Display" << endl;
    cout << "5.Search  6.isEmpty" << endl;
    cout << "7.Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice, id;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Kit ID: ";
            cin >> id;
            push(id);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Enter Kit ID to search: ";
            cin >> id;
            search(id);
            break;
        case 6:
            if (isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 7);
    return 0;
}