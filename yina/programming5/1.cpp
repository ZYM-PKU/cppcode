#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

enum Genre { fiction = 1, nonfiction, periodical, biography, children };

class book
{
protected:
	string name;
	string auther;
	string ISBN;
	int year, month, day;
	bool borrowed;
	enum Genre bookclass;
public:
	book() :year(0), month(0), day(0), borrowed(false), bookclass(fiction) {}
	~book() {}
	book(string _name, string _auther, string _ISBN, int _bookclass, int _year, int _month, int _day = 0) {
		name = _name; auther = _auther; ISBN = _ISBN; year = _year; month = _month; day = _day;
		borrowed = false; bookclass = (enum Genre)_bookclass;
	}
	string getname() { return name; }
	string getauther() { return auther; }
	string getISBN() { return ISBN; }
	string getbookclass() {
		switch (bookclass)
		{
		case fiction:return "fiction"; break;
		case nonfiction:return"nonfiction"; break;
		case periodical:return"periodical"; break;
		case biography:return"biography"; break;
		case children:return"children"; break;
		default:
			break;
		}
	}
	bool isborrowed() { return borrowed; }
	void lend() { borrowed = true; }
	void give_back() { borrowed = false; }
	friend ostream& operator<<(ostream& os, book& bk);
	friend istream& operator>>(istream& is, book& bk);
	bool operator== (const book& book1)const;
	bool operator!= (const book& book1)const;
};

ostream& operator<<(ostream& os, book& bk) {
	os << bk.name << " " << bk.auther << " " << bk.ISBN << " ";
	if (bk.day)os << bk.year << "-" << bk.month << "-" << bk.day<<" ";
	else os << bk.year << "-" << bk.month<<" ";
	os << bk.getbookclass();
	cout << endl;
	return os;
}

istream& operator>>(istream& is, book& bk) {
	is >> bk.name >> bk.auther >> bk.ISBN;
	string date, bkclass;
	is >> date >> bkclass;
	char substr1[4] = { 0 }, substr2[4] = { 0 };
	if (date.find_last_of('-') == date.find_first_of('-')) {
		bk.year = stoi(date.substr(0, 4));
		date.copy(substr1, date.size() - 5, 5);
		bk.month = atoi(substr1);
	}
	else {
		bk.year = stoi(date.substr(0, 4));
		date.copy(substr1, date.find_last_of('-') - date.find_first_of('-') - 1, 5);
		date.copy(substr2, date.size() - date.find_last_of('-') - 1, date.find_last_of('-') + 1);
		bk.month = atoi(substr1);
		bk.day = atoi(substr2);
	}
	if (bkclass == "ficiton")bk.bookclass = fiction;
	else if (bkclass == "nonfiction")bk.bookclass = nonfiction;
	else if (bkclass == "periodical")bk.bookclass = periodical;
	else if (bkclass == "biography")bk.bookclass = biography;
	else if (bkclass == "children")bk.bookclass = children;
	return is;
}

bool book::operator==(const book& book1)const {
	return ISBN == book1.ISBN;
}
bool book::operator!=(const book& book1)const {
	return ISBN != book1.ISBN;
}

vector<book>library;

bool cmp(book& book1, book& book2) {
	return book1.getISBN() < book2.getISBN();
}
int main() {
	while (cin) {
		char test;
		if (cin >> test)cin.putback(test);
		else break;
		book currbk;
		cin >> currbk;
		library.push_back(currbk);
	}
	sort(library.begin(), library.end(), cmp);
	for (book bk : library)cout << bk;
	return 0;
}