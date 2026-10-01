#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertPosition(int val, int pos) {
    if (pos == 1) {
        insertBeginning(val);
        return;
    }
    Node* newNode = new Node();
    newNode->data = val;
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid Position!" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
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

void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
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
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid Position!" << endl;
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    cout << "Deleted: " << delNode->data << endl;
    delete delNode;
}

void updateNode(int oldVal, int newVal) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldVal) {
            temp->data = newVal;
            cout << "Updated Successfully" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found!" << endl;
}

void showMenu() {
    cout << "\n1.Insert Beg  2.Insert End" << endl;
    cout << "3.Insert Pos  4.Display" << endl;
    cout << "5.Search      6.Delete Beg" << endl;
    cout << "7.Delete End  8.Delete Pos" << endl;
    cout << "9.Update      10.Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice, val, pos, oldVal, newVal;
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
            display();
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 6:
            deleteBeginning();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            cout << "Enter position: ";
            cin >> pos;
            deletePosition(pos);
            break;
        case 9:
            cout << "Enter old and new value: ";
            cin >> oldVal >> newVal;
            updateNode(oldVal, newVal);
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