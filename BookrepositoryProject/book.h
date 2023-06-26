#pragma once
#include <string>
#include "Booktype.h"
using std::string;



class Book
{
public:
	const static int priceArraySize = 3;
protected:
	string bookID;
	string title;
	string author;
	double prices[priceArraySize];
	Booktype bookType;

public:
	Book();/*parameterless constructor*/
	Book(string bookID, string title, string author, double prices[],Booktype booktype);
	

	/*getters*/
	string getID();
	string getTitle();
	string getAuthor();
	double* getPrices();
	virtual Booktype getBookType() = 0;

	/*setters*/
	void setID(string ID);
	void setTitle(string title);
	void setAuthor(string author);
	void setPrices(double prices[]);
	

	virtual void print()=0; 

	~Book();
};


