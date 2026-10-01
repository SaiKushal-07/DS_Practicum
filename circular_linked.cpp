#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* last = NULL;
Node* current = NULL;

void addMember(string name) {
    Node* newNode = new Node();
    newNode->name = name;
    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
        current = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    cout << "Member added successfully." << endl;
}

void displayMembers() {
    if (last == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    Node* temp = last->next;
    cout << "Driving Rotation: ";
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

void removeMember(string name) {
    if (last == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    Node* curr = last->next;
    Node* prev = last;
    do {
        if (curr->name == name) {
            if (curr == last && curr == last->next) {
                last = NULL;
            } else if (curr == last) {
                prev->next = curr->next;
                last = prev;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Member removed successfully." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);
    cout << "Member not found." << endl;
}

void searchMember(string name) {
    if (last == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    Node* temp = last->next;
    int pos = 1;
    do {
        if (temp->name == name) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);
    cout << "Member not found." << endl;
}

void assignNextDriver() {
    if (last == NULL) {
        cout << "Driving rotation is empty." << endl;
        return;
    }
    cout << "Current Driver: " << current->name << endl;
    current = current->next;
}

void showMenu() {
    cout << "\n1.Add Member    2.Remove Member" << endl;
    cout << "3.Search Member 4.Display Rotation" << endl;
    cout << "5.Next Driver   6.Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice;
    string name;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter member name: ";
            cin >> name;
            addMember(name);
            break;
        case 2:
            cout << "Enter member name: ";
            cin >> name;
            removeMember(name);
            break;
        case 3:
            cout << "Enter member name: ";
            cin >> name;
            searchMember(name);
            break;
        case 4:
            displayMembers();
            break;
        case 5:
            assignNextDriver();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 6);
    return 0;
}