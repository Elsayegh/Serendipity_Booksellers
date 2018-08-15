#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
#include <string>
#include "strupper.h"
#include "bookdata.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std;

const int NUM_BOOKS = 20;
extern BookData book[NUM_BOOKS];


void invMenu() {
	int choice = 0;
	while (choice != 5) {
		cout << "Serendipity BookSellers\n\n";
		cout << "     Inventory Database\n\n";

		cout << "1. Look Up a book\n";
		cout << "2. Add a Book\n";
		cout << "3. Edit a book's Record\n";
		cout << "4. Delete a Book\n";
		cout << "5. Return to the main Menu\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		while (choice < 1 || choice > 5) {
			cout << "\nPlease Enter the number in the range 1 - 5 \n";
			cout << "Enter your choice: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			lookUpBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			cout << "\nYou Selected Item 5 ";
			break;
		}
		cout << endl;
	}
}

void lookUpBook() {

	char YesNo = ' ';
	int row = 0;
	char title[STR_SIZE];

	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	cin.getline(title, STR_SIZE);

	strUpper(title);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(book[row].bookTitle, title))
		{
			cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
			cout << "Is this the correct match?  (Y OR N) ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
				cout << "Is this the correct match?  (Y OR N) ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y') {
				bookInfo(book[row].isbn, book[row].bookTitle, book[row].author, book[row].publisher,
					book[row].dateAdded, book[row].qtyOnHand, book[row].wholesale, book[row].retail);
				break;
			}
		}
	}
	if (row > NUM_BOOKS - 1)
		cout << "The book you searched for is not in the inventory" << endl;

}

void addBook() {

	char title[STR_SIZE];
	char isbn[STR_SIZE];
	char publisher[STR_SIZE];
	char author[STR_SIZE];
	char date[STR_SIZE];
	int quantity;
	double wholeSale;
	double retail;
	int row;

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (isEmpty(row)) {
			cin.ignore();
			cout << "Enter Title: ";
			cin.getline(title, STR_SIZE);
			setTitle(title, row);

			cout << "Enter ISBN: ";
			cin.getline(isbn, STR_SIZE);
			setISBN(isbn, row);

			cout << "Enter Author: ";
			cin.getline(author, STR_SIZE);
			setAuthor(author, row);

			cout << "Enter Publisher: ";
			cin.getline(publisher, STR_SIZE);
			setPub(publisher, row);

			cout << "Enter date added to inventory: ";
			cin.getline(date, STR_SIZE);
			setDateAdded(date, row);

			cout << "Enter quantity added: ";
			cin >> quantity;
			setQty(quantity, row);

			cout << "Enter whole sale price: ";
			cin >> wholeSale;
			setWholesale(wholeSale, row);

			cout << "Enter retail price: ";
			cin >> retail;
			setRetail(retail, row);

			cout << "\n\nRecord Was Entered.";

			break;
		}
		cout << "No more books maybe added.\n";
	}
}

void editBook() {

	char title[STR_SIZE];
	char isbn[STR_SIZE];
	char publisher[STR_SIZE];
	char author[STR_SIZE];
	char date[STR_SIZE];
	int quantity;
	double wholeSale;
	double retail;
	int row;
	int choice = 0;
	char YesNo = ' ';
	//char searchTitle[STR_SIZE];

	cin.ignore();

	cout << "Enter the title of the book you need to edit: ";
	cin.getline(title, STR_SIZE);
	strUpper(title);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(book[row].bookTitle, title))
		{
			cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
			cout << "Is this the correct match?  (Y OR N) ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
				cout << "Is this the correct match?  (Y OR N) ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y') {
				bookInfo(book[row].isbn, book[row].bookTitle, book[row].author, book[row].publisher,
					book[row].dateAdded, book[row].qtyOnHand, book[row].wholesale, book[row].retail);
				break;

				do
				{
					cout << "\nYou may edit any of the following: " << endl;
					cout << "1. ISBN\n";
					cout << "2. Title\n";
					cout << "3. Author\n";
					cout << "4. Publisher\n";
					cout << "5. Date book was added to inventory\n";
					cout << "6. Quantity oh hand\n";
					cout << "7. WholeSale Cost\n";
					cout << "8. Retail price\n";
					cout << "9. Exit\n";
					cin >> choice;

					while (choice < 1 || choice > 9) {
						cout << "\nPlease enter a number in between the range 1 and 9. " << endl;
						cout << "Enter your choice: ";
						cin >> choice;
					}

					switch (choice)
					{
					case 1:
						cout << "\nCurrent ISBN: ";
						cout << book[row].isbn << endl;
						cin.ignore();
						cout << "Enter new ISBN: ";
						cin.getline(isbn, STR_SIZE);
						setISBN(isbn, row);
						break;

					case 2:
						cout << "\nCurrent Title: ";
						cout << book[row].bookTitle << endl;
						cin.ignore();
						cout << "Enter new title: ";
						cin.getline(title, STR_SIZE);
						setTitle(title, row);
						break;

					case 3:
						cout << "\nCurrent Author: ";
						cout << book[row].author;
						cin.ignore();
						cout << "Enter new author: ";
						cin.getline(author, STR_SIZE);
						setAuthor(author, row);
						break;

					case 4:
						cout << "\nCurrent Publisher: ";
						cout << book[row].publisher << endl;
						cin.ignore();
						cout << "Enter new publisher: ";
						cin.getline(publisher, STR_SIZE);
						setPub(publisher, row);
						break;

					case 5:
						cout << "\nCurrent date added: ";
						cout << book[row].dateAdded << endl;
						cin.ignore();
						cout << "Enter new date: ";
						cin.getline(date, STR_SIZE);
						setDateAdded(date, row);
						break;

					case 6:
						cout << "\nCurrent quantity on hand: ";
						cout << book[row].qtyOnHand << endl;
						cin.ignore();
						cout << "Enter new quantity on hand: ";
						cin >> quantity;
						setQty(quantity, row);
						break;

					case 7:
						cout << "\nCurrent Wholesale cost: ";
						cout << book[row].wholesale << endl;
						cin.ignore();
						cout << "Enter new Wholesale cost: ";
						cin >> wholeSale;
						setWholesale(wholeSale, row);
						break;

					case 8:
						cout << "\nCurrent retail price: ";
						cout << book[row].retail << endl;
						cin.ignore();
						cout << "Enter new retail price: ";
						cin >> retail;
						setRetail(retail, row);
						break;
					}
				} while (choice != 9);
				break;
			}
		}
	}
	if (row > NUM_BOOKS - 1) 
		cout << "\nSorry, no title matching: " << title << "was found\n\n";
}


void deleteBook() {

	char title[STR_SIZE];
	int row = 0;
	//char response;
	char YesNo = ' ';

	cin.ignore();

	cout << "Enter the title of the book to delete: ";
	cin.getline(title, STR_SIZE);

	strUpper(title);

	for (row = 0; row < NUM_BOOKS; row++)
	{
		if (strstr(book[row].bookTitle, title))
		{
			cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
			cout << "Is this the correct match?  (Y OR N) ";
			cin >> YesNo;

			while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n')
			{
				cout << "Please enter Y or N\n\n";
				cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
				cout << "Is this the correct match?  (Y OR N) ";
				cin >> YesNo;
			}

			if (YesNo == 'Y' || YesNo == 'y') {
				if (YesNo == 'Y' || YesNo == 'y') {
					bookInfo(book[row].isbn, book[row].bookTitle, book[row].author, book[row].publisher,
						book[row].dateAdded, book[row].qtyOnHand, book[row].wholesale, book[row].retail);
					break;
					cout << "Would you like to delete the entire record? Y\N\: ";
					cin >> YesNo;

					while (YesNo != 'Y' && YesNo != 'y' && YesNo != 'N' && YesNo != 'n') {
						cout << "Please enter Y or N\n\n";
						cout << "\nPossible match found: " << book[row].bookTitle << "\n\n";
						cout << "Would you like to delete the entire record? Y\N\: ";
						cin >> YesNo;
					}
					if (YesNo == 'Y' || YesNo == 'y') {
						removeBook(row);
						cout << "\nRecord was deleted\n";
					}
					else
						cout << "\nRecord wasn't deleted\n";
					break;
				}
			}
		}
		if (row > NUM_BOOKS - 1)
			cout << "\nSorry, no title matching: " << title << "was found\n\n";
	}
}