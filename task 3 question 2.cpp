#include <iostream>
using namespace std;

int main()
 {
    int n, key, choice, i;
    int roll[100];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter roll numbers:\n";
    for (i = 0; i < n; i++) {
        cin >> roll[i];
    }

    cout << "Enter roll number to search: ";
    cin >> key;

    cout << "\nChoose Search Method:\n";
    cout << "1. Linear Search (Unsorted)\n";
    cout << "2. Binary Search (Sorted)\n";
    cin >> choice;

    int low = 0, high = n - 1, mid;
    bool found = false;

    if (choice == 1) {
        // Linear Search
        for (i = 0; i < n; i++) {
            if (roll[i] == key) {
                found = true;
                cout << "\nRoll number found at position " << i + 1 << endl;
                break;
            }
        }
        if (!found)
            cout << "\nRoll number not found.\n";
    }

    else if (choice == 2) {
        // Binary Search (works only for sorted data)
        while (low <= high) {
            mid = (low + high) / 2;
            if (roll[mid] == key) {
                found = true;
                cout << "\nRoll number found at position " << mid + 1 << endl;
                break;
            }
            else if (roll[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (!found)
            cout << "\nRoll number not found.\n";
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}

