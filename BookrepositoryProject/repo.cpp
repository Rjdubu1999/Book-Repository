#include "repo.h"
void Repo::parse(string bookdata)
{
	Booktype bt = UNDECIDIED;
	if (bookdata.at(0) == 'F') bt = FICTION;
	else if (bookdata.at(0) == 'N') bt = NONFICTION;
	

	int rhs = bookdata.find(",");
	string bID = bookdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = bookdata.find(",",lhs);
	string ttl = bookdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	string aut = bookdata.substr(lhs, rhs - lhs);
	double p1 = stod(bookdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	double p2 = stod(bookdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	double p3 = stod(bookdata.substr(lhs, rhs - lhs));


	double p[3];
	(bookdata.substr(lhs, rhs - lhs));
	
	add(bID, ttl, aut, p1,p2,p3,bt);

}


void Repo::add(string bookID, string title, string author, double price1, double price2, double price3, Booktype bt)
{

	double parr[3] = { price1,price2,price3 };

	bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt);

}

void Repo::printAll()
{
	Book::printHeader();
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		cout << bookRepoArray[i]->getID();cout << '\t';
		cout << bookRepoArray[i]->getTitle();cout << '\t';
		cout << bookRepoArray[i]->getAuthor(); cout << '\t';
		cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
		cout << bookRepoArray[i]->getPrices()[1];cout << '\t';
		cout << bookRepoArray[i]->getPrices()[2]; cout<< '\t';
		cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;
	}
}

void Repo::printByBookType(Booktype bt)
{
	Book::printHeader();
	for (int i = 0; i <= Repo::lastIndex; i++) {
		if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();

	}
	cout << std::endl;

}

void Repo::printInvalidIDs()
{
	bool any = false;
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		string bID = (bookRepoArray[i]->getID());
		if (bID.find('_') == string::npos || (bID.find('X') == string::npos && bID.find('x') == string::npos))
		{
			any = true;
			cout << bID << ":" << bookRepoArray[i]->getTitle() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Repo::printAveragePrices()
{
	for (int i = 0; i <= Repo::lastIndex; i++)
	{

		cout << bookRepoArray[i]->getID() << ":";
		cout << (bookRepoArray[i]->getPrices()[0]
			+ bookRepoArray[i]->getPrices()[1]
			+ bookRepoArray[i]->getPrices()[2]) / 3.0 << std::endl;

	}
	cout << std::endl;
}

void Repo::removeBookByID(string bookId)
{
	bool success = false;
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		if (bookRepoArray[i]->getID() == bookId)
		{
			success = true;
			if (i < numBooks - 1)
			{
				Book* temp = bookRepoArray[i];
				bookRepoArray[i] = bookRepoArray[numBooks - 1];
				bookRepoArray[numBooks - 1] = temp;

			}
			Repo::lastIndex--;
		}
	}
	if (success)
	{
		cout << bookId << "removed from repository." << std::endl << std::endl;
		this->printAll();
	}
	else cout << bookId << "not found." << std::endl << std::endl;
}

Repo::~Repo()
{
	cout << "Destructor Called!!!" << std::endl << std::endl;
	for (int i = 0; i < numBooks; i++)
	{
		cout << "Destroying book #" << i + 1 << std::endl;
		delete bookRepoArray[i];
		bookRepoArray[i] = nullptr;
	}
}