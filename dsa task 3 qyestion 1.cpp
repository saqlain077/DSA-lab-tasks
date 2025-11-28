#include <iostream>
using namespace std;

int main()
 {
 	int  found, roll;
    int students[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    cout<<"Enter Roll no to search\n";
    cin>>roll;
    found=0;
    for(int i=0;i<10;i++)
    {
	
          if(students[i] == roll)
		   {
            found = 1;
            break;
        }
    }
    
    if(found == 0) {
        cout << "Roll number not found!";
        return 0;
    }
    
    
    
       int mid;
    int high =9;
    int low=0;
    
    if(roll% 2==0)
    {
    	cout<<"ROll no is even so start acending search\n";
    	
    	while(low<=high)
    	{
		
    	mid=(low+high)/2;
    	
    	 if(students[mid] == roll) {
                cout << "Found at position " << mid + 1;
                 int found = 1;
                break;
                }
                  else if(students[mid] < roll) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
                   
	
	
	
		
    }
    	
    	
}
else {

        cout<<"Roll no is odd so  search in descending order\n";
        
        while(low<=high)
		 {
            mid = (low + high) / 2;
            if(students[mid] == roll) {
                cout << "Found at position "<<mid+1;
                int found = 1;
                break;
            }
            else if(students[mid] < roll) {
                high = mid - 1; 
            }
            else {
                low = mid + 1;  
            }    	

}

}

    }

