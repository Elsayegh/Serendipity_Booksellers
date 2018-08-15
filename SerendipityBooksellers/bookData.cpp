#include <cstring>
#include"bookdata.h"
#include"strupper.h"

using namespace std;

const int NUM_BOOKS = 20;
extern BookData book[NUM_BOOKS]; 

void setTitle(char* newTitle, int subscript)
{
	strUpper(newTitle);
	strcpy(book[subscript].bookTitle, newTitle);
}

void setISBN(char* newISBN, int subscript)
{
	strUpper(newISBN);
	strcpy(book[subscript].isbn, newISBN);
}

void setAuthor(char* newAuthor, int subscript)
{
	strUpper(newAuthor);
	strcpy(book[subscript].author, newAuthor);
}

void setPub(char* newPublisher, int subscript)
{
	strUpper(newPublisher);
	strcpy(book[subscript].publisher, newPublisher);
}

void setDateAdded(char* newDate, int subscript)
{
	strUpper(newDate);
	strcpy(book[subscript].dateAdded, newDate);
}

void setQty(int newQuantity, int subscript)
{
	book[subscript].qtyOnHand = newQuantity;
}

void setWholesale(double newWholesale, int subscript)
{
	book[subscript].wholesale = newWholesale;
}

void setRetail(double newRetail, int subscript)
{
	book[subscript].retail = newRetail;
}

int isEmpty(int subscript) {
	if (book[subscript].bookTitle[0] == 0)
		return 1;
	else
		return 0;
}

void removeBook(int subscript) {
	book[subscript].bookTitle[0] = 0;
	book[subscript].isbn[0] = 0;
}
