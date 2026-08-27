#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr1[50];

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) cin >> arr1[i];
    cout << "Array: ";

    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

    for (int t = 0; t < 3; t++) {
        int idx, val;
        cout << "Enter index and value: ";
        cin >> idx >> val;

        if (idx >= 0 && idx < n) {
            arr1[idx] = val;
            cout << "Updated: ";
            for (int i = 0; i < n; i++) cout << arr1[i] << " ";
            cout << endl;
     
        } else cout << "Invalid Index!" << endl;
    }
    return 0;
}