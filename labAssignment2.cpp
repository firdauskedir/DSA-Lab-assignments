#include <iostream>
#include <string>
using namespace std;


//structre example code
struct female {
    string name;
    int age;
    string nationality;
    double height;
};


//overload example code
int multiply(int a, int b) {
    return a * b;
}
double multiply(double a, double b) {
    return a * b;
}
//template example code
template <typename T>
T multiply(T a, T b) {
 return a * b;
}

int main() {

    //example for overload
    cout << "Multiplication of integers: " << multiply(5, 10) << endl;
    cout << "Multiplication of doubles: " << multiply(5.5, 10.5) << endl;

    //example for template
    cout << "Multiplication of template: " << multiply(5, 10) << endl;
    cout << "Multiplication of template: " << multiply(5.5, 10.5) << endl;
    
    
    // example for structure
    female F1;
    F1.name = "Firdaus";
    F1.age = 19;
    F1.nationality = "Ethiopian";
    F1.height = 165.5;

    cout << "Name: " << F1.name << endl;
    cout<< "Age: " << F1.age << endl;
    cout<< "Nationality: " << F1.nationality << endl;
    cout<< "Height: " << F1.height << endl;

    return 0;

}
