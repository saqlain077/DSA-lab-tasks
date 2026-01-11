#include <iostream>
using namespace std;

int main() {
    int A[5] = {5, 3, 7, 1, 2};
    int n = 5;
    int j;

    for (int i = 1; i < n; i++) {
        int key = A[i];
          j = i - 1;

    
        while (j >= 0 && A[j] > key) {
           A [j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    cout << "Sorted array (Insertion Sort): ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}

