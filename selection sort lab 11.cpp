#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 3, 1, 9, 4};
    int n = 5;

    
    for (int i = 0; i < n - 1; i++) {
        int comp = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[comp]) {
                comp = j;
            }
        }

        
        int temp = arr[i];
        arr[i] = arr[comp];
        arr[comp] = temp;
    }

    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

