                    /************************************************************
                    *   Author: Radwa Mahmoud                                   *
                    *   Date  : 17/9/2023                                       *
                    *   Task  : Address Book Program                            *
                    ************************************************************/

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>


int main()
{
    int choice = 0;
    std::vector<std::string> UserNames= {"Radwa", "Khadija", "Esraa", "Gehad", "Samya"};
    while (1)
    {
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1- List.....2- Add.....3- delete user.....4- delete all users.....5- Search.....6- Close...." << std::endl;
    std::cin >> choice;
    if (choice == 6) {
        break;
    }
    else {
        switch (choice) {
        case 1:
            std::cout << "List of users: " << std::endl;
            if (UserNames.empty())
            {
                std::cout << "No users" << std::endl;
            }
            else{
            for ( std::string i : UserNames)
            {
                std::cout << i << std::endl;
            }
            }
        break;

        case 2:
        {
            std::string user;
            std::cout << "Enter the user name: " << std::endl;
            std::cin >> user;
            UserNames.push_back(user);       
        }
        break;

        case 3:
        {
            std::string user;
            std::cout << "Enter the user name: " << std::endl;
            std::cin >> user;
            UserNames.erase(std::find(UserNames.begin(), UserNames.end(),user));
        }
        break;

        case 4:
            UserNames.clear();
        break;

        case 5:
        {
            std::string user;
            std::cout << "Enter the user name: " << std::endl;
            std::cin >> user;
            if(std::find(UserNames.begin(), UserNames.end(),user)==UserNames.end())
            {
                std::cout << "User not found" << std::endl;
            }
            else {
                std::cout << "User found" << std::endl;
            }
        }
        break;
    }
    }
    }
}