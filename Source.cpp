#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int size = 0;
struct person
{
	string stName;
	string ndname;
	int id;
	string homeAdd;
	string officeAdd;
	string city;
	string phonenum;
	string company;
	string cellnum;
};

person *regrow(person *oldCollection, int growBy){

	int oldSize = size;
	int newSize = oldSize + growBy;

	person* newCollection = new person[newSize];

	//Copying oldCollection data into newCollection
	for (int i = 0; i<oldSize; i++)
	{
		newCollection[i].cellnum = oldCollection[i].cellnum;
		newCollection[i].city = oldCollection[i].city;
		newCollection[i].company = oldCollection[i].company;
		newCollection[i].homeAdd = oldCollection[i].homeAdd;
		newCollection[i].id = oldCollection[i].id;
		newCollection[i].ndname = oldCollection[i].ndname;
		newCollection[i].officeAdd = oldCollection[i].officeAdd;
		newCollection[i].phonenum = oldCollection[i].phonenum;
		newCollection[i].stName = oldCollection[i].stName;
	}

	//Delete oldCollection if its not null i.e. oldCollection's size is not zero
	if (oldCollection != NULL){
		delete []oldCollection;
	}

	size = newSize;
	return newCollection;
}

person *regrowByOne(person *oldCollection)
{
	return regrow(oldCollection, 1);
}

char mainMenu(char option)
{
	cout << "************************* CONTACT LIST ************************** \n";
	cout << "************************* Main Menu *************************\n";
	cout << "*******************************************************************\n";

	cout << "R – Read contact list from file contact\n";
	cout << "F - Find a contact by any field\n";
	cout << "W - Write contact list to file.\n";
	cout << "S – Sort contact list\n";
	cout << "With respect to all the fields (give their options).\n";
	cout << "A – Add a single contact\n";
	cout << "D – Delete a contact\n";
	cout << "M – Modify a contact\n";
	cout << "I – Input a contact from keyboard\n";
	cout << "O – Output a contact to the screen\n";
	cout << "Q- Quit Contact List program\n";
	cout << "P- Print Complete Contact List\n";
	cout << "******************************************************************\n";
	cout << "Please select one of the menu options by typing the given character and hitting\n";
	cout << "the “Enter” key\n";
	cin >> option;
	return option;
}
person *readfile(ifstream &fin, person *p)
{
	while (1)
	{
		if (fin.eof())
		{
			break;
		}
		else
		{
			p = regrowByOne(p);
			string temp;

			getline(fin, temp);
			p[size-1].id = stoi(temp);
			getline(fin, p[size-1].stName);
			getline(fin, p[size-1].ndname);
			getline(fin,p[size-1].homeAdd);
			getline(fin, p[size - 1].officeAdd);
			getline(fin, p[size - 1].city);
			getline(fin, p[size - 1].phonenum);
			getline(fin, p[size - 1].cellnum);
			getline(fin, p[size - 1].company);
		}
	}
	return p;
}
void print(person *p)
{
	for (int i = 0; i<size; i++)
	{
		cout << "id= " << p[i].id << endl;
		cout << "first Name= " << p[i].stName << endl;
		cout << "Secound Name= " << p[i].ndname << endl;
		cout << "Home Address= " << p[i].homeAdd << endl;
		cout << "Office Address= " << p[i].officeAdd << endl;
		cout << "city= " << p[i].city << endl;
		cout << "phone Number=(042) " << p[i].phonenum << endl;
		cout << "Cell Number=" << p[i].cellnum << endl;
		cout << "Company= " << p[i].company << endl;
	}
}
void find(person *p, int opt)
{
	if (opt == 1)
	{
		int findID = 0;
		cout << "Enter Id you want to find\n";
		cin >> findID;
		cout << "id= " << p[findID].id << endl;
		cout << "first Name= " << p[findID].stName << endl;
		cout << "Secound Name= " << p[findID].ndname << endl;
		cout << "Home Address= " << p[findID].homeAdd << endl;
		cout << "Office Address= " << p[findID].officeAdd << endl;
		cout << "city= " << p[findID].city << endl;
		cout << "phone Number=(042) " << p[findID].phonenum << endl;
		cout << "Cell Number=" << p[findID].cellnum << endl;
		cout << "Company= " << p[findID].company << endl;
	}
	else if (opt == 2)
	{
		string findd;
		cout << "Enter First name \n";
		cin >> findd;
		for (int i = 0; i>size; i++)
		{
			if (p[i].stName == findd)
			{
				cout << "id= " << p[i].id << endl;
				cout << "first Name= " << p[i].stName << endl;
				cout << "Secound Name= " << p[i].ndname << endl;
				cout << "Home Address= " << p[i].homeAdd << endl;
				cout << "Office Address= " << p[i].officeAdd << endl;
				cout << "city= " << p[i].city << endl;
				cout << "phone Number=(042) " << p[i].phonenum << endl;
				cout << "Cell Number=" << p[i].cellnum << endl;
				cout << "Company= " << p[i].company << endl;
			}
		}
	}
	else if (opt == 3)
	{
		string finddd;
		cout << "Enter Secound name \n";
		cin >> finddd;
		for (int i = 0; i>size; i++)
		{
			if (p[i].stName == finddd)
			{
				cout << "id= " << p[i].id << endl;
				cout << "first Name= " << p[i].stName << endl;
				cout << "Secound Name= " << p[i].ndname << endl;
				cout << "Home Address= " << p[i].homeAdd << endl;
				cout << "Office Address= " << p[i].officeAdd << endl;
				cout << "city= " << p[i].city << endl;
				cout << "phone Number=(042) " << p[i].phonenum << endl;
				cout << "Cell Number=" << p[i].cellnum << endl;
				cout << "Company= " << p[i].company << endl;
			}
		}
	}
}
void writeFile(person *p)
{
	ofstream fout("contact.txt");
	for (int i = 0; i<size; i++)
	{
		fout <<p[i].id << endl;
		fout <<p[i].stName << endl;
		fout <<p[i].ndname << endl;
		fout <<p[i].homeAdd << endl;
		fout <<p[i].officeAdd << endl;
		fout <<p[i].city << endl;
		fout <<p[i].phonenum << endl;
		fout <<p[i].cellnum << endl;
		if (i == size - 1){
			fout << p[i].company;
		}
		else{
			fout << p[i].company << endl;
		}
	}
	fout.close();
}
void output(person *p, int i)
{
	cout << "id= " << p[i].id << endl;
	cout << "first Name= " << p[i].stName << endl;
	cout << "Secound Name= " << p[i].ndname << endl;
	cout << "Home Address= " << p[i].homeAdd << endl;
	cout << "Office Address= " << p[i].officeAdd << endl;
	cout << "city= " << p[i].city << endl;
	cout << "phone Number=(042) " << p[i].phonenum << endl;
	cout << "Cell Number=" << p[i].cellnum << endl;
	cout << "Company= " << p[i].company << endl;
}
person* addAContact(person *p)
{
	p = regrowByOne(p);
	int i = size - 1;
	cout << "Enter id \n";
	cin >> p[i].id;
	cout << "Enter First Name \n";
	cin.ignore();
	cin >> p[i].stName;
	cout << "Enter Secound name \n";
	cin >> p[i].ndname;
	cout << "Enter Home Address \n";
	cin >> p[i].homeAdd;
	cout << "Enter Office Address \n";
	cin >> p[i].officeAdd;
	cout << "Enter city\n";
	cin >> p[i].city;
	cout << "Enter Phone Number \n";
	cin.ignore();
	cin >> p[i].phonenum;
	cout << "Enter Cell Number\n";
	cin >> p[i].cellnum;
	cin.ignore();
	cout << "Enter mobile company\n";
	cin >> p[i].company;
	return p;
}
person *deleteAContact(person *p, int delID)
{
	int index = 0;

	for (int i = delID; i<size-1; i++)
	{
		p[i].cellnum = p[i + 1].cellnum;
		p[i].city = p[i + 1].city;
		p[i].company = p[i + 1].company;
		p[i].homeAdd = p[i + 1].homeAdd;
		p[i].id = p[i + 1].id;
		p[i].ndname = p[i + 1].ndname;
		p[i].officeAdd = p[i + 1].officeAdd;
		p[i].phonenum = p[i + 1].phonenum;
		p[i].stName = p[i+1].stName;
	}
	size--;
	person *temp = new person[size];
	for (int i = delID; i<size; i++)
	{
		temp[i].cellnum = p[i].cellnum;
		temp[i].city = p[i].city;
		temp[i].company = p[i].company;
		temp[i].homeAdd = p[i].homeAdd;
		temp[i].id = p[i].id;
		temp[i].ndname = p[i].ndname;
		temp[i].officeAdd = p[i].officeAdd;
		temp[i].phonenum = p[i].phonenum;
		temp[i].stName = p[i].stName;
	}
	delete p;
	return temp;
}
void sorting(person *p, int optt)
{
	if (optt == 1)
	{
		for (int i = size; i > size; i--)
		{
			cout << "id= " << p[i].id << endl;
			cout << "first Name= " << p[i].stName << endl;
			cout << "Secound Name= " << p[i].ndname << endl;
			cout << "Home Address= " << p[i].homeAdd << endl;
			cout << "Office Address= " << p[i].officeAdd << endl;
			cout << "city= " << p[i].city << endl;
			cout << "phone Number=(042) " << p[i].phonenum << endl;
			cout << "Cell Number=" << p[i].cellnum << endl;
			cout << "Company= " << p[i].company << endl;
		}
	}
	else if (opt == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (strcmp(p[i].stName, p[j].stName))
				{
					swap(p[i].id, p[j].id);
					swap(p[i].stName, p[j].stName);
					swap(p[i].ndName, p[j].ndName);
					swap(p[i].homeAdd, p[j].homeAdd);
					swap(p[i].officeAdd, p[j].officeAdd);
					swap(p[i].city, p[j].city);
					swap(p[i].phonenum, p[j].phonenum);
					swap(p[i].cellnum, p[j].cellnum);
					swap(p[i].company, p[j].company);
				}
			}
		}
	}
}
person *modify(person *p, int id, int opt)
{
	if (opt == 1)
	{
		cout << "Enter First Name";
		cin >> p[id].stName;
		return p;
	}
	else if (opt == 2)
	{
		cout << "Enter Secund Number";
		cin >> p[id].ndname;
		return p;
	}
	else if (opt == 3)
	{
		cout << "Enter home address";
		cin >> p[id].homeAdd;
		return p;
	}
	else if (opt == 4)
	{
		cout << "Enter city";
		cin >> p[id].city;
		return p;
	}
	else if (opt == 5)
	{
		cout << "Enter Office Address";
		cin >> p[id].officeAdd;
		return p;
	}
}
int main()
{
	char option = '\n';
	person *p = NULL;
	ifstream fin;
	fin.open("contact.txt");
	for (; option != 'Q' || option != 'q';)
	{
		option = mainMenu(option);
		if (option == 'R' || option == 'r')
		{
			p = readfile(fin, p);
		}
		else if (option == 'P' || option == 'p')
		{
			print(p);
		}
		else if (option == 'F' || option == 'f')
		{
			int opt;
			cout << "to find with id press 1\n";
			cout << "to find with first name press 2\n";
			cout << "to find with Second name press 3\n";
			cin >> opt;
			find(p, opt);
		}
		else if (option == 'W' || option == 'w')
		{
			writeFile(p);
		}
		else if (option == 'O' || option == 'o')
		{
			int serchID;
			cout << "Enter contact ID you want to see\n";
			cin >> serchID;
			output(p, serchID);
		}
		else if (option == 'A' || option == 'a')
		{
			cout << "Enter the info of a contact \n";
			p = addAContact(p);
		}
		else if (option == 'D' || option == 'd')
		{
			int delID;
			cout << "Enter the contact id which you want to delete \n";
			cin >> delID;
			p = deleteAContact(p, delID);
		}
		else if (option == 'S' || option == 's')
		{
			int optt;
			cout << "If you want to sort by ID press 1 \n";
			cout << "If you want to sort by names press 2\n";
			cin >> optt;
			sorting(p,optt);
		}
		else if (option == 'M' || option == 'm')
		{
			int id,opt;
			cout << "Enter contact ID which you want to Modify \n";
			cin >> id;
			cout << "if you want to change First Name press 1 \nif you want to change Secound Name press 2 /nif you want to change Home Address press 3 \nif you want to change city press 4 \nif you want to change Office Address press 5 \n";
			cin >> opt;
			p = modify(p, id, opt);
		}
		else if (option == 'Q' || option == 'q')
		{
			break;
		}
	}
	fin.close();
	return 0;
}