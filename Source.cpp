#include <iostream>
#include <string>

using namespace std;

struct User
{
	//array is treated as pointer
	string* item = nullptr; //assign nullptr to pointer variable item
	char reply{};//=0 //brace intialize
	//int count;  //include this
};

void displayMenu(User* Shopper, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Item #" << i + 1 << ": " << Shopper->item[i] << endl;
	}
}

void addItems(User* Shopper, int count)
{
	cout << "Enter item name: ";
	
	string* temp = new string[count + 1];//add 1 to size of array every time user adds item
	for (int i = 0; i < count; i++)// Copy all items from the old to the temp
	{
		temp[i] = Shopper->item[i];	
	}
	delete[] Shopper->item;
	Shopper->item = temp;
	 cin>>Shopper->item[count];
}

int removeItems(User* Shopper, int count)
{
	cout << "Enter the name of your item to delete it: ";
	string itemToDelete;
	cin >> itemToDelete;

	string* temp = new string[count - 1];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (Shopper->item[i] != itemToDelete)
		{
			//temp[i-1] = Shopper->item[i]; //move the right item to the left by 1 index
			//count--;
			temp[j] = Shopper->item[i];
			j++;
		}
	}
	delete[] Shopper->item; //delete the old pointer 
	Shopper->item = temp;
	return count - 1;
}

bool areItemsDuplicate(User Shopper, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (Shopper.item[i] == Shopper.item[i + 1])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void main()
{
	int count = 0;
	User Shopper;
	string* item=nullptr;
	//Shopper.item = new string[0];
	do
	{
		addItems(&Shopper, count); //add items to list
		count++;
		if (count > 1)
		{
			displayMenu(&Shopper, count);
			cout << "Do you want to delete any items? (Y/N)"<< endl;
			cin >> Shopper.reply;

			if (Shopper.reply == 'Y' || Shopper.reply == 'y')
			{
				removeItems(&Shopper, count); //delete items
				count--;
			}
		}
		displayMenu(&Shopper, count); //display item list

		cout << "Do you want to enter another item? (Y/N)" << endl;
		cin >> Shopper.reply;
		cout << endl;

	} while (Shopper.reply == 'Y' || Shopper.reply == 'y');
}
