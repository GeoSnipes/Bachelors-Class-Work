#include<iostream>
using namespace std;
/*
Concatenation of arrays
Input- arrays
Output- 2 arrays sorted in ascending order and placed in one array
*/

void main()
{
	//variables
	int array1[20], array2[20], array3[40];
	int x, i=0, j=0, s1length, s2length, s3length;
	
	//algorithm
	cout<<"How many numbers do you want to enter in string 1:\t";
	cin>>s1length;
	cout<<"Enter the numbers in ascending order:\n";
	for (x=0;x<s1length;x++)
	{
		cin>>array1[x];
	}
	cout<<"\n\nHow many numbers do you want to enter in string 2:\t";
	cin>>s2length;
	cout<<"Enter the numbers in ascendding order:\n";
	for (x=0;x<s2length;x++)
	{
		cin>>array2[x];
	}
	s3length=s2length+s1length;
	cout<<"\n\nThe numbers will now be concatenated.\n\n";
	for (x=0;x<s3length;x++)
	{
		if ((i<s1length)&&(array1[i]<array2[j]))
		{
			array3[x]=array1[i];
			i++;
		}
		else if (j<s2length)
		{
			array3[x]=array2[j];
			j++;
		}
		else if ((i<s1length)&&(j>=s2length)) //This part is here because when s1length is greater than s2length, it makes the number in array2[j]=-8598830 which cause this to be saved in array3 
		{
			array3[x]=array1[i];
			i++;
		}
	}
	for (x=0;x<s3length;x++)
	{
		cout<<array3[x]<<endl;
	}
}


