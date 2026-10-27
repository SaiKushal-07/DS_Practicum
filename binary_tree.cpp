#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(int val) {
    Node* newNode = createNode(val);
    if (root == NULL) {
        root = newNode;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        q.push(temp->left);
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        q.push(temp->right);
    }
}

bool searchNode(int key) {
    if (root == NULL)
        return false;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->data == key)
            return true;
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return false;
}

Node* findDeepestNode() {
    queue<Node*> q;
    q.push(root);
    Node* temp = NULL;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return temp;
}

void deleteDeepestNode(Node* deepest) {
    if (root == deepest) {
        delete root;
        root = NULL;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left == deepest) {
            temp->left = NULL;
            delete deepest;
            return;
        }
        if (temp->right == deepest) {
            temp->right = NULL;
            delete deepest;
            return;
        }
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

bool deleteNode(int key) {
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            delete root;
            root = NULL;
            return true;
        }
        return false;
    }
    queue<Node*> q;
    q.push(root);
    Node* target = NULL;
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->data == key && target == NULL)
            target = temp;
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    if (target == NULL)
        return false;
    Node* deepest = findDeepestNode();
    if (target == deepest) {
        deleteDeepestNode(deepest);
    } else {
        target->data = deepest->data;
        deleteDeepestNode(deepest);
    }
    return true;
}

void display() {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    cout << endl;
}

void showMenu() {
    cout << "\n1.Insert  2.Search" << endl;
    cout << "3.Delete  4.Display" << endl;
    cout << "5.Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    int choice, val;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertNode(val);
            cout << "Inserted: " << val << endl;
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> val;
            if (searchNode(val))
                cout << "Element found." << endl;
            else
                cout << "Element not found." << endl;
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> val;
            if (deleteNode(val))
                cout << "Deleted: " << val << endl;
            else
                cout << "Element not found." << endl;
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}