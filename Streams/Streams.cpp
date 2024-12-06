#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Company {
public:
	string name;
	string owner;
	string phone_number;
	string address;
	string activity_type;

    Company(string n, string o, string p, string a, string act)
        : name(n), owner(o), phone_number(p), address(a), activity_type(act) {}

    void display() const {
        cout << "Company name: " << name << "\n"
            << "Owner: " << owner << "\n"
            << "Phone number: " << phone_number << "\n" 
            << "Adress: " << address << "\n"
            << "Type of activity: " << activity_type << "\n\n";
    }
};

class Directory {
private:
	vector<Company> companies;
	const string filename = "directory.txt";

	void load_from_file() {
        ifstream file(filename);
        if (file.is_open()) {
            std::string name, owner, phone, address, activity;
            while (getline(file, name) && getline(file, owner) &&
                getline(file, phone) && getline(file, address) &&
                getline(file, activity)) {
                companies.emplace_back(name, owner, phone, address, activity);
            }
            file.close();
        }
	}

	void save_to_file() {
        ofstream file(filename, std::ios::trunc);
        if (file.is_open()) {
            for (const auto& company : companies) {
                file << company.name << "\n"
                    << company.owner << "\n"
                    << company.phone_number << "\n"
                    << company.address << "\n"
                    << company.activity_type << "\n";
            }
            file.close();
        }
	}

public:
	Directory() {
		load_from_file();
	}

	~Directory() {
		save_to_file();
	}

	void add_company(const Company& company) {
		companies.push_back(company);
	}

	void display() const {
		for (const auto& company : companies) {
			company.display();
		}
	}

	void search_by_name(const string& name) const {
		for (const auto& company : companies) {
			if (company.name == name) {
				company.display();
				return;
			}
		}
		cout << "ERROR! Company not found\n";
	}

	void search_by_owner(const string& owner) const {
		for (const auto& company : companies) {
			if (company.owner == owner) {
				company.display();
				return;
			}
		}
		cout << "ERROR! Company not found\n";
	}

	void search_by_phone(const string& phone) const {
		for (const auto& company : companies) {
			if (company.phone_number == phone) {
				company.display();
				return;
			}
		}
		cout << "ERROR! Company not found\n";
	}

	void search_by_activity(const string& activity_type) const {
		for (const auto& company : companies) {
			if (company.activity_type == activity_type) {
				company.display();
				return;
			}
		}
		cout << "ERROR! Company not found\n";
	}
};

int main() {
    Directory directory;
    int choice;

    do {
        system("cls");
        cout << "Menu:\n"
            << "1. Add a company\n"
            << "2. Search by name\n"
            << "3. Search by owner\n"
            << "4. Search by phone\n"
            << "5. Search by activity type\n"
            << "6. Display all companies\n"
            << "7. Add sample companies\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name, owner, phone, address, activity;
            cout << "Enter company name: ";
            getline(cin, name);
            cout << "Enter owner name: ";
            getline(cin, owner);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter activity type: ";
            getline(cin, activity);
            directory.add_company(Company(name, owner, phone, address, activity));
            cout << "Company added successfully!\n";
            system("pause");
            break;
        }
        case 2: {
            string name;
            cout << "Enter company name: ";
            getline(cin, name);
            directory.search_by_name(name);
            system("pause");
            break;
        }
        case 3: {
            string owner;
            cout << "Enter owner name: ";
            getline(cin, owner);
            directory.search_by_owner(owner);
            system("pause");
            break;
        }
        case 4: {
            string phone;
            cout << "Enter phone number: ";
            getline(cin, phone);
            directory.search_by_phone(phone);
            system("pause");
            break;
        }
        case 5: {
            string activity;
            cout << "Enter activity type: ";
            getline(cin, activity);
            directory.search_by_activity(activity);
            system("pause");
            break;
        }
        case 6:
            directory.display();
            system("pause");
            break;
        case 7: {
            directory.add_company(Company("Company1", "Owner1", "123456789", "Address1", "Activity1"));
            directory.add_company(Company("Company2", "Owner2", "987654321", "Address2", "Activity2"));
            directory.add_company(Company("Company3", "Owner3", "123456789", "Address3", "Activity3"));
            directory.add_company(Company("Company4", "Owner4", "987654321", "Address4", "Activity4"));
            directory.add_company(Company("Company5", "Owner5", "123456789", "Address5", "Activity5"));
            cout << "Sample companies added successfully!\n";
            system("pause");
            break;
        }
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            system("pause");
        }
    } while (choice != 0);

    return 0;
}