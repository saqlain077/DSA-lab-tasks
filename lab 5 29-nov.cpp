#include<iostream>
using namespace std;


struct node{
	
	int id;
	int sem;
	float gpa;
	string name;
	
	node*next;
	node*pev;
	
	};
	
	
	node*head=0;
	void ist(int id,string name,int sem,float gpa)
	{
		if(head==0)
		{
			node*temp=new node;
			
			temp->id=id;
			temp->name=name;
			temp->sem=sem;
			temp->gpa=gpa;
			temp->next=0;
		    temp->pev=0;
			
		head=temp;
			return;
		}
		else{
				node*temp=new node;
			
			temp->id=id;
			temp->name=name;
			temp->sem=sem;
			temp->gpa=gpa;
			
			
			head->pev=temp;
			temp->next=head;
			head=temp;
			
			return;
		}
		
		
		
	}
		void end (int id,string name,int sem,float gpa)
      {
      	if(head==0)
		{
			node*temp=new node;
			
			temp->id=id;
			temp->name=name;
			temp->sem=sem;
			temp->gpa=gpa;
			temp->next=0;
		    temp->pev=0;
			
		head=temp;
			return;}
			
			else{
				node*temp=new node;
					temp->id=id;
			temp->name=name;
			temp->sem=sem;
			temp->gpa=gpa;
			temp->next=0;
			
			node*ptr=head;
			
			while(ptr->next!=0){
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->pev=ptr;
			return;
			}
			
			
	  }
	  void specp(int id,string name,int sem,float gpa,int pos)
	  {
	  		node*temp=new node;
			
			temp->id=id;
			temp->name=name;
			temp->sem=sem;
			temp->gpa=gpa;
			temp->next=0;
			if(pos!=1)
			{
			
		    node*ptr=head;
		    int count =1;
		    while(count<pos-1)
		    {
		    	ptr=ptr->next;
		    	count++;
			}
	  	
	  	      temp->next=ptr->next;
	  	      temp->pev=ptr;
	  	      ptr->next=temp;
	  	      temp->next->pev=temp;
	  	      return;
	  	}
		  else{
	  		cout<<"use ohter function to add node";
		  }
	  }
	  
	  void dstart(){
	  	  if(head == 0) {
        cout << "List is empty.\n";
        return;
    }
           node*ptr=head;
           head=ptr->next;
           head->pev=0;
           delete ptr;
	cout<<"node delete at start";
	  }
	  void dend()
	  {
	  	  if(head == 0) {
        cout << "List is empty.\n";
        return;
    }
    
      node*ptr=head;
      while(ptr!=0)
      {ptr=ptr->next;
	  }
	  ptr->pev->next=0;
	  delete ptr;
	  
	  cout<<"\ndelete node from last \n";
	  }
	  
	  void dspec(int pos)
	  
	  {
	    if(head == 0) {
        cout << "List is empty.\n";
        return;
    }
	 node*ptr=head;
	 int cont=1;
	 while(cont<pos)
{ptr=ptr->next;
cont++;
}

	  	ptr->pev->next=ptr->next;
	  	ptr->next->pev=ptr->pev;
	  	delete ptr;
	  	
	 cout<<"delete at"<<pos; }
	 
	 
	 void displayfw(){
	 	
	 	if(head == 0) {
        cout << "No student records.\n";
        return;}
        
        node*ptr=head;
        cout << "\nStudent Records (Start to End):\n";
        
        while(ptr!=0)
        {
        	cout << "ID: " << ptr->id
             << ", Name: " << ptr->name
             << ", Semester: " << ptr->sem
             << ", GPA: " << ptr->gpa << endl;
        	
        	ptr=ptr->next;
        	
		}
	 
}
	 void displaybw(){
	 
	  
	  
	  
	  if(head == 0) {
        cout << "No student records.\n";
        return;
    }

    node* ptr = head;


    while(ptr->next != 0) {
        ptr = ptr->next;
    }

    cout << "\nStudent Records (End to Start):\n";
    while(ptr != 0) {
        cout << "ID: " << ptr->id
             << ", Name: " << ptr->name
             << ", Semester: " << ptr->sem
             << ", GPA: " << ptr->gpa << endl;
        ptr = ptr->pev;
    }
}


	 	
	 	main()
	 	{
	 		int choice;
	 		while(1){
	 			
	 			 cout << "\n--- Student Enrollment Management ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
	 			
	 	     int id, sem, pos;
        float gpa;
        string name;

        if(choice == 1) {
            cout << "Enter ID Name Semester GPA: ";
            cin >> id >> name >> sem >> gpa;
            ist(id, name, sem, gpa);
        }
        else if(choice == 2) {
            cout << "Enter ID Name Semester GPA: ";
            cin >> id >> name >> sem >> gpa;
            end(id, name, sem, gpa);
        }
        else if(choice == 3) {
            cout << "Enter ID Name Semester GPA Position: ";
            cin >> id >> name >> sem >> gpa >> pos;
            specp(id, name, sem, gpa, pos);
        }
        else if(choice == 4) {
            dstart();
        }
        else if(choice == 5) {
            dend();
        }
        else if(choice == 6) {
            cout << "Enter Position: "; cin >> pos;
            dspec(pos);
        }
        else if(choice == 7) {
            displayfw();
        }
        else if(choice == 8) {
            displaybw();
        }
        else if(choice == 9) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}		
		
	 		
	 		
		 
	 
	 
