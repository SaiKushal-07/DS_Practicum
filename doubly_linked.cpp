#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertPosition(int val, int pos) {
    if (pos == 1) {
        insertBeginning(val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid Position!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void deletePosition(int pos) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid Position!" << endl;
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void displayForward() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayBackward() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not Found!" << endl;
}

void showMenu() {
    cout << "\n1.Insert Beg  2.Insert End" << endl;
    cout << "3.Insert Pos  4.Delete Beg" << endl;
    cout << "5.Delete End  6.Delete Pos" << endl;
    cout << "7.Display Fwd 8.Display Bwd" << endl;
    cout << "9.Search      10.Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice, val, pos;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            insertPosition(val, pos);
            break;
        case 4:
            deleteBeginning();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            deletePosition(pos);
            break;
        case 7:
            displayForward();
            break;
        case 8:
            displayBackward();
            break;
        case 9:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 10);
    return 0;
}