#include <iostream>
#include <vector>
using namespace std;

struct Person {
    int id;
    string name;
};

void sortByID(vector<Person>& person) {
    int size = person.size(); 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (person[j].id > person[j + 1].id) {
                Person temp = person[j];
                person[j] = person[j + 1];
                person[j + 1] = temp;
            }
        }
    }
}

void sortByName(vector<Person>& person) {
    int size = person.size(); 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (person[j].name[0] > person[j + 1].name[0]) {
                Person temp = person[j];
                person[j] = person[j + 1];
                person[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int N = stoi(argv[1]);

    if (argc != (2 + 2 * N)) {
        cout << "MISSING DATA!! Make sure that number of people, and both name and id are entered for each person!!";
        return 1;
    }

    vector<Person> People;

    for (int i = 0; i < N; i++) {
        Person details;
        details.id = stoi(argv[2 + 2 * i]); 
        details.name = argv[2 + 2 * i + 1]; 
        People.push_back(details); 
    }
    
    cout << "Before Sorting:" << endl;
    for (const auto& details : People) {
        cout << "ID: " << details.id << ", Name: " << details.name << endl;
    }
    
    sortByID(People);
    cout << "Sorted by ID:" << endl;
    for (const auto& details : People) {
        cout << "ID: " << details.id << ", Name: " << details.name << endl;
    }

    sortByName(People);
    cout << "\nSorted By First Character of The Name:" << endl;
    for (const auto& details : People) {
        cout << "ID: " << details.id << ", Name: " << details.name << endl;
    }

    return 0;
}

