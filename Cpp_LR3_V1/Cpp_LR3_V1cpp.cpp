#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

/*
* A structure that contains the day month and year of the worker's birthday
*/
struct Birth
{
	int day;
	int month;
	int year;
};

/*
 * A structure to contain info about worker
 */
struct Worker
{
	string surname;
	string name;
	string patronymic;
	char gender;
	Birth birth_person;
};

/*
*Function to fill in the vector with workers data
*
* @param N numbers of workers that the user enters
* @return filled vector with workers data
*/
vector<Worker> fillWorkers(const int N);

/*
*Function to search for an worker by the full name entered by the user
*
* @param workers a vector with all workers data is transmitted
* @param surname surename of the worker to be found
* @param name name of the worker to be found
* @param patronymic patronymic of the worker to be found
* @return a new vector with the data of the worker who had to be found
*/
vector<Worker> searchWorker(
	const vector<Worker>& workers,
	string surname,
	string name,
	string patronymic
);

/*
*Function to find workers older or younger than the specified year
*
* @param workers a vector with all workers data is transmitted
* @param sl symbol < or >
* @param year the year from which you need to start the slice
* @return a new vector with the data of the workers who had to be found
*/
vector<Worker> sliceByYear(const vector<Worker>& workers, char sl, int year);

/*
*function to display worker statistics by gender
*
* @param workers a vector with all workers data is transmitted
*/
void genderStatistics(const vector<Worker>& workers);

/*
*function to compare two dates
*
* @param d1 a vector with the first date
* @param d2 a vector with the second date
* @param comp comparator > or <, that the user selected
* @return If comp '>': returns true if 1st date is more than 2d date and false otherwise. 
* If comp '<': returns true if 1st date is less than 2d date and false otherwise
*/
bool compDates(const Birth& d1, const Birth& d2, char comp);

/*
*function to sort workers by age
*
* @param workers a vector with all workers data is transmitted
* @param comp comparator > or <, that the user selected
*/
void sortWorkers(vector<Worker>& workers, char comp);

/*
*function to display the resulting vector on the console
*
* @param workers vector with the received data about workers
*/
void printWorkers(vector<Worker>& workers);

/*
*function for output of a string with an error
*
* @param string err string with an error
*/
void errors(const string err);

/*
*main function for declaring variables and calling functions, as well as the implementation of the switch
*
* @return returns 0 if the program completed successfully
*/
int main()
{
	srand(time(0));

	cout << "Enter the number of workers\n\
->";
	int N;
	string surn;
	string n;
	string patron;
	vector<Worker> found;
	char comp;
	int year;
	bool flag = true;
	cin >> N;
	if (cin.fail() || N < 0 || N > 100) {
		errors("Wrong number!");
		return 0;
	}
	vector<Worker> workers = fillWorkers(N);
	printWorkers(workers);

	while (flag) {
		cout << "Dear user, choose an action:\n \
1. Find a worker by full name.\n \
2. Find workers older or younger than the specified year.\n \
3. Display worker statistics by gender.\n \
4. Sort workers by age.\n \
5. Exit.\n \
-> ";
		int action;
		cin >> action;
		if (cin.fail()) {
			errors("Please, enter the number!");
		}
		switch (action)
		{
		case 1:
			cout << "Enter the full name of the worker: \n\
-> ";
			cin >> surn;
			cin >> n;
			cin >> patron;
			found = searchWorker(workers, surn, n, patron);
			printWorkers(found);
			break;
		case 2:
			cout << "Enter the comparator > or <:\n\
-> ";
			cin >> comp;
			if (comp != '>' && comp != '<') {
				errors("Wrong comparator!");
				continue;
			}
			cout << "Enter the year:\n\
-> ";
			cin >> year;
			if (cin.fail() || year <= 0 || year > 2022) {
				errors("Wrong year!");
			}
			if (comp == '>')
				cout << "Workers older than " << year << " year" << endl;
			else
				cout << "Workers younger than " << year << " year" << endl;
			found = sliceByYear(workers, comp, year);
			printWorkers(found);
			break;
		case 3:
			genderStatistics(workers);
			break;
		case 4:
			cout << "Enter the comparator > or <:\n\
-> ";
			cin >> comp;
			if (comp != '>' && comp != '<') {
				errors("Wrong comparator!");
				continue;
			}
			if (comp == '>')
				cout << "Sort in ascending order:" << endl;
			else
				cout << "Sort in descending order:" << endl;
			sortWorkers(workers, comp);
			printWorkers(workers);
			break;
		case 5:
			flag = false;
		default:
			cout << "You entered the wrong number!" << endl;
		}
	}
	cin.get();
	return 0;
}

vector<Worker> searchWorker(
	const vector<Worker>& workers,
	string surname,
	string name,
	string patronymic
)
{
	vector<Worker> found;
	for (const Worker& w : workers) {
		if (w.surname == surname && w.name == name && w.patronymic == patronymic) {
			found.push_back(w);
		}
	}
	if (found.empty()) {
		cout << "Worker not found!" << endl;
	}
	return found;
}

vector<Worker> fillWorkers(const int N)
{
	ifstream fem_name("name_fem.txt");
	ifstream fem_fam("fam_fem.txt");
	ifstream fem_otch("otch_fem.txt");
	ifstream male_name("name_male.txt");
	ifstream male_fam("fam_male.txt");
	ifstream male_otch("otch_male.txt");

	vector<Worker> workers(N);

	for (int i = 0; i < N; i++) {
		int a = rand() % 100;
		int b = rand() % 100;
		int c = rand() % 100;
		char g = (rand() % 2) ? 'm' : 'f';
		string surname;
		string name;
		string patronymic;
		Birth birth;
		Worker worker;
		if (g == 'm') {
			for (int i = 0; i < a; i++) male_fam >> surname;
			for (int i = 0; i < b; i++) male_name >> name;
			for (int i = 0; i < c; i++) male_otch >> patronymic;
			male_name.seekg(0);
			male_fam.seekg(0);
			male_otch.seekg(0);
		}
		else {
			for (int i = 0; i < a; i++) fem_fam >> surname;
			for (int i = 0; i < b; i++) fem_name >> name;
			for (int i = 0; i < c; i++) fem_otch >> patronymic;
			fem_name.seekg(0);
			fem_fam.seekg(0);
			fem_otch.seekg(0);
		}
		int year = 1947 + rand() % (2004 - 1947 + 1);
		int month = 1 + rand() % 12;
		int day = 0;
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			day = 1 + rand() % 30;
		}
		else if (month == 2) {
			day = 1 + rand() % 28;
		}
		else {
			day = 1 + rand() % 31;
		}

		birth.year = year;
		birth.month = month;
		birth.day = day;

		worker.surname = surname;
		worker.name = name;
		worker.patronymic = patronymic;
		worker.gender = g;
		worker.birth_person = birth;

		workers[i] = worker;
	}
	return workers;
}

vector<Worker> sliceByYear(const vector<Worker>& workers, char sl, int year)
{
	vector<Worker> found;
	for (const Worker& w : workers) {
		if (sl == '>') {
			if (w.birth_person.year > year) found.push_back(w);
		}
		else if (sl == '<') {
			if (w.birth_person.year < year) found.push_back(w);
		}
	}
	if (found.empty()) cout << "Not found this workers!";
	return found;
}

void genderStatistics(const vector<Worker>& workers)
{
	int stat_male = 0;
	int stat_female = 0;
	for (const Worker& w : workers) {
		if (w.gender == 'm')
			stat_male++;
		else
			stat_female++;
	}
	cout << "Number of men: " << stat_male << "\nNumber of women: " << stat_female << endl;
}

bool compDates(const Birth& d1, const Birth& d2, char comp) 
{
	switch (comp)
	{
	case '>':
		if (d1.year > d2.year) return true;
		if (d1.year != d2.year) return false;
		if (d1.month > d2.month) return true;
		if (d1.month != d2.month) return false;
		return (d1.day > d2.month);
	case '<':
		if (d1.year < d2.year) return true;
		if (d1.year != d2.year) return false;
		if (d1.month < d2.month) return true;
		if (d1.month != d2.month) return false;
		return (d1.day < d2.month);
	}
}

void sortWorkers(vector<Worker>& workers, char comp)
{
	for (int i = 0; i < workers.size(); i++) {
		for (int j = 0; j < workers.size() - 1; j++) {
			if (compDates(workers[j].birth_person, workers[j + 1].birth_person, comp)) {
				Worker w = workers[j];
				workers[j] = workers[j + 1];
				workers[j + 1] = w;
			}
		}
	}
}

void printWorkers(vector<Worker>& workers)
{
	cout << endl;
	for (Worker& w : workers) {
		cout << "............................" << endl;
		cout << "Full name: " << w.surname << " " << w.name << " " << w.patronymic << endl
			<< "Gender: " << w.gender << endl
			<< "Birth day: ";
		if (w.birth_person.day < 10) cout << "0" << w.birth_person.day << '.';
		else cout << w.birth_person.day << '.';
		if (w.birth_person.month < 10) cout << "0" << w.birth_person.month << '.';
		else cout << w.birth_person.month << '.';
		cout << w.birth_person.year << '\n' << endl;
	}
}

void errors(const string err)
{
	cout << "Error: " << err << endl;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}