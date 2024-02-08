#include <iostream> 
#include <string>
#include <conio.h>

struct Products{
    std::string name;
    double price;
    int quantity;    

    friend std::istream& operator >> (std::istream &is, Products &_product){    
        std::cout << "Enter name: ";
        is.ignore();
        getline(is, _product.name);
        std::cout << "Enter price: ";
        is >> _product.price;
        std::cout << "Enter quantity: ";
        is >> _product.quantity;

        return is;
    }

    friend std::ostream& operator << (std::ostream &os, Products _product){
        os << "Name: " << _product.name << std::endl;
        os << "Price: " << _product.price << std::endl;
        os << "Quantity: " << _product.quantity << std::endl;

        return os;
    }
};

void print_products(const struct Products *list, int n);
void insert_new_product(struct Products* &list, int &n);
void remove_product(struct Products* &list, int &n);
void press_to_continue();
void menu();

int main(){
    int n = 0;
    struct Products *list = new struct Products[n];
    bool running = true;
    int choice;

    while (running){
        menu();
        std::cout << "Your choice: ";
        std::cin >> choice;
        system("cls");

        switch(choice){
            case 0:
                std::cout << "You exited the program";
                running = false;
                break; 

            case 1:
                print_products(list, n);
                press_to_continue();
                system("cls");
                break;
            
            case 2:
                insert_new_product(list, n);
                press_to_continue();
                system("cls");
                break;
            
            case 3:
                remove_product(list, n);
                press_to_continue();
                system("cls");
                break;
            
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }


    delete[] list;
    return 0;
}

void print_products(const struct Products *list, int n){
    if (n < 1){
        std::cout << "You don't have any products" << std::endl;
        return;
    }

    for (int i = 0; i < n; i++){
        std::cout << "Products number " << (i + 1) << std::endl;
        std::cout << list[i];       
    }
}

void insert_new_product(struct Products* &list, int &n){
    int new_size = n + 1;
    Products new_products;
    Products *new_list = new Products[new_size];
    std::cout << "Enter information of new product" << std::endl;
    std::cin >> new_products;

    for (int i = 0; i < n; i++){
        new_list[i] = list[i];
    }

    delete[] list;
    new_list[new_size - 1] = new_products;
    list = new_list;
    n = new_size;
    // delete[] new_list;
}   

void remove_product(struct Products* &list, int &n){
    int new_size = n;
    int index;
    std::string deleted_name;    
    std::cout << "Enter name of product: ";
    std::cin.ignore();
    std::getline(std::cin, deleted_name);

    for (int i = 0; i < n; i++){
        if (deleted_name.compare(list[i].name)){
            for (int j = i; j < n - 1; j++){
                list[j] = list[j + 1];
            }
            new_size--;
        }
    }

    Products *new_list = new Products[new_size];
    for (int i = 0; i < new_size; i++){
        new_list[i] = list[i];
    }

    delete[] list;
    list = new_list;
    n = new_size;
    // delete[] new_list;
}

void press_to_continue(){
    std::cout << "Press any key to continue..." << std::endl;
    getch();
}

void menu(){
    std::cout << "1-Print product" << std::endl
        << "2-Insert product" << std::endl
        << "3-Remove product" << std::endl
        << "0-Exit" << std::endl;
}