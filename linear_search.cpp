#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[50];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Element not found!" << endl;
    return 0;
}