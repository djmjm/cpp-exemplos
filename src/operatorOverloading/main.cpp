#include <iostream>

using namespace std;

class Product{
    private: 
        string name = "Generic Product";
        double price = 1.99;
    public:
        Product(){};
        Product(string name, double price){
            this->name = name;
            this->price = price;
        };
        string get_name(){ return name; };
        double get_price(){ return price; };
        
        friend ostream& operator << (ostream &out, const Product &product);
};

ostream& operator << (ostream &out, Product &product){
    out <<  product.get_name() << " | "
        << "$" << product.get_price();
        
    return out;
};

double operator + (double value, Product &product){
    return value + product.get_price();
}

double operator + (Product &product2, Product &product1){
    return product2.get_price() + product1.get_price();
}

int main(){
    Product *generic = new Product();
    Product *coffee = new Product("Coffee", 5.89);
    Product *milk = new Product("Milk", 6.14);
    
    cout << *generic << endl;
    cout << *coffee << endl;
    cout << *milk << endl;
    
    cout << "Total Cost: $" << 
            (
             *generic +
             *coffee +
             *milk
            ) 
         << endl;
    
    return 0;
}