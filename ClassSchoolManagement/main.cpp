#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "student.hpp"
#include "mgntstudent.hpp"



using json = nlohmann::json;

MgntStudent mgntStudent;

int main() {


    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Delete Student" << std::endl;
        std::cout << "Enter your choice (1 or 2): ";
        std::cin >> choice;

        if (choice == 1) {
            mgntStudent.addStudent();
            std::cout << "Student added successfully!" << std::endl;
            break;
        } else if (choice == 2) {
            mgntStudent.deleteStudent();
            std::cout << "Student delete successfully!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }



    
    return 0;
}
