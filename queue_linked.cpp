#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int id) {
    Node* newNode = new Node();
    newNode->data = id;
    newNode->next = NULL;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Student " << id << " registered." << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node* temp = front;
    cout << "Removed Student: " << temp->data << endl;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
}

void showFront() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front Student: " << front->data << endl;
}

void showRear() {
    if (rear == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Rear Student: " << rear->data << endl;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void search(int id) {
    Node* temp = front;
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
    return front == NULL;
}

void showMenu() {
    cout << "\n1.Enqueue 2.Dequeue" << endl;
    cout << "3.Front   4.Rear" << endl;
    cout << "5.Display 6.Search" << endl;
    cout << "7.isEmpty 8.Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice, id;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;
            enqueue(id);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            showFront();
            break;
        case 4:
            showRear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Enter Student ID to search: ";
            cin >> id;
            search(id);
            break;
        case 7:
            if (isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 8);
    return 0;
}