#include<iostream>
using namespace std;

struct node {

    int id;
    string name;
    string artist;
    float duration;

    node* next;
};

node* head = 0;

// Insert at start (beginning)
void ist(int id, string name, string artist, float duration)
{
    node* temp = new node;

    temp->id = id;
    temp->name = name;
    temp->artist = artist;
    temp->duration = duration;

    if (head == 0)
    {
        head = temp;
        temp->next = head; // circular
        return;
    }

    node* ptr = head;

    // go to last node
    while (ptr->next != head)
        ptr = ptr->next;

    temp->next = head;
    head = temp;
    ptr->next = head;  // maintain circular link
}

// Insert at end
void endd(int id, string name, string artist, float duration)
{
    node* temp = new node;

    temp->id = id;
    temp->name = name;
    temp->artist = artist;
    temp->duration = duration;

    if (head == 0)
    {
        head = temp;
        temp->next = head;
        return;
    }

    node* ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;

    ptr->next = temp;
    temp->next = head;
}

// Insert at specific position
void specp(int id, string name, string artist, float duration, int pos)
{
    if (pos == 1)
    {
        ist(id, name, artist, duration);
        return;
    }

    node* temp = new node;

    temp->id = id;
    temp->name = name;
    temp->artist = artist;
    temp->duration = duration;

    node* ptr = head;
    int count = 1;

    while (count < pos - 1 && ptr->next != head)
    {
        ptr = ptr->next;
        count++;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

// Delete from start
void dstart()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = 0;
        return;
    }

    node* ptr = head;
    node* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    delete ptr;

    cout << "Track deleted at start.\n";
}

// Delete from end
void dend()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = 0;
        return;
    }

    node* ptr = head;
    node* prev = 0;

    while (ptr->next != head)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = head;
    delete ptr;

    cout << "Track deleted from end.\n";
}

// Delete by Track ID
void dspec(int pos)
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    node* ptr = head;
    node*pev=0;

    int cont=1;

    while (cont<pos && ptr->next!=head)
    
    {
        pev=ptr;
        ptr = ptr->next;
        cont++;
    }

pev->next = ptr->next;
    delete ptr;

    cout << "Track deleted.\n";
}

// Display playlist (circular)
void display()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    node* ptr = head;
    cout << "\n--- Playlist Songs ---\n";

    do {
        cout << "ID: " << ptr->id
            << ", Name: " << ptr->name
            << ", Artist: " << ptr->artist
            << ", Duration: " << ptr->duration << " mins\n";

        ptr = ptr->next;

    } while (ptr != head);
}



int main()
{
    int choice;

    while (1)
    {
        cout << "\n--- Circular Singly Linked List Playlist ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by Track position\n";
        cout << "7. Display Playlist\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, pos;
        float duration;
        string name, artist;

        if (choice == 1)
        {
            cout << "Enter ID Name Artist Duration: ";
            cin >> id >> name >> artist >> duration;
            ist(id, name, artist, duration);
        }
        else if (choice == 2)
        {
            cout << "Enter ID Name Artist Duration: ";
            cin >> id >> name >> artist >> duration;
            endd(id, name, artist, duration);
        }
        else if (choice == 3)
        {
            cout << "Enter ID Name Artist Duration Position: ";
            cin >> id >> name >> artist >> duration >> pos;
            specp(id, name, artist, duration, pos);
        }
        else if (choice == 4)
        {
            dstart();
        }
        else if (choice == 5)
        {
            dend();
        }
        else if (choice == 6)
        {
            cout << "Enter Track position to Delete: ";
            cin >> pos;
            dspec(pos);
        }
        else if (choice == 7)
        {
            display();
        }
        else if (choice == 8)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}

