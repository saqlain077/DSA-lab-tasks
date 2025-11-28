#include<iostream>
using  namespace std;

main()
{
	
	
	
	int a,b,key;
	
	
	cout << "Enter the number of elements ";
    cin >> a;
	
	
	int arr[a];
	  cout << "Enter " << a << " elements to store in array:\n ";
    for (int i = 0; i < a; i++)
     cin>> arr[i];
     
     
     
     
 
	
	
cout<<"enter the element  you want to search\n";
cin>>key;


   for(int i=0; i<=a;i++)
   {
   	
   	if(arr[i]==key)
   	
   	cout<<"the element founded. \n and the peosition of the element is \t"<<i+1;
   	
   }
   	
   	cout<<"\nelement not founded ";
	   
	
	
}  
