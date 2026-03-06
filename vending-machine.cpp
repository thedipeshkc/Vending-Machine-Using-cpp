// vending machine program that sells 5 different items
// user selects from 5 items (each with a price); insert coins ($0.01, $0.05, $0.10, $0.25,..etc)
// rogram tracks total coins and checks if enough and allows multiple coin entries,dispense item,return change
// error handle for wrong coins value

#include <iostream>   // for cin and cout
#include <string>     // for string type
using namespace std;

// definimg items in vending machine by using variable and constant
// defining function(void-which doesnot return value) to show menu to user

void show_menu()
{
    cout << "\n==============================================\n";
    cout << "        WELCOME TO DIPESH VENDING MACHINE      \n";
    cout << "==============================================\n";
    cout << "  1. Water Bottle       $0.75\n";
    cout << "  2. Chips              $1.25\n";
    cout << "  3. Chocolate Bar      $1.50\n";
    cout << "  4. Soda Can           $1.00\n";
    cout << "  5. Gum Pack           $0.50\n";
    cout << "==============================================\n";
    cout << "  Enter your choice from 1 to 5: ";
}

// another function (used double as it returns decimal num) to get price of selected item
// get_price(int choice)-takes users selection and returs its price as double
// uses an if-else chain

double get_price(int choice)
{
    if (choice == 1) return 0.75;
    else if (choice == 2) return 1.25;
    else if (choice == 3) return 1.50;
    else if (choice == 4) return 1.00;
    else if (choice == 5) return 0.50;
    else return -1;   // -1 means invalid choice
}

// another function(used sting because it returs word) to get name of selected item

string get_item_name(int choice)
{
    if (choice == 1) return "Water Bottle";
    else if (choice == 2) return "Chips";
    else if (choice == 3) return "Chocolate Bar";
    else if (choice == 4) return "Soda Can";
    else if (choice == 5) return "Gum Pack";
    else return "Unknown";
}

// again defining new function(bool for yes/no) to check if a coin value is valid (error handling)
//  valid coins: $0.01, $0.05, $0.10, $0.25, $0.50, $1.00

bool is_valid_coin(double coin)
{
    if (coin == 0.01) return true;
    else if (coin == 0.05) return true;
    else if (coin == 0.10) return true;
    else if (coin == 0.25) return true;
    else if (coin == 0.50) return true;
    else if (coin == 1.00) return true;
    else return false;
}

// shows valid coins to user
void show_coin_options()
{
    cout << "\n  Valid coin values:\n";
    cout << "    $0.01  $0.05  $0.10  $0.25  $0.50  $1.00\n";
    cout << "  Enter a coin (or 0 to cancel): $";
}

// defining main function where program starts

int main()
{
    // calling show_menu function and getting user's item selection
    show_menu();

    int choice = 0;
    cin >> choice;

    //checking if input failed or choice is out of range(if input will "abcd text",it should reject
    // used if condition, !cin which means if cin is false(like gets etxt abcd...), then it prints error message
    if (!cin) {
        cout << "\n  ERROR: Please enter a number, not text.\n";
        return 1;   // exit program with error code
    }

    
    double price = get_price(choice);

    if (price == -1) {
        cout << "\n  ERROR: Invalid choice. Please select 1 to 5.\n";
        return 1;
    }

    string item_name = get_item_name(choice);

    cout << "\n  You selected: " << item_name;
    cout << "\n  Price: $" << price << "\n";

    // collecting coins from the user

    double total_inserted = 0.0;  // tracks how much money was inserted
    int coin_count = 0;  // tracks how many coins were inserted

    cout << "\n  Insert coins until you reach $" << price << "\n";

    // while-loop keeps asking for coins until enough is inserted

    while (total_inserted < price)
    {
        show_coin_options();

        double coin = 0.0;
        cin >> coin;

        // error handling:wrong input (like letters)
        if (!cin) {
            cin.clear();            // clear the error flag
            cin.ignore(1000, '\n'); // throw away bad input
            cout << "  ERROR: That is not a valid number. Try again.\n";
            continue;  // go back to the top of the loop
        }

        // allows user to cancel
        if (coin == 0) {
            cout << "\n  Transaction cancelled. No coins were taken.\n";
            return 0;
        }

        // checking if coin value is valid
        if (!is_valid_coin(coin)) {
            cout << "  ERROR: $" << coin << " is not a valid coin. Try again.\n";
            continue;
        }

        // if valid coin then adding it to total
        total_inserted = total_inserted + coin;
        coin_count = coin_count + 1;

        cout << "  Coin accepted! Total inserted: $" << total_inserted;
        cout << "  (coins used: " << coin_count << ")\n";

        // show how much more is needed
        if (total_inserted < price) {
            double still_needed = price - total_inserted;
            cout << "  Still need: $" << still_needed << "\n";
        }
    }

    // dispensing item and return change

    double change = total_inserted - price;

    cout << "\n===================================================================\n";
    cout << "Enjoy !! " << item_name << " has been dispensed!Have a great time!!  \n";
    cout << "  Coins inserted : " << coin_count << "\n";
    cout << "  Amount paid    : $" << total_inserted << "\n";
    cout << "  Item price     : $" << price << "\n";

    if (change > 0) {
        cout << "  Change returned: $" << change << "\n";
    }
    else {
        cout << "  No change needed. Exact amount paid! Perfecto!! \n";
    }

    cout << "=======================================================================\n";
    cout << "  Thank you for your purchase! Happy Day!! Visit me Again !!\n\n";

    return 0;  // program finished successfully
}