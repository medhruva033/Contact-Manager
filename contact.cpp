#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    Contact contacts[100];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n===== CONTACT MANAGER =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // important

        if (choice == 1) {
            cout << "Enter Name: ";
            getline(cin, contacts[count].name);

            cout << "Enter Phone: ";
            getline(cin, contacts[count].phone);

            count++;
            cout << "✅ Contact Added Successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "⚠ No contacts found.\n";
            } else {
                cout << "\n--- Contact List ---\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". "
                         << contacts[i].name
                         << " - "
                         << contacts[i].phone << endl;
                }
            }
        }

        else if (choice == 3) {
            string searchName;
            cout << "Enter name to search: ";
            getline(cin, searchName);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (contacts[i].name == searchName) {
                    cout << "✅ Found: "
                         << contacts[i].name
                         << " - "
                         << contacts[i].phone << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "❌ Contact not found.\n";
            }
        }

        else if (choice == 4) {
            string deleteName;
            cout << "Enter name to delete: ";
            getline(cin, deleteName);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (contacts[i].name == deleteName) {
                    for (int j = i; j < count - 1; j++) {
                        contacts[j] = contacts[j + 1];
                    }
                    count--;
                    cout << "🗑 Contact deleted.\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Contact not found.\n";
            }
        }

        else if (choice == 5) {
            cout << "👋 Exiting...\n";
            break;
        }

        else {
            cout << "⚠ Invalid choice!\n";
        }
    }

    return 0;
}