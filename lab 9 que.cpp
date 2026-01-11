#include <iostream>
using namespace std;

#define MAX 10   

string queue[MAX];   // array to store tickets
int front = -1;
int rear = -1;

// Add ticket (Enqueue)
void enqueue() {
    if (rear == MAX - 1) {
        cout << "Queue is full! Cannot add ticket.\n";
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        cout << "Enter customer ticket: ";
        cin >> queue[rear];
        cout << "Ticket added successfully.\n";
    }
}

// Process ticket (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty! No ticket to process.\n";
    } else {
        cout << "Processed Ticket: " << queue[front] << endl;
        front++;
    }
}

// Display all tickets
void display() {
    if (front == -1 || front > rear) {
        cout << "No pending tickets.\n";
    } else {
        cout << "Pending Tickets:\n";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
}

// Check if queue is empty
void isEmpty() {
    if (front == -1 || front > rear)
        cout << "Queue is empty.\n";
    else
        cout << "Queue is not empty.\n";
}

// Check if queue is full
void isFull() {
    if (rear == MAX - 1)
        cout << "Queue is full.\n";
    else
        cout << "Queue is not full.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Customer Support Queue Menu ---\n";
        cout << "1. Add Ticket (Enqueue)\n";
        cout << "2. Process Ticket (Dequeue)\n";
        cout << "3. Display All Tickets\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            case 0: cout << "Program exited.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

