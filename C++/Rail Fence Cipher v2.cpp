
// 'Ctrl +' to increase font size
// 'Ctrl -' to decrease font size
// 'Ctrl 0' to Reset Font size
// 'Ctrl q' for more help


// Sample code to perform I/O:

// C++ program to illustrate Rail Fence Cipher
// Encryption and Decryption
#include <bits/stdc++.h>
using namespace std;

// function to encrypt a message
string encryptRailFence(string text, int key){
	// create the matrix to cipher plain text
	// key = rows , length(text) = columns
	int n = text.length();
	char rail[key][n];

	// filling the rail matrix to distinguish filled
	// spaces from blank ones
	for (int i=0; i < key; i++)
		for (int j = 0; j < n; j++)
			rail[i][j] = '\n';

	// to find the direction
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < n; i++)
	{
		// check the direction of flow
		// reverse the direction if we've just
		// filled the top or bottom rail
		if (row == 0 || row == key-1)
			dir_down = !dir_down;

		// fill the corresponding alphabet
		rail[row][col++] = text[i];

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	//now we can construct the cipher using the rail matrix
	string result;
	for (int i=0; i < key; i++){
		for (int j=0; j < n; j++){
		    cout<<((rail[i][j]=='\n')?'*':rail[i][j]);
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);
		}
		cout<<"\n";
	}
	return result;
}

string decryptRailFence(string cipher, int key){
	// create the matrix to cipher plain text
	// key = rows , length(text) = columns
	int n = cipher.length();
	char rail[key][n];

	// filling the rail matrix to distinguish filled
	// spaces from blank ones
	for (int i=0; i < key; i++)
		for (int j=0; j < n; j++)
			rail[i][j] = '\n';

	// to find the direction
	bool dir_down;

	int row = 0, col = 0;

	// mark the places with '*'
	for (int i=0; i < n; i++)
	{
		// check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// place the marker
		rail[row][col++] = '*';

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	// now we can construct the fill the rail matrix
	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<n; j++)
			if (rail[i][j] == '*' && index<n)
				rail[i][j] = cipher[index++];


	// now read the matrix in zig-zag manner to construct
	// the resultant text
	string result;

	row = 0, col = 0;
	for (int i=0; i< n; i++)
	{
		// check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// place the marker
		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		// find the next row using direction flag
		dir_down?row++: row--;
	}
	return result;
}

//driver program to check the above functions
int main(){
    string message;
    int fence_depth;
	cout<<"Enter fence depth: ";
    cin>>fence_depth; // key for row technique encryption
	cout<<"Enter Message: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // discards the input buffer
	getline(cin,message); // get message
    string ency = encryptRailFence(message,fence_depth);
    cout<<"encryptRailFence: "<<ency<<"\n";
    cout<<"decryptRailFence: "<<decryptRailFence(ency,fence_depth);
	return 0;
}



// Write your code here