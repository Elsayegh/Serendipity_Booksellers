#ifndef BOOKDATA_H
#define BOOKDATA_H

const int STR_SIZE = 51;

struct BookData
{
	char bookTitle[STR_SIZE];
	char isbn[STR_SIZE];
	char author[STR_SIZE];
	char publisher[STR_SIZE];
	char dateAdded[STR_SIZE];
	int qtyOnHand;
	double wholesale;
	double retail;
};

void setTitle(char*, int);
void setISBN(char*, int);
void setAuthor(char*, int);
void setPub(char*, int);
void setDateAdded(char*, int);
void setQty(int, int);
void setWholesale(double, int);
void setRetail(double, int);
int isEmpty(int);
void removeBook(int);

#endif // !BOOKDATA_H
