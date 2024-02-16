#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Pain {
public:
	void add();
	void change();
	void erase();
	void search();
	void fileRead();
	void suffering();
	void order();
	vector <string> v;
	string myText;
	string myLine;
	int i = 0;
	int x = 0;
	int y = 0;
	int addnew = 50;
	ifstream myFile;
private:
	string help[70][4];
	string ID;
	string Name;
	string Price;
	string Cat;
	int changeLine;
	vector <float> pice;
};

void Pain::fileRead() {

	myFile.open("product_data.txt");

	if (myFile.is_open())
	{
		while (getline(myFile, myLine))
		{
			stringstream ss(myLine);

			while (getline(ss, myLine, ','))
			{
				v.push_back(myLine);
			}
			while (true)
			{
				if (i == v.size())
				{
					break;
				}
				if (x == 4)
				{
					x = 0;
					y++;
				}

				help[y][x] = v[i];
				x++;
				i++;
			}
		}
	}
	else
	{
		cout << "not open";
	}
	for (int i = 0; i < addnew; i++) {
		pice.push_back(stof(help[i][2]));
		
	}
}
void Pain::add() {
	
	cout << "input ID\n";
	cin >> ID;
	cout << "input Name\n";
	cin >> Name;
	cout << "input Price\n";
	cin >> Price;
	cout << "input Category\n";
	cin >> Cat;
	help[addnew][0] = ID;
	help[addnew][1] = Name;
	help[addnew][2] = Price;
	help[addnew][3] = Cat;
	addnew++;
}
void Pain::change() {
	cout << "input the line number of the product\n";
	cin >> changeLine;
	cout << "input new info (input x if no change is desired)\n";

	cout << "input ID\n";
	cin >> ID;
	if (ID != "x") {
		help[changeLine][0] = ID;
	}


	cout << "input Name\n";
	cin >> Name;
	if (Name != "x") {
		help[changeLine][1] = Name;
	}

	cout << "input Price\n";
	cin >> Price;
	if (Price != "x") {
		help[changeLine][2] = Price;
	}

	cout << "input Category\n";
	cin >> Cat;
	if (Cat != "x") {
		help[changeLine][3] = Cat;
	}
	
}
void Pain::erase() {
	cout << "Warning this will erase the product permanently\n";
	cout << "Continue? (y/n) \n";
	cin >> ID;
	if (ID == "y") {
		cout << "Input the line number of the product ID\n";
		cin >> changeLine;
		for (int i = 0; i < 4; i++) {
			help[changeLine][i] = "";
		}
	}
	
}
void Pain::search() {
	cout << "input the word you're looking for\n";
	cin >> ID;
	for (int i = 0; i < addnew; i++) {
		for (int j = 0; j < 4; j++) {
			if (help[i][j].find(ID) != string::npos) {
				cout << i << ": " << help[i][j] << "\n";
			}
			
		}
	}
}
void Pain::suffering() {

	for (int i = 0; i < addnew; i++) {
		for (int j = 0; j < 4; j++) {
			cout << i << ": " << help[i][j] << "\n";
		}
	}
	
}


void Pain::order() {
	string huuu[70][4];
	int arrr [70]
	int j = 0;
	sort(pice.begin(), pice.end());
	for (int i = 0; i < addnew;) 
	{
		x = 0;
		if (pice.begin() == stof(help[i][2]))
		{
			while (x < 4) 
			{
				huuu[i][x] = help[i][x];
				x++;
			}
			i++;
		}
		else
		{
			j++;
		}
	}
	cout << huuu;
}


int main(){
	Pain pain;
	pain.fileRead();
	pain.myFile.close();
	int choice;
	do {
		cout << "\nShopping Database\n\n";
		cout << "0 - Quit\n";
		cout << "1 - See the list\n";
		cout << "2 - Add to list\n";
		cout << "3 - Edit the list\n";
		cout << "4 - Delete item on list\n";
		cout << "5 - Search the list\n\n";
		cout << "Choice: ";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			pain.suffering();;
			break;
		case 2:
			pain.add();
			break;
		case 3:
			pain.change();
			break;
		case 4:
			pain.erase();
			break;
		case 5:
			pain.search();
			break;
		case 6:
			pain.order();
			break;

		default:
			std::cout << "\nSorry, but " << choice << " is not a valid choice.\n";
		}
	} while (choice != 0);
	return 0;
}


