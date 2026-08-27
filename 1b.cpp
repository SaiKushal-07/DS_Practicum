#include <iostream>
using namespace std;

int main() {
    int m, p;

    cout << "Enter rows and columns: ";
    cin >> m >> p;

    int arr2[10][10];

    cout << "Enter " << m * p << " elements: ";

    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++) cin >> arr2[i][j];
    }

    cout << "Array:" << endl;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) cout << arr2[i][j] << " ";
        cout << endl;
    }

    for (int t = 0; t < 4; t++) {
        int r, c, val;
        cout << "Enter row, column and value: ";
        cin >> r >> c >> val;

        if (r >= 0 && r < m && c >= 0 && c < p) {
            arr2[r][c] = val;
            cout << "Updated:" << endl;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < p; j++) cout << arr2[i][j] << " ";
                cout << endl;
            }
        } else cout << "Invalid Row/Column!" << endl;
    }
    
    return 0;
}