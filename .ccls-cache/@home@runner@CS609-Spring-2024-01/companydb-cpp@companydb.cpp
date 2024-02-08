#include <iostream>
#include <fstream>
#include <iomanip>
#include "company.h"
#include "employee.h"
#include "customer.h"

using namespace std;

int get_mm()
{
    bool done = false;
    int input;
    do {
        cout << endl;
        cout << "    MAIN MENU\n" << "1.) Employees\n" << "2.) Sales\n" << "3.) Quit" << endl << endl << "Choice? ";
        while(!isdigit(cin.peek())) 
            cin.get();
        cin >> input;
        cin.ignore();
        if(input < 0 || input > 3)
            cout << "Invalid Selection, please try again." << endl;
        else
            done = true;
    } while(not done);
    return input;
}

char get_cm()
{
    bool done = false;
    string c;
    do {
        std::cout << std::endl;
        cout << "(A)dd Customr, Enter a (S)ale, (V)iew Customer, or (M)ain Menu? ";
        getline(cin, c);
        c[0] = toupper(c[0]);
        if(c != "A" && c != "M" && c != "S" && c != "V")
            std::cout << "Invalid Selection, please try again." << std::endl;
        else
            done = true;
    } while(not done);
    return c[0];
}

int get_csm(Company company)
{
    bool done = false;
    int input;
    do {
        cout << endl;
        input = 1;
        for(auto itr = company.customer_begin(); itr < company.customer_end(); itr++){
            Customer temp = *itr;
            cout << input++ << ".) " << temp.name() << endl;
        }
        cout << "choice? ";
        while(!isdigit(std::cin.peek())) std::cin.get();
        cin >> input;
        cin.ignore();
        if(input < 1 || input > company.customer_end() - company.customer_begin())
            cout << "Invalid Selection, please try again." << endl;
        else
            done = true;
    } while(not done);
    return input;
}

int main(){    
    string temp_str;
    int menuitem_response;

    cout << "Company Name: ";
    getline(cin, temp_str);
    Company company(temp_str + ".dat");
    ifstream fin;
    string line;
    fin.open(company.name());
    while (getline(fin, line)){
        for(int i= 0; i< stoi(line); i++){
            Employee employee;
            fin >> employee;
            company.add_employee(employee);
        }
        getline(fin, line);
        int temp = stoi(line);
        for(int i= 0; i < temp; i++){
            Customer customer;
            fin >> customer;
            getline(fin, line);
            for(int j=0; j< stoi(line); j++){
                Purchase purchase("", 0, 0);
                fin >> purchase;
                customer.add_purchase(purchase);
            }
            company.add_customer(customer);
        }
    }
    fin.close();

    menuitem_response = get_mm();
    char cus_mi;
    while(menuitem_response == 1 || menuitem_response == 2)
    {
        if(menuitem_response == 1)
        {
            for(auto itr = company.employee_begin(); itr != company.employee_end(); itr++)
                cout << *itr;
            while(true) {
                std::cout << "(A)dd Employee or (M)ain Menu? ";
                getline(cin, temp_str);
                temp_str[0] = toupper(temp_str[0]);
                if(temp_str != "A" and temp_str != "M") {
                    std::cout << "Invalid Selection, please try again." << std::endl;
                } 
                else {
                    if(temp_str == "M")
                        break;
                    else{
                        Employee employee;
                        cin >> employee;
                        company.add_employee(employee);
                        for(auto itr = company.employee_begin(); itr != company.employee_end(); itr++)
                            cout << *itr;
                    }
                }
            }
        }
        else
        {
            cus_mi = get_cm();
            while(cus_mi == 'A' || cus_mi == 'S' || cus_mi == 'V' || cus_mi == 'M'){
                if(cus_mi == 'A'){
                    Customer customer;
                    cin >> customer;
                    company.add_customer(customer);
                }
                else if(cus_mi == 'V' || cus_mi == 'S'){
                    if(company.customer_end() - company.customer_begin() > 0){
                        menuitem_response = get_csm(company);
                        auto ptr = company.customer_begin() + menuitem_response - 1;
                        if(cus_mi == 'S'){
                            Customer customer = *ptr;
                            Purchase purchase("", 0, 0);
                            cin >> purchase;
                            customer.add_purchase(purchase);
                            *ptr = customer;
                        }
                        else
                            cout << *ptr;
                    }
                    else{
                        cout << "Error: No Customers!";
                    }
                }
                else
                    break;

                cus_mi = get_cm();
            }
        }
        menuitem_response = get_mm();
    }

    ofstream fout;
    fout.open(company.name());
    fout << company;
    fout.close();

    return 0;
}
