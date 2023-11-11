#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <set>
#include <algorithm>

class User
{
public:
    std::string name{};
    std::string surname{};
    std::string phone_num{};
    std::string adress{};
    std::string postal_code{};
};

void user_delete(std::string user_component)
{
}

void trim(User &user)
{
    // name
    std::string token{""};
    for (int i{0}; i < user.name.size(); i++)
    {
        std::set<char> wsc{' ', '\n', '\r', '\t'};
        if (!wsc.contains(user.name[i]))
        {
            token += user.name[i];
        }
    }
    user.name = token;
    token = "";

    // surname
    for (int i{0}; i < user.surname.size(); i++)
    {
        std::set<char> wsc{' ', '\n', '\r', '\t'};
        if (!wsc.contains(user.surname[i]))
        {
            token += user.surname[i];
        }
    }
    user.surname = token;
    token = "";

    // phone_num
    for (int i{0}; i < user.phone_num.size(); i++)
    {
        std::set<char> wsc{' ', '\n', '\r', '\t'};
        if (!wsc.contains(user.phone_num[i]))
        {
            token += user.phone_num[i];
        }
    }
    user.phone_num = token;
    token = "";

    // adress
    for (int i{0}; i < user.adress.size(); i++)
    {
        std::set<char> wsc{' ', '\n', '\r', '\t'};
        if (!wsc.contains(user.adress[i]))
        {
            token += user.adress[i];
        }
    }
    user.adress = token;
    token = "";

    // postal_code
    for (int i{0}; i < user.postal_code.size(); i++)
    {
        std::set<char> wsc{' ', '\n', '\r', '\t'};
        if (!wsc.contains(user.postal_code[i]))
        {
            token += user.postal_code[i];
        }
    }
    user.postal_code = token;
    token = "";
}

void clean_print(User user)
{

    std::string delimiter{":"};
    std::string token{user.name.substr(user.name.find(delimiter) + 1, user.name.size())};
    user.name = token;

    token = user.surname.substr(user.surname.find(delimiter) + 1, user.surname.size());
    user.surname = token;

    token = user.phone_num.substr(user.phone_num.find(delimiter) + 1, user.phone_num.size());
    user.phone_num = token;

    token = user.adress.substr(user.adress.find(delimiter) + 1, user.adress.size());
    user.adress = token;

    token = user.postal_code.substr(user.postal_code.find(delimiter) + 1, user.postal_code.size());
    user.postal_code = token;

    std::cout << user.name << '\n';
    std::cout << user.surname << '\n';
    std::cout << user.phone_num << '\n';
    std::cout << user.adress << '\n';
    std::cout << user.postal_code << '\n';
};

void to_lower(User &user)
{
    std::transform(user.name.begin(), user.name.end(), user.name.begin(), ::tolower);

    std::transform(user.surname.begin(), user.surname.end(), user.surname.begin(), ::tolower);

    std::transform(user.phone_num.begin(), user.phone_num.end(), user.phone_num.begin(), ::tolower);

    std::transform(user.adress.begin(), user.adress.end(), user.adress.begin(), ::tolower);

    std::transform(user.postal_code.begin(), user.postal_code.end(), user.postal_code.begin(), ::tolower);
}

void file_output(User user)
{

    std::ofstream temp_os{"adressbook.txt", std::ios::app};
    temp_os << "N:" << user.name << '\n';
    temp_os << "S:" << user.surname << '\n';
    temp_os << "PN:" << user.phone_num << '\n';
    temp_os << "A:" << user.adress << '\n';
    temp_os << "PC:" << user.postal_code << '\n';
    temp_os << "E\n";
    temp_os.close();
}

int main()
{

    std::ofstream ofile("adressbook.txt", std::ios::app);
    std::ifstream ifile("adressbook.txt", std::ios::app);

    std::vector<User> ab_content{};

    while (true)
    {

        std::vector<User> data{};

        User user;

        std::cout << "Choose by typing the corresponding number\n";

        std::cout << "1. View the Adress Book\n";

        std::cout << "2. Add a new user\n";

        std::cout << "3. Delete a user\n";

        std::cout << "4. Edit a user\n";

        std::cout << "5. End program\n";

        std::cout << "6. Clear list\n";

        std::string kofol_a;

        int a{};

        std::cin >> a;

        if (a == 5)
        {
            ifile.close();
            ofile.close();
            break;
        }

        if (!ifile.is_open())
        {
            ifile.open("adressbook.txt", std::ios::app);
        }

        if (!ofile.is_open())
        {
            ofile.open("adressbook.txt", std::ios::app);
        }

        std::string temp{};

        switch (a)
        {
        case 1:

            /*while (ifile >> temp)
            {
                data.push_back(temp);
            }

            for (int i{0}; i < static_cast<int>(data.size()); i++)
            {
                std::cout << data[i] << '\n';
            }

            for (int i{0}; i < data.size(); i++)
            {
                std::cout << data[i].name
            }

            for (User currentUser : data)
            {
                std::cout << currentUser.name
            }
            */

            while (ifile >> temp)
            {
                if (temp.starts_with("N:"))
                {
                    user.name = temp;
                }
                else if (temp.starts_with("S:"))
                {
                    user.surname = temp;
                }
                else if (temp.starts_with("PN:"))
                {
                    user.phone_num = temp;
                }
                else if (temp.starts_with("A:"))
                {
                    user.adress = temp;
                }
                else if (temp.starts_with("PC:"))
                {
                    user.postal_code = temp;
                }
                else
                {
                    data.push_back(user);
                }
            }

            for (User print : data)
            {
                clean_print(print);
            }

            break;

        case 2:

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter the name\n";
            std::getline(std::cin, user.name);

            std::cout << "Enter the surname\n";
            std::getline(std::cin, user.surname);

            std::cout << "Enter the phone number\n";
            std::getline(std::cin, user.phone_num);

            std::cout << "Enter the adress\n";
            std::getline(std::cin, user.adress);

            std::cout << "Enter the postal code\n";
            std::getline(std::cin, user.postal_code);

            /* ofile << "N:" << user.name << '\n';
             ofile << "S:" << user.surname << '\n';
             ofile << "PN:" << user.phone_num << '\n';
             ofile << "A:" << user.adress << '\n';
             ofile << "PC:" << user.postal_code << '\n';
             ofile << "E\n";
             ofile.close();
             */
            trim(user);

            to_lower(user);

            file_output(user);

            break;

        case 3:

            std::cout << "Enter the information of the user you want to delete.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::getline(std::cin, temp);

            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

            std::cout << temp << '\n';

            break;

        case 4:

            break;

        case 6:

            ifile.close();
            ofile.close();
            ofile.open("adressbook.txt", std::ios::out | std::ios::trunc);
            ofile.close();

            break;

        default:
            ifile.close();
            ofile.close();
            break;
        }
    }

    return 0;
}
