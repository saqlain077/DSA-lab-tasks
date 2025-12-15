#include<iostream>
using namespace std;

struct node
{
    int id;
    string title;
    string artist;
    string album;
    float duration;

    node* next;
    node* pev;   // same name you use (pev instead of prev)
};

node* head = 0;
node* current = 0;   // for play next / previous

// Insert at beginning
void ist(int id, string title, string artist, string album, float duration)
{
    node* temp = new node;

    temp->id = id;
    temp->title = title;
    temp->artist = artist;
    temp->album = album;
    temp->duration = duration;

    if (head == 0)
    {
        head = temp;
        temp->next = head;
        temp->pev = head;
        current = head;
        return;
    }

    node* last = head->pev;

    temp->next = head;
    temp->pev = last;

    last->next = temp;
    head->pev = temp;

    head = temp;
}

//  at end
void endd(int id, string title, string artist, string album, float duration)
{
   
    node* temp = new node;

    temp->id = id;
    temp->title = title;
    temp->artist = artist;
    temp->album = album;
    temp->duration = duration;

    if (head == 0)
    {
        head = temp;
        temp->next = head;
        temp->pev = head;
        current = head;
        return;
    }

    node* last = head->pev;

    last->next = temp;
    temp->pev = last;

    temp->next = head;
    head->pev = temp;
    return;
}

// Insert at specific position
void specp(int id, string title, string artist, string album, float duration, int pos)
{
    if (pos == 1)
    {
        ist(id, title, artist, album, duration);
        return;
    }

    node* temp = new node;

    temp->id = id;
    temp->title = title;
    temp->artist = artist;
    temp->album = album;
    temp->duration = duration;

    node* ptr = head;
    int cont = 1;

    while (cont < pos - 1 && ptr->next != head)
    {
        ptr = ptr->next;
        cont++;
    }

    temp->next = ptr->next;
    temp->pev = ptr;

    ptr->next->pev = temp;
    ptr->next = temp;
}

// Delete first track
void dstart()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    if (head->next == head)
    {
    	node *del=head;
        delete del;
        head = 0;
        current = 0;
        return;
    }

    node* last = head->pev;
    node* del = head;

    head = head->next;

    head->pev = last;
    last->next = head;

    delete del;
}


void dend()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    if (head->next == head)
    { 
    node*del=head;
        delete del;
        head = 0;
        current = 0;
        return;
    }

    node* last = head->pev;
    node* slast = last->pev;

    slast->next = head;
    head->pev = slast;



    delete last;
}

// Delete track by position
void dspec(int pos)
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    if (pos == 1)
    {
        dstart();
        return;
    }

    node* ptr = head;
    int cont = 1;

    while (cont < pos && ptr->next != head)
    {
        ptr = ptr->next;
        cont++;
    }

    

    ptr->pev->next = ptr->next;
    ptr->next->pev = ptr->pev;

    

    delete ptr;
}

// Display forward
void displayfw()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    node* ptr = head;

    cout << "\n--- Playlist Forward ---\n";

    do
    {
        cout << "ID: " << ptr->id
             << ", Title: " << ptr->title
             << ", Artist: " << ptr->artist
             << ", Album: " << ptr->album
             << ", Duration: " << ptr->duration << endl;

        ptr = ptr->next;

    } while (ptr != head);
}

// Display backward
void displaybw()
{
    if (head == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    node* ptr = head->pev;

    cout << "\n--- Playlist Backward ---\n";

    do
    {
        cout << "ID: " << ptr->id
             << ", Title: " << ptr->title
             << ", Artist: " << ptr->artist
             << ", Album: " << ptr->album
             << ", Duration: " << ptr->duration << endl;

        ptr = ptr->pev;

    } while (ptr != head->pev);
}

// Play next song
void playnext()
{
    if (current == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    cout << "Now Playing: " << current->title << endl;
    current = current->next;
}

// Play previous song
void playprev()
{
    if (current == 0)
    {
        cout << "Playlist Empty\n";
        return;
    }

    cout << "Now Playing: " << current->title << endl;
    current = current->pev;
}

int main()
{
    int choice;

    while (1)
    {
        cout << "\n--- Premium Playlist (CDLL) ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete First Track\n";
        cout << "5. Delete Last Track\n";
        cout << "6. Delete by Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Play Next Song\n";
        cout << "10. Play Previous Song\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, pos;
        float duration;
        string title, artist, album;

        if (choice == 1)
        {
        	cout<<"ENTER ID,TITLE,ARTIST,ALBUM,DURATION\n";
            cin >> id >> title >> artist >> album >> duration;
            ist(id, title, artist, album, duration);
        }
        else if (choice == 2)
        {cout<<"ENTER ID,TITLE,ARTIST,ALBUM,DURATION\n";
            cin >> id >> title >> artist >> album >> duration;
            endd(id, title, artist, album, duration);
        }
        else if (choice == 3)
        {cout<<"ENTER ID,TITLE,ARTIST,ALBUM,DURATION AND POSITION\n";
            cin >> id >> title >> artist >> album >> duration >> pos;
            specp(id, title, artist, album, duration, pos);
        }
        else if (choice == 4)
            dstart();
        else if (choice == 5)
            dend();
        else if (choice == 6)
        {
            cin >> pos;
            dspec(pos);
        }
        else if (choice == 7)
            displayfw();
        else if (choice == 8)
            displaybw();
        else if (choice == 9)
            playnext();
        else if (choice == 10)
            playprev();
        else if (choice == 11)
            break;
        else
            cout << "Invalid Choice\n";
    }

    return 0;
}

