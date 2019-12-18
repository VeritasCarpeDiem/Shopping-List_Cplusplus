#include <iostream>
#include <string>

using namespace std;

struct User
{
	string* item = nullptr; //array is treated as pointer
	char reply{}; //brace intialize
	int count = 0;
	string tempItem="";
};

void displayMenu(User* Shopper)
{
	for (int i = 0; i < Shopper->count; i++)
	{
		cout << "Item #" << i + 1 << ": " << Shopper->item[i] << endl;
	}
}

bool isItemDuplicate(User* Shopper); //function prototype

void addItems(User* Shopper)
{
	cout << "Enter item name: ";

	string* temp = new string[Shopper->count + 1];//add 1 to size of pointer array every time user adds item

	for (int i = 0; i < Shopper->count; i++)// Copy all items from the current list to the temp
	{
		temp[i] = Shopper->item[i];
	}
	delete[] Shopper->item;
	Shopper->item = temp;

	while (true) 
	{
		cin >> Shopper->tempItem;
		if (isItemDuplicate(Shopper) ==false)
		{
			break;
		}
		cout << "Your item is a duplicate. Please Enter another item!" << endl;
	}

	Shopper->item[Shopper->count] = Shopper->tempItem;
	Shopper->count++;
}

void removeItems(User* Shopper)
{
	cout << "Enter the name of your item to delete it: ";

	cin >> Shopper->tempItem;

	string* temp = new string[Shopper->count - 1];
	int newItemCount = 0;
	for (int i = 0; i < Shopper->count; i++)
	{
		if (Shopper->item[i] != Shopper->tempItem)
		{
			//temp[i-1] = Shopper->item[i]; //move the right item to the left by 1 index
			//Shopper->count--;
			temp[newItemCount] = Shopper->item[i];
			newItemCount++;
		}
	}
	delete[] Shopper->item; //delete the old pointer 

	Shopper->item = temp;
	Shopper->count--;
}

bool isItemDuplicate(User* Shopper)
{
	for (int i = 0; i < Shopper->count; i++)
	{
		if (Shopper->item[i] == Shopper->tempItem)
		{
			return true;
		}
		
	}
	return false;
}

void main()
{
	User* Shopper = new User();
	do
	{
		addItems(Shopper); //add items to list

		if (Shopper->count > 1)
		{
			displayMenu(Shopper);
			cout << "Do you want to delete any items? (Y/N)" << endl;
			cin >> Shopper->reply;

			if (Shopper->reply == 'Y' || Shopper->reply == 'y')
			{
				removeItems(Shopper); //delete item

			}
		}
		displayMenu(Shopper); //display item list

		cout << "Do you want to enter another item? (Y/N)" << endl;
		cin >> Shopper->reply;

	} while (Shopper->reply == 'Y' || Shopper->reply == 'y');
}
