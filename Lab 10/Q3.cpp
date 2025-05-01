#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class User {
public:
    string user_id, first_name, last_name, address, email;

    User(string id, string fn, string ln, string addr, string em)
        : user_id(id), first_name(fn), last_name(ln), address(addr), email(em) {}

    string toLine() const {
        return user_id + "," + first_name + "," + last_name + "," + address + "," + email;
    }

    static User fromLine(const string& line) {
        stringstream ss(line);
        string id, fn, ln, addr, em;
        getline(ss, id, ',');
        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, addr, ',');
        getline(ss, em, ',');
        return User(id, fn, ln, addr, em);
    }
};

class Product {
public:
    string product_id, product_name, description;
    int price;

    Product(string id, string name, string desc, int pr)
        : product_id(id), product_name(name), description(desc), price(pr) {}

    string toLine() const {
        return product_id + "," + product_name + "," + description + "," + to_string(price);
    }

    static Product fromLine(const string& line) {
        stringstream ss(line);
        string id, name, desc, priceStr;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, priceStr, ',');
        return Product(id, name, desc, stoi(priceStr));
    }
};

class Order {
public:
    string order_id, user_id, product_id;
    int total_paid;

    Order(string oid, string uid, string pid, int paid)
        : order_id(oid), user_id(uid), product_id(pid), total_paid(paid) {}

    string toLine() const {
        return order_id + "," + user_id + "," + product_id + "," + to_string(total_paid);
    }

    static Order fromLine(const string& line) {
        stringstream ss(line);
        string oid, uid, pid, paidStr;
        getline(ss, oid, ',');
        getline(ss, uid, ',');
        getline(ss, pid, ',');
        getline(ss, paidStr, ',');
        return Order(oid, uid, pid, stoi(paidStr));
    }
};

void populateFiles() {
    ofstream userFile("users.txt");
    userFile << User("U10", "Marie", "Curie", "Paris", "marie@science.com").toLine() << endl;
    userFile << User("U11", "Nikola", "Tesla", "Belgrade", "nikola@electricity.com").toLine() << endl;
    userFile.close();

    ofstream productFile("products.txt");
    productFile << Product("P10", "Physics Book", "Quantum theory explained", 600).toLine() << endl;
    productFile << Product("P11", "Electric Kit", "Build your own motor", 750).toLine() << endl;
    productFile.close();

    ofstream orderFile("orders.txt");
    orderFile << Order("O10", "U10", "P10", 600).toLine() << endl;
    orderFile << Order("O11", "U11", "P11", 750).toLine() << endl;
    orderFile.close();
}

vector<User> getUsers() {
    vector<User> list;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        list.push_back(User::fromLine(line));
    }
    return list;
}

vector<Product> getProducts() {
    vector<Product> list;
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        list.push_back(Product::fromLine(line));
    }
    return list;
}

vector<Order> getOrders() {
    vector<Order> list;
    ifstream file("orders.txt");
    string line;
    while (getline(file, line)) {
        list.push_back(Order::fromLine(line));
    }
    return list;
}

void displayProductsByUser(const string& fname) {
    vector<User> users = getUsers();
    vector<Product> products = getProducts();
    vector<Order> orders = getOrders();

    string target_id = "";
    for (const auto& user : users) {
        if (user.first_name == fname) {
            target_id = user.user_id;
            break;
        }
    }

    if (target_id.empty()) {
        cout << "No user with that name found.\n";
        return;
    }

    cout << fname << " bought:\n";
    for (const auto& order : orders) {
        if (order.user_id == target_id) {
            for (const auto& product : products) {
                if (product.product_id == order.product_id) {
                    cout << "- " << product.product_name << endl;
                }
            }
        }
    }
}

int main() {
    populateFiles();
    string searchName;
    cout << "Enter user's first name to search: ";
    getline(cin, searchName);
    displayProductsByUser(searchName);
    return 0;
}

