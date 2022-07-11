#include <iostream>
#include <fstream>
#include <vector>


int main() {
    std::cout << "Enter the path to the list: ";
    std::string path;
    std::getline (std::cin, path);

    std::ifstream file;
    file.open (path);
    while (!file.is_open()){
        std::cout << "Enter the correct path to the list: ";
        std::getline (std::cin, path);
        file.open (path);
    }

    std::vector <std::string> name;
    std::vector <std::string> surname;
    std::vector <int> payment;
    std::vector <std::string> date;
    int allPayment = 0;


    for (int i =0; i < 4 && !file.eof();i++){
         std::string buffer;
         file >> buffer;
         if (i == 0) {name.push_back(buffer);}
         if (i == 1) {surname.push_back(buffer);}
         try {
             if (i == 2) {
                 int temp = std::stoi(buffer);
                 payment.push_back(temp);
                 allPayment += std::stoi(buffer);
             }
         }catch (const std::exception& obj)
             {
                 std::cerr << obj.what();
             }
         if (i == 3) {date.push_back (buffer); i = -1;}
    }
    std::cout << "All payment = " << allPayment << std::endl;
    int maxPayment = 0;
    int indexMax = 0;
    for (int i =0; i < payment.size(); i++){
        if (payment [i] > maxPayment) {maxPayment = payment [i]; indexMax = i;}
    }
    std::cout << name [indexMax] << " "<<surname [indexMax] << " received the maximum payout of "
        << maxPayment << " on the "<<date [indexMax] << std::endl;
}


