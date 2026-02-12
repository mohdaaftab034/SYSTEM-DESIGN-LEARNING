#include<iostream>
#include<vector>

using namespace std;

// Product class is representing any items in eCommerce system
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
            total+= p->price; // Accessing price through getter, maintains encapsulation
        }
        return total;
    }
};

class ShoppingCartPrinter {
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this-> cart = cart;
    }

    void printInvoice() {
        cout << "Invoice:" << endl;
        for(auto p : cart->getProducts()) {
            cout << p->name << ": $" << p->price << endl; // Accessing name and price through getters
        }
        cout << "Total: $" << cart->calculateTotal() << endl; // Using ShoppingCart's method to calculate total
    }

};

class ShoppingCartStorage {
    private:
    ShoppingCart* cart;

    public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this-> cart = cart;
    }

    void saveToDatabase() {
        // Code to save the shopping cart to a database
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart(); // Create a shopping cart

    cart->addProduct(new Product("Laptop", 999.99)); // Add products to the cart
    cart->addProduct(new Product("Mouse", 25.50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart); // Create a printer for the cart
    printer->printInvoice(); // Print the invoice

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart); // Create a storage for the cart
    storage->saveToDatabase(); // Save the cart to the database

    return 0;
}