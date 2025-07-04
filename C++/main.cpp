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
    float extraCharge = 0.0;
    float balance = 400.00;
    float withdrawAmount;
    float newAmount;
    float serviceCharge1 = 0.04;
    float serviceCharge2 = 25.00;
    float totalWithdrawn = 0.00;
    std::string decision;
    std::string reWithdraw = "y";

    //Beginning Interface
    std::cout << "Welcome to Cyber World ATM. You have $5,000 in your account." << std::endl;

    while (reWithdraw == "y" || reWithdraw == "Y")
    {
        //Inputting amount to withdraw
        std::cout << "Enter amount to withdraw: ";
        std::cin >> withdrawAmount;


        if (withdrawAmount > 300) {
            extraCharge = (serviceCharge1 * withdrawAmount) / 300;
        }

        //Calculation of New Amount (Balance after Service Charge application)
        newAmount = withdrawAmount + extraCharge;


        if (totalWithdrawn + withdrawAmount <= 500){
            if (withdrawAmount <= 500 && withdrawAmount >= 0){


                if (balance >= newAmount){
                    if (withdrawAmount > 300){
                        //New Balance
                        balance -= newAmount;

                            //Total Amount Withdrawn
                            totalWithdrawn += newAmount;

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

                        std::cout << "You can still withdraw $" << (500 - totalWithdrawn) << " today." << std::endl;

                            std::cout << "Would you like to withdraw again?(Y/N)";
                            std::cin >> reWithdraw;

                    }else{
                        //New Balance
                        balance -= withdrawAmount;

                        //Total Amount Withdrawn
                        totalWithdrawn += newAmount;

                        //Output
                        std::cout << "---------------------------------------------" << std::endl;
                        std::cout << "            ATM TRANSACTION SUMMARY           " << std::endl;
                        std::cout << "---------------------------------------------" << std::endl;
                        std::cout << "AMOUNT WITHDRAWN:                 $" << withdrawAmount << std::endl;
                        std::cout << "SERVICE CHARGE:                   $0.00" << std::endl;
                        std::cout << "TOTAL AMOUNT DEDUCTED:            $" << withdrawAmount << std::endl;
                        std::cout << "______________________________________________" << std::endl;
                        std::cout << "YOUR CURRENT BALANCE IS:          $" << balance << std::endl;
                        std::cout << "______________________________________________" << std::endl;

                        std::cout << "You can still withdraw $" << (500 - totalWithdrawn) << " today." << std::endl;

                        std::cout << "Would you like to withdraw again?(Y/N)";
                        std::cin >> reWithdraw;

                    }
                    //If balance is less than the withdrawn amount, but you still have money in your account.
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

                        //Total Amount Withdrawn
                        totalWithdrawn += withdrawAmount;

                        std::cout << "---------------------------------------------" << std::endl;
                        std::cout << "            ATM TRANSACTION SUMMARY           " << std::endl;
                        std::cout << "---------------------------------------------" << std::endl;
                        std::cout << "AMOUNT WITHDRAWN:                 $" << withdrawAmount << std::endl;
                        std::cout << "SERVICE CHARGED:                  $" << serviceCharge2 <<  std::endl;
                        std::cout << "TOTAL AMOUNT DEDUCTED:            $"<< newAmount << std::endl;
                        std::cout << "______________________________________________" << std::endl;
                        std::cout << "YOUR CURRENT BALANCE IS:          $" << balance << std::endl;
                        std::cout << "______________________________________________" << std::endl;

                        std::cout << "You have reached your withdrawal limit for today." << std::endl;
                        reWithdraw = "n";
                    }else{
                        std::cout << "Thank you for using Cyber World ATM";
                        break;
                    }
                }else{
                    //if Balance is Negative or 0
                    std::cout << "You Don't have enough money in your account.";
                    std::cout << "Thank you for using Cyber World ATM";
                    break;
                }
            }else{
                //If you input an amount more than $500
                std::cout << "Invalid amount to withdraw. Maximum withdraw amount is $500"<< std::endl;
            }
        }else{
            std::cout << "Withdrawal failed. Your Daily limit is $500." << std::endl;
        }
    }


    return 0;
}