#include <iostream>
using namespace std;

// Function to apply Bubble Sort
void bubbleSort(int arr[], int size) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int salaries[10] = {45000, 32000, 60000, 28000, 52000,
                        39000, 70000, 31000, 48000, 56000};

    int size = 10;

    cout << "Salaries Before Sorting:\n";
    display(salaries, size);

    bubbleSort(salaries, size);

    cout << "\nSalaries After Sorting (Ascending Order):\n";
    display(salaries, size);

    return 0;
}

