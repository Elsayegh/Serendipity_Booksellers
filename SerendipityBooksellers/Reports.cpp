#include "reports.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "bookdata.h"

using namespace std;

const int NUM_BOOKS = 20;
extern BookData book[NUM_BOOKS];

void reports() {
	int choice = 0;
	while (choice != 7)
	{
		cout << "Serendipity BookSellers\n\n";
		cout << "\tReports\n\n";

		cout << "1. Inventory Listing\n";
		cout << "2. Inventory Wholesale Value\n";
		cout << "3. Inventory Retail Value\n";
		cout << "4. Listing By Quantity\n";
		cout << "5. Listing By Cost\n";
		cout << "6. Listing By Age\n";
		cout << "7. Return To The Main Menu\n\n\n";

		cout << "Enter Your Choice: ";
		cin >> choice;

		while (choice < 1 || choice > 7) {
			cout << "\nPlease Enter the number in the range 1 - 7 \n";
			cout << "Enter your choice: ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			repListing();
			break;
		case 2:
			repWholesale();
			break;
		case 3:
			repRetail();
			break;
		case 4:
			repQty();
			break;
		case 5:
			repCost();
			break;
		case 6:
			repAge();
			break;
		case 7:
			cout << "\nYou Selected Item 7 ";
			break;

		}
		cout << endl;
	}
}

void repListing() {

	char end[] = { '\0' };
	char date[STR_SIZE];
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Book Sellers Inventory Report\n";
	cout << "Date: \t\t" << date;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn,end) != 0)
		{
			cout << "_________________________________________________________";
			cout << "\n\nTitle: \t\t\t" << book[i].bookTitle;
			cout << "\nISBN: \t\t\t" << book[i].isbn;
			cout << "\nAuthor: \t\t\t" << book[i].author;
			cout << "\nPublisher: \t\t" << book[i].publisher;
			cout << "\nDate Added: \t\t" << book[i].dateAdded;
			cout << fixed << showpoint << right << setprecision(2);
			cout << "\nQuantity on hand: \t" << book[i].qtyOnHand;
			cout << "\nWholeSale Cost: \t\t" << book[i].wholesale;
			cout << "\nRetail Cost: \t\t" << book[i].retail; 
		}
	}

	cout << "\n\n________________________________________________________________";
	cout << "\n\nEnd of the inventory report.\n\n\n";

	//Pause the screen
	cout << "Press enter to continue";
	cin.ignore();
	cin.get();
}

void repWholesale() {
	char end[] = { '0' };
	char date[STR_SIZE];
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Book Sellers WholeSale Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t ISBN\t\t Quantity\t WholeSale\n";
	cout << "\t_______________________________________________\n";

	double itemSubTotal = 0;
	double subTotal = 0;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0) {
			cout << "\n\t" << left << setw(26) << book[i].bookTitle;
			cout << left << setw(14) << book[i].isbn;
			cout << right << setw(6) << book[i].qtyOnHand << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << book[i].wholesale;

			itemSubTotal = book[i].qtyOnHand * book[i].wholesale;
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\nTotal WholeSale Value: $ " << subTotal << endl;
	cout << "\t__________________________________________________________________\n";
	cout << "\n\tEnd of the wholsale report\n\n\n";
	//Pause the screen
	cout << "Press enter to continue";
	cin.ignore();
	cin.get();

}

void repRetail() {
	char end[] = { '\0' };
	char date[STR_SIZE];
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Book Sellers Retail Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t ISBN\t\t Quantity\t Retail\n";
	cout << "\t_______________________________________________\n";
	
	double itemSubTotal = 0;
	double subTotal = 0;

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		if (strcmp(book[i].isbn, end) != 0) {
			cout << "\n\t" << left << setw(26) << book[i].bookTitle;
			cout << left << setw(14) << book[i].isbn;
			cout << right << setw(6) << book[i].qtyOnHand << "\t";
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << "\t$ " << book[i].retail;

			itemSubTotal = book[i].qtyOnHand * book[i].retail;
			subTotal += itemSubTotal;
		}
	}

	cout << "\n\n\nTotal Retail Value: $ " << subTotal << endl;
	cout << "\t__________________________________________________________________\n";
	cout << "\n\tEnd of the Retails report\n\n\n";
	//Pause the screen
	cout << "Press enter to continue";
	cin.ignore();
	cin.get();

}

void repQty() {

	int id[NUM_BOOKS];
	int* idPtr[NUM_BOOKS];
	int* qtyPtr[NUM_BOOKS];

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		qtyPtr[i] = &book[i].qtyOnHand;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	int* maxValue;

	for (startScan = 0; startScan < NUM_BOOKS; startScan++)
	{
		maxIndex = startScan;
		maxValue = qtyPtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(qtyPtr[index]) > *maxValue)
			{
				maxValue = qtyPtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		qtyPtr[maxIndex] = qtyPtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		qtyPtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE];
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Book Sellers Quantity Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t ISBN\t\t Quantity\n";
	cout << "\t_______________________________________________\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[j].isbn, end) != 0)
		{
			cout << "\n\t<<" << left << setw(26) << book[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << book[*(idPtr[j])].isbn;
			cout << right << setw(6) << *qtyPtr[j] << "\n";
		}
	}

	
	cout << "\t__________________________________________________________________\n";
	cout << "\n\tEnd of the Quantity  report\n\n\n";
	//Pause the screen
	cout << "Press enter to continue";
	cin.ignore();
	cin.get();
}

void repCost() {
	
	int id[NUM_BOOKS];
	int* idPtr[NUM_BOOKS];
	double* wholePtr[NUM_BOOKS];

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		wholePtr[i] = &book[i].wholesale;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	double* maxValue; 

	for (startScan = 0; startScan < NUM_BOOKS; startScan++)
	{
		maxIndex = startScan;
		maxValue = wholePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue = wholePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		wholePtr[maxIndex] = wholePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		wholePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE];
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Book Sellers Cost Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t ISBN\t\t Quantity\t WholeSale\n";
	cout << "\t_______________________________________________\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[j].isbn, end) != 0)
		{
			cout << "\n\t<<" << left << setw(26) << book[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << book[*(idPtr[j])].isbn;
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << book[j].qtyOnHand;
			cout << setw(6) << "/t$ "<< *wholePtr[j] << "\n";
		}
	}


	cout << "\t__________________________________________________________________\n";
	cout << "\n\tEnd of the Cost report\n\n\n";
	//Pause the screen
	cout << "Press enter to continue";
	cin.ignore();
	cin.get();
}

void repAge() {
	
	int id[NUM_BOOKS];
	int* idPtr[NUM_BOOKS];
	char* datePtr[NUM_BOOKS];

	for (int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		datePtr[i] = book[i].dateAdded;
	}

	int startScan;
	int maxIndex;
	int* tempId;
	char* maxValue;

	for (startScan = 0; startScan < NUM_BOOKS; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];

		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(datePtr[index]) > *maxValue)
			{
				maxValue = datePtr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}

		datePtr[maxIndex] = datePtr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		datePtr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

	char date[STR_SIZE];
	cout << "\n\nEnter Today's date: ";
	cin >> date;
	cout << endl;

	cout << "\n\n\t\tSerendipity Book Sellers Date Added Report\n";
	cout << "Date: \t\t" << date;

	cout << "\n\tTitle\t\t\t ISBN\t\t Quantity\t DateAdded\n";
	cout << "\t_______________________________________________\n";

	char end[] = { '\0' };
	for (int j = 0; j < NUM_BOOKS; j++)
	{
		if (strcmp(book[j].isbn, end) != 0)
		{
			cout << "\n\t<<" << left << setw(26) << book[*(idPtr[j])].bookTitle;
			cout << left << setw(14) << book[*(idPtr[j])].isbn;
			cout << fixed << showpoint << right << setprecision(2);
			cout << right << setw(6) << book[j].qtyOnHand;
			cout << setw(6) << "/t$ " << book[*(idPtr[j])].dateAdded << "\n";
		}
	}


	cout << "\t__________________________________________________________________\n";
	cout << "\n\tEnd of the Date Added report\n\n\n";
	//Pause the screen
	cout << "Press enter to continue";
	cin.ignore();
	cin.get();
}