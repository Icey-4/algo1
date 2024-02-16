#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Pain {
public:
	void add();
	void change();
	void erase();
	void search();
	void fileRead();
	void suffering();
	void sort();
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
};

void Pain::fileRead(){
	
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


void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

	// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

		// select the rightmost element as pivot
	int pivot = array[high];

		// pointer for greater element
	int i = (low - 1);

		// traverse each element of the array
		// compare them with the pivot
		for (int j = low; j < high; j++) {
			if (array[j] <= pivot) {

				// if element smaller than pivot is found
				// swap it with the greater element pointed by i
				i++;

				// swap element at i with element at j
				swap(&array[i], &array[j]);
			}
		}

		// swap pivot with the greater element at i
		swap(&array[i + 1], &array[high]);

		// return the partition point
		return (i + 1);
	}

	void quickSort(int array[], int low, int high) {
		if (low < high) {

			// find the pivot element such that
			// elements smaller than pivot are on left of pivot
			// elements greater than pivot are on righ of pivot
			int pi = partition(array, low, high);

			// recursive call on the left of pivot
			quickSort(array, low, pi - 1);

			// recursive call on the right of pivot
			quickSort(array, pi + 1, high);
		}
	}

	// Driver code
void sad() {
	int data[] = { 8, 7, 6, 1, 0, 9, 2 };
	int n = sizeof(data) / sizeof(data[0]);

	cout << "Unsorted Array: \n";
	//printArray(data, n);

		// perform quicksort on data
	quickSort(data, 0, n - 1);

	cout << "Sorted array in ascending order: \n";
	//printArray(data, n);
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
		default:
			std::cout << "\nSorry, but " << choice << " is not a valid choice.\n";
		}
	} while (choice != 0);
	return 0;
}


