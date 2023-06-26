#pragma once
#include "book.h"

class Repo
{
private:
	int lastIndex = -1;
	const static int numBooks = 5;
	Book* bookRepoArray[numBooks];

public:
	void parse(string row);
	void add(string bID,
		string bTitle,
		string bAuthor,
		double bprice1,
		double bprice2,
		double bprice3,
		Booktype bt);
	void printAll();
	void printByBookType(Booktype bt);
	void printInvalidIDs();
	void printAveragePrices();
	void removeBookByID(string bookID);
	~Repo();
};