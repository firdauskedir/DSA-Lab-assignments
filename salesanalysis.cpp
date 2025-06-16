#include <iostream>
#include <string>
#define TAX_RATE_PREPROCESSOR 0.08  // Preprocessor constant
const float TAX_RATE_CONST = 0.08;  // Const constant for tax rate

using namespace std;

int main() {

    // Display an introductory message
    cout << "Welcome" << endl;
    cout << "This program helps store managers analyze product inventory and sales." << endl;
    cout << "Reminder: C++ is a compiled language." << endl;

    // Declare variables for product details
    string productName;             //for writting Product name (a single word)
    int productCategory;            // An integer from (1 to 5)
    int initialInventoryQuantity;   // Initial inventory quantity
    float productPrice;      // Product price per unit
    int itemsSold;                  // Number of items sold

    //Accepting input from the user
    cout << "Enter the product name: ";
    cin >> productName;
    cout << "Enter product category (1-5): ";
    cin >> productCategory;
    cout << "Enter initial inventory quantity: ";
    cin >> initialInventoryQuantity;
    cout << "Enter product price: ";
    cin >> productPrice;
    cout << "Enter number of items sold: ";
    cin >> itemsSold;

    // Declare computed variables
   int newInventory;       //calcualted as initial inventory minus items sold         
      newInventory = initialInventoryQuantity - itemsSold;
   float totalsalesamount;      //calculated as number of items sold multiplied by the product price
        totalsalesamount = itemsSold * productPrice;
   string inventoryStatus; //set to Low Inventory if the new inventory is less than 10 otherwise Sufficient Inventory
        if (newInventory <10)
        {
            inventoryStatus = "Low Inventory";
        }
        else
        {
            inventoryStatus = "Sufficient Inventory";
        }

    // Different initialization methods
   int sample1 = 23; // Direct initialization
   int sample2;
   sample2 = 45; // Declaration first, then assignment
   int sample3{30}; // List initialization

   // Type deduction for extra helper variables
   auto totalsalesamountcopy = totalsalesamount;
   decltype(initialInventoryQuantity) newInventoryCopy = newInventory;

   //Implement flow control(switch statement)

    if (productCategory < 1 || productCategory > 5) {
        cout << "Invalid category" << endl;
    } 
    else
    {
        switch(productCategory) {
       case 1:
           cout << "Category 1: Electronics\n"; break;
         case 2:
              cout << "Category 2: Groceries\n"; break;
            case 3:
                cout << "Category 3: Clothing\n"; break;
            case 4:
                cout << "Category 4: Stationery\n"; break;
            case 5:
                cout << "Category 5: Miscellaneous\n"; break;
        }
    }
// using for loop to print
cout << "receipt; \n";
for (int i = 1; i <= itemsSold; i++) {
    cout << productName << ":" << productPrice << endl;
}
// final step: printing
cout << "Product Name: " << productName << endl;
cout << "Product Category: " << productCategory << endl;
cout << "Initial Inventory Quantity: " << initialInventoryQuantity << endl;
cout << "Product Price: " << productPrice << endl;
cout << "Items Sold: " << itemsSold << endl;
// print computed variables
cout << "New Inventory: " << newInventory << endl;
cout << "Total Sales Amount: " << totalsalesamount << endl;
cout << "Inventory Status: " << inventoryStatus << endl;
// print tax rates
cout << "Tax Rate (Preprocessor): " << TAX_RATE_PREPROCESSOR * 100 << "%" << endl;
cout << "Tax Rate (Constant variable): " << TAX_RATE_CONST * 100 << "%" << endl;
// print helper variables from the type deduction
cout << "Total Sales Amount Copy: " << totalsalesamountcopy << endl;
cout << "New Inventory Copy: " << newInventoryCopy << endl;

return 0;
}   