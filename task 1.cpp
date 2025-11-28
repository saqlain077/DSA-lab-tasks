#include<iostream>
using namespace std;

int main()
{
    
    int roll[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
   int pf[30] = {85,78,92,45,88,74,35,81,40,79,86,91,42,84,38,77,93,43,87,75,89,82,44,94,41,83,39,90,46,80};
    int oop[30] = {82,75,88,48,85,79,32,78,43,76,84,89,47,80,36,81,90,41,83,77,86,79,45,91,39,82,37,87,44,84};
    int dsa[30] = {80,72,85,46,82,76,30,75,42,74,83,86,49,78,35,79,87,40,81,73,84,77,48,89,38,80,34,85,47,82};
    int rollno;
    cout<<"ENTER THE ROLL NUMBER TO SERCH INFORMATIO (1 TO 30)"<<endl;
    cin>>rollno;
    
    
    int i;
    float percentage ,total;
    
    
    for(i=0; i<30;i++)
    {
    	if(roll[i]==rollno)
    	
         break;
        
    	
	}
	
	
	if(i<30)
	{
		total = pf[i] + oop[i] + dsa[i];
        percentage = (total / 300.0) * 100;
        
        cout << "\n=================================" << endl;
        cout << "           STUDENT RESULT" << endl;
        cout << "=================================" << endl;
        cout << " Roll Number:    " << roll[i] << endl;
        cout << "---------------------------------" << endl;
        cout << " PF Marks:       " << pf[i] << "/100" << endl;
        cout << " OOP Marks:      " << oop[i] << "/100" << endl;
        cout << " DSA Marks:      " << dsa[i] << "/100" << endl;
        cout << "---------------------------------" << endl;
        cout << " Total Marks:    " << total << "/300" << endl;
        cout << " Percentage:     " << percentage << "%" << endl;
        cout << "=================================" << endl;
		if(percentage>=50)
		cout<<"pass";
		else
		cout<<"fail";
			}
		
	   else  
    {
        cout << "Roll number not found!" << endl;
    }
   
    return 0;
	
	
}
