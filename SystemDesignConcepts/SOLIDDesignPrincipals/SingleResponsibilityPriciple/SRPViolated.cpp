#include<iostream>
#include<vector>

using namespace std;


class Product {
    public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
    private:
    vector<Product*> products; // Store heap allocated products

    public:
    void addProduct(Product* p) {
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    double calculateTotal() {
        double total = 0;

        for(auto p : products) {
            total+= p->price; // Accessing price directly, violates encapsulation
        }
        return total;
    }

    void printInvoice() {
        cout << "Invoice:" << endl;
        for(auto p : products) {
            cout << p->name << ": $" << p->price << endl; // Accessing name and price directly, violates encapsulation
        }
        cout << "Total: $" << calculateTotal() << endl; // Using ShoppingCart's method to calculate total
    }

    void saveToDatabase() {
        // Code to save cart details to database
        // This method is not implemented, but it would violate the Single Responsibility Principle if added here
    }
};


int main() {

    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Mouse", 25.50));
    cart->printInvoice();
    cart->saveToDatabase(); // This method is not implemented, but it would violate the Single Responsibility Principle if added here

    return 0;
}