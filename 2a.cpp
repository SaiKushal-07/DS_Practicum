#include <iostream>
#include <string>
using namespace std;

#define MAX 5

string historyStack[MAX];
int top = -1;

bool isFull() { return top == MAX - 1; }

bool isEmpty() { return top == -1; }

void visitPage(string page) {
    if (isFull()) { 
        cout << "Stack Overflow!" << endl; return; 
    }

    historyStack[++top] = page;
    cout << "Visited: " << page << endl;
}

void goBack() {

    if (isEmpty()) { 
        cout << "Stack Underflow!" << endl; return; 
    }

    cout << "Back from: " << historyStack[top] << endl;
    top--;
    
    if (!isEmpty()){
        cout << "Current Page: " << historyStack[top] << endl;
    }
}

void showCurrentPage() {
    if (isEmpty()) {
        cout << "No current page." << endl;
    }
    else {
        cout << "Current Page: " << historyStack[top] << endl;
    } 
}

void displayHistory() {
    if (isEmpty()) { 
        cout << "History is empty." << endl; return; 
    }
    for (int i = top; i >= 0; i--) {
        cout << historyStack[i] << endl;
    }
}

int main() {
    int choice;
    string page;
    do {
        cout << "1.Visit 2.Back 3.Current 4.History 5.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter page: "; cin >> page; visitPage(page); break;
            case 2: goBack(); break;
            case 3: showCurrentPage(); break;
            case 4: displayHistory(); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid Choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}