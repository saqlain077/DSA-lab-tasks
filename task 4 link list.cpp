#include<iostream>
using namespace std;


struct node{
	
	
	int id;
	node*next;
	
	
};

node*head=0;

 void ist(int id)
{
	node*temp=new node;
	
	temp->id=id;
	temp->next=0;
	
	if(head==0)
	{
		
		head=temp;
		}
else{
	temp->next=head;
	head=temp;
	
	
}	
	return;
}

void end(int id)
{


	
	node*temp=new node;
	
	temp->id=id;
	temp->next=0;
		
	if(head==0)
	{
		
		head=temp;
	}
	else{
 node*ptr=head;	
	while(ptr->next!=0)
	{
		ptr=ptr->next;
		
	}
	ptr->next=temp;
	
	
	
}
}
void display()
{ if (head == 0) {
        cout << "No patients.\n";
        return;
    }
        
        node* ptr = head;
    cout << "\nPatients List:\n";
    while (ptr != 0) {
        cout << "ID: " << ptr->id << endl;
        ptr = ptr->next;
        
        
}
}

main()
{
	
	int id , choice;
	
while(1){
	  cout << "\n1. Add Patient (End)";
        cout << "\n2. Add Emergency Patient (Beginning)";
        cout << "\n3. Display Patients";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
	
	if(choice==1)
	{
		cout<<"enter id";
		cin>>id;
		end( id);
		
		
		}
		
	else if(choice==2)
	{
		cout<<"enter id";
		cin>>id;
		ist( id);
		
		
		}
	else if(choice==3)
	{
		display();
	}
	else if(choice==4)
	{
	return 0;
	}
	else{
		
		cout<<"invelad";
		
}	
}
}

