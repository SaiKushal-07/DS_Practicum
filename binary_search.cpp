#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of sorted array: ";
    cin >> n;
    int arr[50];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    int low = 0, high = n - 1;
    bool found = false;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            cout << "Element found at position " << mid + 1 << endl;
            found = true;
            break;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (!found)
        cout << "Element not found!" << endl;
    return 0;
}