/*An ATM allows a customer to withdraw a maximum of $500 per day.
If a customer withdraws more than $300, the service charge is 4% of the amount over $300.
If the customer does not have sufficient money in the account, the ATM informs the customer
about the insufficient funds and gives the customer the option to withdraw the
money for a service charge of $25.00. If there is no money in the account or if the account balance is negative,
the ATM does not allow the customer to withdraw any money. If the amount to be withdrawn is greater than $500,
the ATM informs the customer about the maximum amount that can be withdrawn. Write a C++ program that allows
the customer to enter the amount to be withdrawn. The program then checks the total amount in the account,
dispenses the money to the customer, and debits the account by the amount withdrawn and the service charges.*/


//Customer can withdraw max %500 daily
// if withdrawAmount > $300, Service charge == 4% of the amount over $300
// if withdrawAmount < Amount u want to withdraw, "You do not have enough money in your account"
// Give option to withdraw(Borrow) at a service charge of $25.00
// if withdrawAmount < 0(Negative) or if withdrawAmount = 0, "You do not have enough money in your account, you cannot withdraw"
// if withdrawAmount > $500, "You can only withdraw a maximum of $500"
// User must enter amount to be withdrawn
// Program must check the total amount in the acc
// Complete code
#include <iostream>

int main(){
    //Variables
    int choice;
    float balance = 0.0;
    float withdrawAmount;
    float newAmount;
    float serviceCharge1 = 0.04;
    float serviceCharge2 = 25;
    std::string decision;
    std::string re_withdraw = "y";

    //Beginning Interface
    std::cout << "Welcome to Cyber World ATM. You have $35,000 in your account." << std::endl;
    std::cout << "Please enter your balance of choice" << std::endl;
    std::cout << "1. A fixed amount of $400\n2. Input your own balance" << std::endl;
    //Input the choice of your balance
    std:: cout << "Input: "; std::cin >> choice;

    //Balance Choice
    if (choice == 1){
        std::cout << "You have a balance of $400" << std::endl;
        balance = 400;
    }else if (choice == 2){
        std::cout << "Please enter your balance of choice" << std::endl;
        std::cin >> balance;
        std::cout << "You have a balance of $" << balance << std::endl;
    }else{
        std::cout << "Invalid choice" << std::endl;
    }


    while (re_withdraw == "y" || re_withdraw == "Y"){
        //Inputting amount to withdraw
        std::cout << "Enter amount to withdraw: ";
        std::cin >> withdrawAmount;

        if (withdrawAmount <= 500 && withdrawAmount >= 0){

            newAmount = withdrawAmount;

            if (balance >= newAmount){
                if (withdrawAmount > 300){

                    //Calculation of New Amount (Balance after Service Charge application)
                    newAmount += ((serviceCharge1 * withdrawAmount) / 300);

                    //New Balance
                    balance -= newAmount;

                    //Output
                    std::cout << "---------------------------------------------" << std::endl;
                    std::cout << "            ATM TRANSACTION SUMMARY           " << std::endl;
                    std::cout << "---------------------------------------------" << std::endl;
                    std::cout << "AMOUNT WITHDRAWN:                 $" << withdrawAmount << std::endl;
                    std::cout << "SERVICE CHARGED:                  $"<< (serviceCharge1 * withdrawAmount) / 300 << std::endl;
                    std::cout << "TOTAL AMOUNT DETECTED:            $"<< newAmount << std::endl;
                    std::cout << "______________________________________________" << std::endl;
                    std::cout << "YOUR CURRENT BALANCE IS:          $" << balance << std::endl;
                    std::cout << "______________________________________________" << std::endl;

                    std::cout << "Would you like to withdraw again?(Y/N)";
                    std::cin >> re_withdraw;

                }else{
                    //New Balance
                    balance -= withdrawAmount;

                    //Output
                    std::cout << "---------------------------------------------" << std::endl;
                    std::cout << "            ATM TRANSACTION SUMMARY           " << std::endl;
                    std::cout << "---------------------------------------------" << std::endl;
                    std::cout << "AMOUNT WITHDRAWN:                 $" << withdrawAmount << std::endl;
                    std::cout << "SERVICE CHARGE:                   $0.00" << std::endl;
                    std::cout << "TOTAL AMOUNT DEDUCTED:            $0.00" << std::endl;
                    std::cout << "______________________________________________" << std::endl;
                    std::cout << "YOUR CURRENT BALANCE IS:          $" << balance << std::endl;
                    std::cout << "______________________________________________" << std::endl;

                    std::cout << "Would you like to withdraw again?(Y/N)";
                    std::cin >> re_withdraw;

                }
                //If Balance is less than the withdraw amount but you still have money in your account.
            }else if (balance < newAmount && withdrawAmount > 0 && balance > 0){
                std::cout << "You do not have enough money in your account." << std::endl;
                std::cout <<"Do you want to withdraw at a service charge of $25? (Y/N)";
                std::cin >> decision;
                //If you want to go through with the decision
                if (decision == "Y" || decision == "y"){
                    //Calculation of New Amount (Balance after Service charge application)
                    newAmount = serviceCharge2 + withdrawAmount;

                    //New Balance
                    balance -= newAmount;

                    std::cout << "---------------------------------------------" << std::endl;
                    std::cout << "            ATM TRANSACTION SUMMARY           " << std::endl;
                    std::cout << "---------------------------------------------" << std::endl;
                    std::cout << "AMOUNT WITHDRAWN:                 $" << withdrawAmount << std::endl;
                    std::cout << "SERVICE CHARGED:                  $" << serviceCharge2 <<  std::endl;
                    std::cout << "TOTAL AMOUNT DEDUCTED:            $"<< newAmount << std::endl;
                    std::cout << "______________________________________________" << std::endl;
                    std::cout << "YOUR CURRENT BALANCE IS:          $" << balance << std::endl;
                    std::cout << "______________________________________________" << std::endl;

                    std::cout << "Would you like to withdraw again?(Y/N)";
                    std::cin >> re_withdraw;

                }else{
                    std::cout << "Thank you for using Cyber World ATM";
                }
            }else{
                //if Balance is Negative or 0
                std::cout << "You Don't have enough money in your account.";
                std::cout << "Thank you for using Cyber World ATM";
            }
        }else{
        //If you input an amount more than $500
        std::cout << "Invalid amount to withdraw. Maximum withdraw amount is $500";
        }
    }



    return 0;
}