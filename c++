#include <iostream>

using namespace std;

int BookID[50];
string BookTitle[50];
string BookAuthor[50];
bool IsBorrowed[50];
int BookCount = 0;

void AddBook()
{
	cout << "\nPlease enter book ID" << endl;
	cin >> BookID[BookCount];
	for (int i = BookCount; i >= 0; i--)
	{
		for (int j = 0; j < BookCount; j++)
		{
			if (i != j && BookID[i] == BookID[j])
			{
				cout << "Error!";
				return;
			}
		}
	}
	cout << "Please enter book title" << endl;
	cin >> BookTitle[BookCount];

	cout << "Please enter book author" << endl;
	cin >> BookAuthor[BookCount];

	IsBorrowed[BookCount] = false;
	BookCount++;
	cout << "Added Succesfully" << endl;
}

void DisplayBooks()
{
	if (BookCount == 0)
	{
		cout << "\aSorry! There is not books in library" << endl;
		return;
	}
	cout << "\n\t\t Book List\n\n" << endl;
	cout << "________________________________________________" << endl;
	for (int i = 0; i < BookCount; i++)
	{
		string status = IsBorrowed[i] ? "Unavailable" : " Available ";

		cout << BookID[i] << " : " << BookTitle[i] << " : " << BookAuthor[i] << " : " << status << endl;
		cout << "________________________________________________" << endl;
	}

}

void BorrowBook()
{
	if (BookCount == 0)
	{
		cout << "Sorry! There is not books in library" << endl;
		return;
	}
	int bookid;
	cout << "\nPlease enter Book ID" << endl;
	cin >> bookid;
	for (int i = 0; i < BookCount; i++)
	{
		if (BookID[i] == bookid)
		{
			if (IsBorrowed[i])
			{
				cout << "\aSorry! This book is Borrowed" << endl;
			}
			else
			{
				cout << "Borrowed Succesfully" << endl;
				IsBorrowed[i] = true;
				return;
			}
		}
	}
	cout << "\aSoory! There is not Book have this ID" << endl;
}

void ReturnBook()
{
	if (BookCount == 0)
	{
		cout << "\aSorry! There is not books in library" << endl;
		return;
	}
	int bookid;
	cout << "\nPlease enter Book ID" << endl;
	cin >> bookid;
	for (int i = 0; i < BookCount; i++)
	{
		if (BookID[i] == bookid)
		{
			if (IsBorrowed[i])
			{
				cout << "Returned Succesfully" << endl;
				IsBorrowed[i] = false;
			}
			else {
				cout << "\aError!!!\nThis book Is not Borrowed! " << endl;
			}
			return;
		}
	}
	cout << "\aThis ID is wrong!" << endl;
}

void StartLibrary()
{
	int choice;
	do
	{
		cout << "\n\nWelcome to PB3-M Library Please enter A number to help you." << endl;
		cout << "1) Add New Book" << endl;
		cout << "2) Display All Books" << endl;
		cout << "3) Borrow Book" << endl;
		cout << "4) Return Book" << endl;
		cout << "5) Exit\n\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			AddBook();
			break;
		case 2:
			DisplayBooks();
			break;
		case 3:
			BorrowBook();
			break;
		case 4:
			ReturnBook();
			break;
		case 5:
			cout << "Thank you For your Visiting" << endl;
			break;
		default:
			cout << "\aWrong Choice!" << endl;
		}
	} while (choice != 5);
}

int main()
{
	StartLibrary();

	system("pause");
	return 0;
}
