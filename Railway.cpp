#include<iostream>
using namespace std;

class Person {
	string Name;
	int Age;
	string Gender;

public:
	Person() {
		
		this->Name = "";
		this->Age = NULL;
		this->Gender = "" ;
	}
	Person(string n, int a, string g) {
		this->Name = n;
		this->Age = a;
		this->Gender = g;
	}
	void printPerson() {
		cout << "Name:" <<this->Name<< endl;
		cout << "Age:" << this->Age << endl;
		cout << "Gender:" << this->Gender << endl;
	
	}
	virtual void Print() {
		cout << " this function is never gonna call ;P ";
	}

	~Person() {
		this->Age = NULL;
		this->Gender = "";
		this->Name = "";

	}
	
};
class Adult :public Person {
	string Occupation;
	string Qualification;
	string NIC;
public:
	Adult() {
		this->NIC = "";
		this->Occupation = "";
		this->Qualification = "";
	}
	Adult(string n, int a, string g, string nic, string occ, string qua) : Person(n,a,g) {
		this->NIC = nic;
		this->Occupation = occ;
		this->Qualification = qua;
	}
	void Print() {
		printPerson();
		cout << "NIC:" << this->NIC << endl;
		cout << "Occupation:" << this->Occupation << endl;
		cout << "Qualification:" << this->Qualification << endl;
	}
	~Adult() {
		this->NIC="";
		this->Occupation = "";
		this->Qualification = "";
	
	}
};
class kid :public Person {
	string B_form_number;
public:
	kid() {
		this->B_form_number = "";
	}
	kid(string n, int a, string g, string bf) :Person(n,a,g) {
		this->B_form_number = bf;
	}
	void Print() {
		
		printPerson();
		cout << "B-form-Number :" << this->B_form_number << endl;
	}
	~kid() {
		this->B_form_number ="" ;
	}
};
class Bogie {
	Bogie *NEW[50];
	int Bogie_ID;
	Bogie* next;
	Person** Adults;
	Person** kids;
	string familyName;
	int Ad;//count of Adults
	int Kd;//count of kids
	int total = 0;   ///this increse when bogie is added and decrease when bogie is removed//
public:
	
	Bogie() {
		this->Bogie_ID = NULL;
		this->next = NULL;
		this->Ad = NULL;
		this->Adults = NULL;
		this->kids = NULL;
		this->Kd = NULL;
		this->familyName = "";
	}
	Bogie(int id) {
		
	
		this->Bogie_ID = id;
		this->next = NULL;
		this->Ad = NULL;
		this->Adults = NULL;
		this->kids = NULL;
		this->Kd = NULL;
		this->familyName = "";
	};
	
	void AddPassengers() {
		cout << "Enter The Name of Family:" << endl;
		cin >> this->familyName;
		
		
			int b=6;
			while (b > 4 || b < 0) {
				cout << "How many Adults are there : MAX 4" << endl;
				cin >> b;
			}
				
		
			this->Ad = b;
			Adults = new Person * [b];
			for (int i = 0 ; i < b; i++)
			{
				cout << " ::Information For Adult " << i + 1 << " ::" << endl;
				cout << " Enter Name :";
				string n;
				cin >> n;
				cout << " Enter Age :";
				int a;
				cin >> a;
				cout << " Enter Gender :";
				string g;
				cin >> g;
				cout << " Enter NIC :";
				string nic;
				cin >> nic;
				cout << " Enter Occupation :";
				string O;
				cin >> O;
				cout << " Enter Qualification :";
				string q;
				cin >> q;
				Adults[i] = new Adult(n,a,g,nic,O,q);
			}
			
		
			b = 7;
			while (b > 6 || b < 0) {
				cout << "How many Kids are there : MAX 6" << endl;
				cin >> b;

			}
			this->Kd = b;
			kids = new Person * [b];
			for (int i = 0; i < b; i++)
			{
				cout << " ::Information For KId " << i + 1 << " ::" << endl;
				cout << " Enter Name :";
				string n;
				cin >> n;
				cout << " Enter Age :";
				int a;
				cin >> a;
				cout << " Enter Gender :";
				string g;
				cin >> g;
				cout << " Enter B-form Number :";
				string nic;
				cin >> nic;
				
				kids[i] = new kid(n, a, g, nic);
			}
		
	
	}; // should add adults and kids information etc
	void Print(int i) {
		
		
			cout << " ::Information For Bogie" <<i+1<< " :" << endl;
			cout << " Bogie Id :" << this->Bogie_ID;
			cout << endl;
			cout << "BOOKED BY FAMILY :" << this->familyName << endl;
			if (this->Ad != 0) {
				cout << "Information About Adults" << endl;
			}
			for (int i = 0; i < this->Ad; i++) {
				cout << i + 1 << " :" << endl;
				this->Adults[i]->Print();
				cout << endl;
			}
			if (this->Kd != 0) {
				cout << "Information About Kids" << endl;
			}
			for (int i = 0; i < this->Kd; i++) {
				cout << i + 1 << " :" << endl;
				this->kids[i]->Print();
				cout << endl;
			}
		
	};
	void Add(int i) {
		
		
		NEW[total] = new Bogie(i);
		NEW[total]->AddPassengers();
		
		if (total != 0) {
		NEW[total-1]->next= NEW[total];
		
		}
		else {
			this->next = NEW[0];
		}
		total++;
		

	}
	void PrintB() {
		system("CLS");
		cout <<endl<< "Engine ID:" << this->Bogie_ID<<endl;
		if (total == 0) {
			cout << endl<< " :: No Bogie attached with this Engine ::" << endl;
		}
		for (int i = 0; i < total; i++)
		{
	
			NEW[i]->Print(i);
			//cout << NEW[i]->next;
			cout << endl;
		}
	}
	void PrintID() {
		for (int i = 0; i < total; i++)
		{
			cout << i + 1<<" : ";
			cout<< NEW[i]->Bogie_ID;
			cout << endl;
		}
	} ///only prints the ID's of all added bogies//
	void SET(int j) {
		if (j > 1) {
			for (int i = j; i < total; i++)
			{
				NEW[i] = NEW[i + 1];
				NEW[i - 1]->next = NEW[i];
				//this will update next of every bogie and remove 1 bogie .
			}
			total--;
		}
		else {
			this->next = NEW[1];
			NEW[0] = NEW[1];
			for (int i = 1; i < total; i++)
			{
				NEW[i] = NEW[i + 1];
				NEW[i - 1]->next = NEW[i];

			}
			total--;

		}
	
	}//removes the specific Bogie from the train
	bool Remove(int id) {
		for (int i = 0; i <total; i++)
		{
			if (NEW[i]->Bogie_ID == id) //match the bogie id
			{
				SET(i);//set function is called
				return true;
			}
			
		}
		return false;


	}/*this function matches the bogie id matched from
	 added bogie list and send the required bogie to set function*/
	bool Repition(int id) {
		bool a=true;
		for (int i = 0; i < total; i++) {
			if (NEW[i]->Bogie_ID == id) {
				a = false;
				
			}

		}
		
		return a;
		
	} /*this function checks the id form the past 
	  bogies weather the new id assigined is repeater or not*/
	bool search(int id) {
		for (int i = 0; i < total; i++)
		{
			if (NEW[i]->Bogie_ID == id)
			{
				cout << "Bogie with  ID :" << id << " found successfully" << endl;
				NEW[i]->Print(i);
				return true;
			}

		}
		cout << "Bogie with  ID :" << id << " is not found " << endl;
		return false;

	}
	~Bogie() {
		this->Bogie_ID = NULL;
		this->next = NULL;
		delete[] next;
		this->next = nullptr;

		this->Ad = NULL;
		this->Adults = NULL;
		delete[] this->Adults;
		this->Adults = nullptr;
		this->kids = NULL;
		delete[] this->kids;
		this->kids = nullptr;
		this->Kd = NULL;
		this->familyName = "";
		for (int i = 0; i < total; i++) {
			NEW[i] = NULL;
			delete[] NEW[i];
			NEW[i] = nullptr;
		}
	};
};
class train {
	Bogie* engine;
	
public:
	
	train() {
		engine = nullptr;
	}
	train(int id) {
		engine = new Bogie(id);
		int yes = 0;
		while (yes == 0) {
			system("color f1");
			system("CLS");
			
			cout << "PRESS A to ADD A BOGIE:" << endl;
			cout << "PRESS R to REMOVE A BOGIE:" << endl;
			cout << "PRESS S to SEARCH A BOGIE:" << endl;
			cout << "PRESS P to PRINT THE TRAIN:" << endl;

			cout << endl << endl << endl << endl;
			cout << "Press E to Exit[ ::The information will be lost once you Exit ::]";
			cout << endl << endl << endl << endl;
			char check;
			cin >> check;
			if (check == 'E' || check == 'e') {
				system("color 01");
				system("CLS");
				cout << endl << endl << endl << endl;

			
				cout << "                                             :: GOOD BYE ::";
				cout << endl << endl << endl << endl;
				yes = 1;
			
			
			}

			if (check == 'A' || check == 'a') {
				
				
					system("CLS");
					system("color 2f");
					cout << " To add a bogie assign an id :" << endl;
					int ID;
					cin >> ID;
					bool a = false;
					while (a == false) {
						a = engine->Repition(ID);
						if (a == false) {
							cout << endl << "///this ID is already added///" << endl;
							cout << "Please Enter a Unique ID :: " << endl;
							cin >> ID;
							a = engine->Repition(ID);
						}
					}
					addBogie(ID);

					
				
			}
			if (check == 'R' || check == 'r') {
				system("CLS");
				system("color 3f");
				bool f = false;
				while (f == false) {
					cout << "Enter Id of bogie to remove :" << endl;
					int i;
					cin >> i;
					f = removeBogie(i);
					if (f == false) {
						cout << "::No Bogie with such ID::" << endl;
					}
					else {
						cout << " :: Bogie with ID:" << i << " is successfully Removed ::" << endl;
					}

				}
				cout << endl << endl << " :: Press any key  and ENTER  to Continue :: " << endl;
				char m;
				cin >> m;
				
			}
			if (check == 'S' || check == 's') {
				system("CLS");
				system("color 4f");
				bool v = false;
				while (v == false)
				{
					cout << "Enter the ID to search:" << endl;
					int i;
					cin >> i;
					v = SearchBogie(i);
					if (v == false) {
						cout << endl << " Please try again:" << endl;
					}
				}
				cout << endl << endl << " :: Press any key  and ENTER  to Continue :: " << endl;
				char m;
				cin >> m;
				
			}
			if (check == 'P' || check == 'p') {
				system("CLS");
				system("color 5f");
				printTrain();
				cout <<endl<<endl<< " :: Press any key  and ENTER  to Continue :: " << endl;
				char m;
				cin >> m;
				
			}
		}
	}
	void addBogie(int Id) {
		
		engine->Add(Id);
	}; //add bogie at the end of the train
	bool removeBogie(int ID) {
	 	bool x = engine->Remove(ID);
		return x;
	}; //search the bogie and delete it
	void printTrain() {
		
		cout << " What do you Want to Print?" << endl;
		cout << " 1 : Bogies ID's" << endl;
		cout << " 2 : Complete Train " << endl;
		char a;
		cin >> a;
		if (a == '1'){
			engine->PrintID();
		}
		
		else if (a == '2') {
			engine->PrintB();
		}
		}; //print only the Bogie_ID of all bogies
	bool SearchBogie(int ID) {
		bool v;
		v = engine->search(ID);
		return v;
	
	};//search the particular bogie
	~train() {
		engine = NULL;
		delete[] engine;
		engine = nullptr;
	};
};
void main() {
	system("color f1");
	cout << endl << endl << endl << endl;
	cout << "					::WELLCOME TO TRAIN SYSTEM::" << endl;
	cout << "											::Created by Gohar Butt:: ";
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
	cout << " ::Starting the system Firstly::" << endl;
    cout << "Enter ID of Engine:" << endl;
	int id;
	cin >> id;
	train a(id);
}