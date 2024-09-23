/*
 * Fruit Juice Machine Simulation Program
 * 
 * Description:
 * This program simulates a vending machine for fruit juices. It contains two main classes:
 * - `cashRegister`: Manages the current balance of cash in the machine.
 * - `dispenserType`: Manages the items available in the machine and their cost.
 * 
 * Features:
 * - Users can select a juice, enter the required amount, and make a purchase.
 * - The program checks if the entered amount is sufficient and returns change if necessary.
 * - Products are deducted from stock after each sale.
 * - Error handling for insufficient balance or out-of-stock items.
 * 
 * Written By: Preet Kulkarni
 * 
 * Future Updates:
 * 1. Add a better cash management system that handles multiple denominations.
 * 2. Implement a front-end interface for better user interaction.
 * 3. Add more products and dynamic product management.
 */

// Class for managing the cash register
class cashRegister {
    public:
        int getCurrentBalance() const;
        void acceptAmount(int);
        cashRegister();
        cashRegister(int);

    private:
        int cashOnHand;
};

// Function to get the current balance in the cash register
int cashRegister::getCurrentBalance() const {
    return cashOnHand;
}

// Function to accept an amount and update the cash register balance
void cashRegister::acceptAmount(int amount) {
    cashOnHand += amount;
}

// Default constructor setting an initial cash amount of 500
cashRegister::cashRegister() {
    cashOnHand = 500;
}

// Parameterized constructor to set a custom initial balance
cashRegister::cashRegister(int amount) {
    cashOnHand = (amount >= 0) ? amount : 500;
}

// Class for managing the product dispensers
class dispenserType {
    public:
        int getNoOfItems() const;
        int getCost() const;
        void makeSale();
        dispenserType();
        dispenserType(int, int);

    private:
        int numberOfItems;
        int cost;
};

// Function to get the number of items available in the dispenser
int dispenserType::getNoOfItems() const {
    return numberOfItems;
}

// Function to get the cost of the product
int dispenserType::getCost() const {
    return cost;
}

// Function to reduce the number of items by 1 after a sale
void dispenserType::makeSale() {
    numberOfItems--;
}

// Default constructor initializing the dispenser with 50 items and a cost of 50
dispenserType::dispenserType() {
    numberOfItems = 50;
    cost = 50;
}

// Parameterized constructor to set a custom number of items and cost
dispenserType::dispenserType(int items, int costx) {
    numberOfItems = (items >= 0) ? items : 50;
    cost = (costx >= 0) ? costx : 50;
}

// Function to display the product selection menu
void showSelection() {
    std::cout << "Welcome to the Fruit Juice Machine!\n";
    std::cout << "Enter 1 for Apple Juice\n";
    std::cout << "Enter 2 for Orange Juice\n";
    std::cout << "Enter 3 for Mango Lassi\n";
    std::cout << "Enter 4 for Fruit Punch\n";
    std::cout << "Enter 9 to exit.\n";
    std::cout << "Enter selection: ";
}

// Function to handle the product sale and update the cash register
void sellProduct(dispenserType& product, cashRegister& pcounter) {
    int amountEntered;
    int remainingAmount;

    if (product.getNoOfItems() > 0) {
        std::cout << "Cost = " << product.getCost() << std::endl;
        std::cout << "Enter amount: ";
        std::cin >> amountEntered;

        // Handling insufficient balance
        if (amountEntered < product.getCost()) {
            int amountNeeded = product.getCost() - amountEntered;
            std::cout << "Insufficient balance.\n";
            std::cout << "Please enter " << amountNeeded << " to proceed: ";
            std::cin >> amountNeeded;
            amountEntered += amountNeeded;
        }

        if (amountEntered < product.getCost()) {
            std::cout << "Insufficient balance, cancelling transaction...\n";
            std::cout << "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n\n";
        } else {
            remainingAmount = amountEntered - product.getCost();
            product.makeSale();
            pcounter.acceptAmount(product.getCost());
            std::cout << "Thank you for your purchase!\n";
            std::cout << "Dispensing...\n";

            if (remainingAmount > 0) {
                std::cout << "Change: " << remainingAmount << std::endl;
            }
            std::cout << "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n\n";
        }
    } else {
        std::cout << "Sorry! This product is out of stock.\n";
        std::cout << "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n\n";
    }
}

int main() {
    int choice;

    // Creating instances of cashRegister and dispenserType
    cashRegister reg;
    dispenserType apple;
    dispenserType orange;
    dispenserType mangoLassi;
    dispenserType fruitPunch(100, 70);

    showSelection();
    std::cin >> choice;

    // Main loop to handle product selection
    while (choice != 9) {
        switch (choice) {
            case 1:
                sellProduct(apple, reg);
                break;
            case 2:
                sellProduct(orange, reg);
                break;
            case 3:
                sellProduct(mangoLassi, reg);
                break;
            case 4:
                sellProduct(fruitPunch, reg);
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
        showSelection();
        std::cin >> choice;
    }

    return 0;
}
