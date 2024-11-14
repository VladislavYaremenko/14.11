#include <iostream>
using namespace std;

struct Product {
    char name[30]; 
    int  unsigned quantity;
    double price;
};

//створення товару
Product createProduct(const char* name, int quantity, double price) 
{
    Product product;
    int i = 0;
    while (name[i] != '\0' && i < 49) {
        product.name[i] = name[i];
        i++;
    }
    product.name[i] = '\0';
    product.quantity = quantity;
    product.price = price;
    return product;
}





//сортування товару
void sortProductsByPrice(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (products[i].price > products[j].price) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

//пошук товару за кількістю
void findProductsByQuantity(const Product products[], int count, int quantity) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (products[i].quantity == quantity) {
            cout << "Name: " << products[i].name << ", Quantity: "<< products[i].quantity << ", Price: " << products[i].price << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Products with quantity " << quantity << " not found" << endl;
    }
}

//Вивід товарів
void printProduct(const Product& product) {
    cout << "Name: " << product.name << ", Quantity: "
        << product.quantity << ", Price: " << product.price << endl;
}

int main()
{
    const int SIZE = 3;
    Product products[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        char name[30];
        int quantity;
        double price;
        cout << "Enter name of product " << i + 1 << ": ";
        cin >> name;
        cout << "Enter quantity of product " << i + 1 << ": ";
        cin >> quantity;
        cout << "Enter price of product " << i + 1 << ": ";
        cin >> price;
        products[i] = createProduct(name, quantity, price);
    }

    sortProductsByPrice(products, SIZE);
    cout << "List of products after sorting by price: " << endl;
    for (int i = 0; i < SIZE; i++) {
        printProduct(products[i]);
    }

    int quantity;
    cout << "enter the quantity of the product to search: ";
    cin >> quantity;
    std::cout << "\nSearch for products with quantity " << quantity <<":" << endl;
    findProductsByQuantity(products, SIZE, quantity);

    return 0;

}