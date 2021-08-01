//============================================================================
// Name        : Preorder_to_Postorder.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
In pre-order traversal of BST, first element is the root element of the tree. Iterate through the given pre-order traversal 
of BST and compare each element with the first element of the array till the index where elements are less than the first element. 
Store the value of the index in a variable called ‘Pivot’. Print elements of a pre-order array from ‘Pivot’ index to index 1. 
Print elements of pre-order array from ‘array, length’ index – 1 to ‘Pivot’ index + 1. Print first element of pre-order array.
*/
//============================================================================

#include <iostream>
using namespace std;

void getPostOrderBST(int pre[], int N)
{
	int pivotPoint = 0;

	// Run loop from 1 to length of pre
	for(int i = 1; i < N; i++)
	{
		if (pre[0] <= pre[i])
		{
			pivotPoint = i;
			break;
		}
	}

	// Print from pivot length -1 to zero
	for(int i = pivotPoint - 1; i > 0; i--)
	{
		cout << pre[i] << " ";
	}

	// Print from end to pivot length
	for(int i = N - 1; i >= pivotPoint; i--)
	{
		cout << pre[i] << " ";
	}
	cout << pre[0];
}

// Driver Code
int main()
{
	int pre[] = { 40, 30, 32, 35,
				80, 90, 100, 120 };
	int N = 8;
	
	getPostOrderBST(pre, N);
	
	return 0;
}


