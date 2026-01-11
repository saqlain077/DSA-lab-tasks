#include <iostream>
using namespace std;

#define MAX 10

string stack[MAX];
int top = -1;

void push() {
    if (top == MAX - 1) {
        cout << "Stack is full!\n";
    } else {
        top++;
        cout << "Enter book name: ";
        cin >> stack[top];
        cout << "Book added.\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is empty!\n";
    } else {
        cout << "Removed book: " << stack[top] << endl;
        top--;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty!\n";
    } else {
        cout << "Top book: " << stack[top] << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!\n";
    } else {
        cout << "Books (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is empty.\n";
    else
        cout << "Stack is not empty.\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Empty\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: isEmpty(); break;
            case 0: cout << "Exit.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

