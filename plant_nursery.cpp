#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<stdlib.h>
#include <map>
using namespace std;

class Product {
public:
    string name;
    int quantity;
    double price;
    Product(const string& n, int q, double p)
    {
        name = n;
        quantity = q;
        price = p;
    }
    virtual void display() = 0; 

    virtual double calculateTotalCost(int quantity) {
        return quantity * price;
    }

    virtual void deductQuantity(int quantity) {
        this->quantity -= quantity;
    }
};
class Plant : public Product {
public:

    Plant(const string& name, int quantity, double price) : Product(name, quantity, price) {}
   
    void display() {
        cout << "Plant Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
};

class Seed : public Product {

public:
    Seed(const string& name, int quantity, double price) : Product(name, quantity, price) {}
    
    void display() {
        cout << "Seed Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
};

class Fertilizer : public Product { 
public:
    Fertilizer(const string& name, int quantity, double price) : Product(name, quantity, price) {}

    void display() {
        cout << "Fertilizer Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
};


class NurseryManagementSystem {
    map<string, Product*> products; 
public:
    NurseryManagementSystem() 
    {
        products["Mango"] = new Plant("Mango", 1000, 100);
        products["Jackfruit"] = new Plant("Jackfruit", 200, 150);
        products["Lichi"] = new Plant("Lichi", 500, 250);
        products["WhiteRose"] = new Plant("WhiteRose", 150, 350);
        products["BlackRose"] = new Plant("BlackRose", 50, 520);
        products["YellowRose"] = new Plant("YellowRose", 200, 250);
        products["AloeVera"] = new Plant("AloeVera", 300, 50);
        products["Rosemary"] = new Plant("Rosemary", 250, 300);
        products["TomatoSeed"] = new Seed("Tomato Seed", 500, 30);
        products["CherryTomatoSeed"] = new Seed("Cherry Tomato Seed", 350, 100);
        products["Nitrogen"] = new Fertilizer("Nitrogen", 500, 550);
        products["Phosphorus"] = new Fertilizer("Phosphorus", 500, 550);
        products["Potassium"] = new Fertilizer("Potassium", 500, 600);
    }

    ~NurseryManagementSystem() {
        for (auto& pair : products) {
            delete pair.second;
        }
    }

    void displayProducts() {
        for (const auto& pair : products) {
            pair.second->display();
        }
    }

    Product* findProduct(const string& productName) {
        auto it = products.find(productName);
        if (it != products.end()) {
            return it->second;
        }
        return nullptr;
    }
    
    void addProduct(Product* product) {
        auto it = products.find(product->name);
        if (it != products.end()) {
            it->second->quantity += product->quantity;
            delete product;
        } else {
            products[product->name] = product;
        }
    }
};

class RegisterUser{
protected:
    string user;
private:
    string pass;
public:
    RegisterUser()
    {
        cout<<"Enter Username: \n";
        cin>>user;
        cout<<"\nEnter Password: \n";
        cin>>pass;
        ofstream reg("userdata.txt", ios::app);
        reg<<user<<' '<<pass<<endl;
        cout<<"Registration is successful\n";
    }
};

class LoginUser{
protected:
    string user;
    string u;
private:
    string pass;
    string p;
public:
    LoginUser()
    {
        int exist, c;
        cout<<"Enter Username: \n";
        cin>>user;
        cout<<"Enter Password: \n";
        cin>>pass;
        ifstream input("userdata.txt");

        while (input>>u>>p)
        {
            if (u == user && p == pass)
            {
                exist = 1;
            }
        }
        input.close();
        if (exist == 1)
        {
            cout<<"Hey "<<user<<"\nYou have successfully logged in\n";
        }
        else
        {
            cout<<"Sorry, user name or password incorrect"<<endl;
            cout<<"Press 1 to TRY AGAIN\n";
            cout<<"Press 2 for USER REGISTRATION"<<endl;
            cout<<"Press 3 for EXIT"<<endl;
            cin>>c;
            switch (c)
            {
                case 1:
                    {
                        LoginUser l1;
                        break;
                    }
                case 2:
                {
                    RegisterUser l2;
                    break;
                }
                case 3:
                {
                    cout<<"EXITING..."<<endl;
                    system("cls");
                    break;
                }
                default:
                {
                    cout<<"Choice is not valid\n";
                    system("cls");
                    break;
                }
            }


        }
    }
};

class AdminLogin{
protected:
    string admin;
    string a;
private:
    string pass;
    string p;
public:
    AdminLogin()
    {
        int exist, c;
        cout<<"Enter Admin ID: \n";
        cin>>admin;
        cout<<"Enter Password: \n";
        cin>>pass;
        ifstream input("admindata.txt");

        while (input>>a>>p)
        {
            if (a==admin && p == pass)
            {
                exist = 1;
            }
        }
        input.close();
        if (exist == 1)
        {
            cout<<"Hey admin, "<<admin<<"\nYou have successfully logged in\n";
        }
        else
        {
            cout<<"Hey, you are not the ADMIN!!!!"<<endl;
            cout<<"Press 1 to TRY AGAIN\n";
            cout<<"Press 2 for USER REGISTRATION"<<endl;
            cout<<"Press 0 to EXIT"<<endl;
            cin>>c;
            switch (c)
            {
                case 1:
                {
                    AdminLogin l1;
                    break;
                }
                case 2:
                {
                    RegisterUser l2;
                    break;;
                }
                case 0:
                {
                    cout<<"EXITING..."<<endl;
                    system("cls");
                    break;
                }
                default:
                {
                    cout<<"Choice is not valid\n";
                    system("cls");
                    break;

                }
            }
        }
    }
};


int main()
{  
    NurseryManagementSystem nursery;
    cout<<"**************************************** PLANT ABODE *****************************************"<<endl;
    cout<<"Choose what you want:"<<endl;
    cout<<"Press 1 for USER LOGIN"<<endl;
    cout<<"Press 2 for USER REGISTRATION"<<endl;
    cout<<"Press 3 for ADMIN LOGIN"<<endl;
    cout<<"Press 4 for VIEW PRODUCTS"<<endl;
    cout<<"Press 0 to EXIT"<<endl;

    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            LoginUser l;
            cout<<"Press 4 for Seeing Product"<<endl;
            int choice1;
            cin>>choice1;
            if (choice1 == 4)
            {
                cout << "\nAvailable Product Categories:\n";
                cout<<endl;
                cout<<endl;
                nursery.displayProducts();

                string productName;
                cout << "\nEnter the name of the product you want to purchase: ";
                cin >> productName;

                Product* product = nursery.findProduct(productName);
                if (product != nullptr) 
                {
                    int quantity;
                    cout << "Enter the quantity: ";
                    cin >> quantity;

                    if (quantity <= product->quantity) 
                    {
                        double totalCost = product->calculateTotalCost(quantity);
                        product->deductQuantity(quantity);
                        cout << "Purchase successful!\n";
                        cout << "Total Cost: " << totalCost << endl;
                        cout<<"Going back to homepage\n";
                        main();
                    } 
                    else 
                    {
                        cout << "Insufficient quantity available!\n";
                    }
                }

                else 
                {
                    cout << "Product not found!\n";
                }
            }
            else
            {
                cout<<"Going back to Home Page"<<endl;
                main();
            }
        }

        case 2:
        {
            RegisterUser r;
            system ("cls");
            cout<<endl<<endl<<endl<<endl<<endl<<endl;
            main();
        }
        case 3:
        {
            AdminLogin a;
            cout<<"Press 4 for Seeing Product"<<endl;
            int choice1;
            cin>>choice1;
            if (choice1 == 4)
            {
                cout<<"Available Products:\n";
                nursery.displayProducts();
                cout << "\nAvailable Product Categories:\n";
                cout << "1. Plants\n";
                cout << "2. Seeds\n";
                cout << "3. Fertilizers\n";
                cout <<"On which category do you want to add?\n";
                cout << "Choice: ";
                int productCategory;
                cin >> productCategory;

                string productName;
                int quantity;
                double price;

                cout << "\nEnter the name of the product: ";
                cin >> productName;
                cout << "Enter the quantity: ";
                cin >> quantity;
                cout << "Enter the price: ";
                cin >> price;

                Product* newProduct = nullptr;
                switch (productCategory) 
                {
                    case 1: 
                    {
                        newProduct = new Plant(productName, quantity, price);
                        break;
                    }
                    case 2: 
                    {
                        newProduct = new Seed(productName, quantity, price);
                        break;
                    }
                    case 3: 
                    {
                        newProduct = new Fertilizer(productName, quantity, price);
                        break;
                    }
                    default: 
                    {
                        cout << "\nInvalid choice!\n";
                        break;
                    }
                }

                if (newProduct != nullptr) {
                    nursery.addProduct(newProduct);
                    cout << "Product added successfully!\n";
                    cout <<"Updated Product list:\n";
                    nursery.displayProducts();
                }
            }
            else
            {
                cout<<"Going back to Home Page"<<endl;
                main();
            }
        }
        case 4:
        {
            cout << "\nAvailable Products:\n";
            nursery.displayProducts();
        }
        case 0:
        {
            cout<<"EXITING..."<<endl;
            system("cls");
            break;
        }
        default:
        {
            cout << "\nInvalid choice!\n";
        }
        return 0;
    }
}
