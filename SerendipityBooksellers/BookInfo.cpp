#include "bookinfo.h"
#include <iostream>


using namespace std;

const int STR_SIZE = 51;

void bookInfo(char isbn[STR_SIZE], char title[STR_SIZE], char author[STR_SIZE], 
	char publisher[STR_SIZE], char date[STR_SIZE], int qty, double wholeSale, double retail) {
	cout << "Serendipity BookSellers\n\n";
	cout << "\tBook Information\n\n";

	cout << "ISBN: "<< isbn << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publisher: " << publisher << endl;
	cout << "Date Added: " << date << endl;
	cout << "Quantity In Hand: " << qty << endl;
	cout << "Retail Price: " << retail << endl;

	cout << "Enter Your Choice: \n\n";

}