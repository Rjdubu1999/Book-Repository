
#include"repo.h"



int main()
{
	const string bookData[] =
	{
		"F1,Forensics for Housewives!,Genevieve Valentin,23.4,45.99,35,NONFICTION",
		"F2,Usless Cyberpunk Gamer Chat,Superkool CyberDog,0,19.99,200,FICTION",
		"U1,A Primer of Educational Wisdom, Sage the Divine Goddess,0.99,12.45,987.65,UNDECIDED",
		"F3,Mein Kampf est NICHT Fiction!,Adolf Hitler's Corpse,0,1,2.49,FICTION",
		"N1,An Agonizing Death from C++,David Wayne Bishop,999.99,3.14,123,NONFICTION",
	};

	const int numBooks = 5;
	Repo repo;

	for (int i = 0; i < numBooks; i++) repo.parse(bookData[i]);
		cout << "Displaying all books:" << std::endl;
		repo.printAll();
		cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			cout << "Displaying by book type:" << std::endl;
			repo.printByBookType((Booktype)i);
		}

	cout << "Displaying books with invalid IDs" << std::endl;
	repo.printInvalidIDs();

	cout << "Removing book with ID N_W1:" << std::endl;
	repo.removeBookByID("N_W1");
	cout << std::endl;

	cout << "Removing book with IdN_W1:" << std::endl;
	repo.removeBookByID("N_W1");
	cout << std::endl;

	system("Pause");
	return 0;
}