#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "strupper.h"
#include "bookdata.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std;

const int NUM_BOOKS = 20;

extern BookData book[NUM_BOOKS];


void cashier() {

	const double SALES_TAX = 0.06; //6 percent sales tax
	char isbnNumber[NUM_BOOKS][STR_SIZE];
	char thisTitle[NUM_BOOKS][STR_SIZE];
	int quantityBooks[NUM_BOOKS];
	double unitPrice[NUM_BOOKS];
	double subTotal[NUM_BOOKS];
	char transDate[STR_SIZE];
	double orderSalesTax = 0;
	double runningTotal = 0;
	double grandTotal = 0;
	int validQty;
	char choice = 'y';
	int counter = 0;
	string message;


	while (choice == 'Y' || choice == 'y')
	{
		cout << "Serendipity BookSellers\n\n";
		cout << "Cashier Module \n\n";

		//cin.ignore();
		cout << "Enter Date: ";
		cin.getline(transDate, STR_SIZE);

		cout << "Enter ISBN: ";
		cin.getline(isbnNumber[counter], STR_SIZE);
		strUpper(isbnNumber[counter]);

		for (int row = 0; row < NUM_BOOKS; row++)
		{
			if (strcmp(isbnNumber[counter],book[row].isbn) == 0) {

				cout << "Title: " << book[row].bookTitle << endl;
				cout << fixed << showpoint << setprecision(2) << "Price: " << book[row].retail << endl;

				unitPrice[counter] = book[row].retail;
			    strcpy(thisTitle[counter], book[row].bookTitle);
				validQty = book[row].qtyOnHand;

				if (validQty == 0) {
					cout << "The book is out of stock!\n\n";
					return;
				}

				cout << "Enter quantity of book: ";
				cin >> quantityBooks[counter];

				while (quantityBooks[counter] < 1 || quantityBooks[counter] > validQty)
				{
					if (quantityBooks[counter] < 1)
						cout << "\nPlease enter a vaild quantity: \n\n";
					else
						cout << "\nSorry, Insufficient quantity in inventory\n\n";

					cout << "Enter Quantity of book: ";
					cin >> quantityBooks[counter];
				}

				book[row].qtyOnHand -= quantityBooks[counter];
				counter++;
				message = "\nAdd another title to this order? ";
				choice = anotherTransaction(message);
				cout << endl;
				break;
			}
			else if (row == NUM_BOOKS- 1)
			{
				cout << "\nISBN number was not found.\n\n";
				message = "Re-Enter ISBN number?\n";
				choice = anotherTransaction(message);

			}
		}


		cout << endl;
	}

	if (counter > 0) {

		cout << "Date" << transDate << "\n\n\n";
		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
		cout << "________________________________________________________________________________";
		cout << "\n\n\n";

		for (int i = 0; i < counter; i++)
		{
			subTotal[i] = (quantityBooks[i] * unitPrice[i]);
			orderSalesTax += (subTotal[i] * SALES_TAX);
			runningTotal += subTotal[i];
			grandTotal = (orderSalesTax + runningTotal);

			//inline data
			cout << quantityBooks[i] << "\t";//show quantity
			cout << left << setw(14) << isbnNumber[i] << "\t"; //ISBN
			cout << left << setw(26) << thisTitle[i] << "\t$ "; //title
			cout << fixed << showpoint << right << setprecision(2);
			cout << setw(6) << unitPrice[i] << "\t$ "; //price
			cout << setw(6) << subTotal[i] << "\n\n\n\t$"; //subtotal
		}

		//calculated totals

		cout << "\t\tSubtotal:\t\t\t\t\t\t$";
		cout << setw(6) << runningTotal << "\n";
		cout << "\t\t\tTax:\t\t\t\t\t\t\t";
		cout << setw(6) << orderSalesTax << "\n";
		cout << "\t\t\tTotal:\t\t\t\t\t\t\t$";
		cout << setw(6) << grandTotal << "\n\n";

		cout << "\n\nThank you for shopping at Serendipity!\n\n";
	}

	cout << endl;
} 



char anotherTransaction(string message) {
	char choice;
	cout << message;
	cout << "Y = Yes, N = No\n";
	cout << "Enter your choice: ";
	cin >> choice;
	cin.ignore();

	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		cout << "\nPlease enter Y for yes or N for no\n\n";
		cout << message;
		cin >> choice;
		cin.ignore();
	}
	return choice;
}