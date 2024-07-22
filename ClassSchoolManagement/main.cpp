#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "student.hpp"

/*Token Github*/
/*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*/

using json = nlohmann::json;

void addStudent(json& students) {
    std::string name;
    int age;
    std::string grade;

    std::cout << "Enter student name: ";
    std::cin.ignore(); // To clear the newline character left by previous input
    std::getline(std::cin, name);

    std::cout << "Enter student age: ";
    std::cin >> age;

    std::cout << "Enter student grade: ";
    std::cin.ignore();
    std::getline(std::cin, grade);

    Student newStudent(name, age, grade);
    students.push_back(newStudent.toJson());
}
void deleteStudent(json& students) {
    std::string name;
    std::cout << "Enter the name of the student to delete: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "List of students:" << std::endl;

    for (const auto& student : students) {
        std::cout << student["name"] << std::endl;
    }

    int menuChoice;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> menuChoice;

    if (menuChoice == 1) {
        // Display the list of student names
        for (const auto& student : students) {
            std::cout << student["name"] << std::endl;
        }
    } else if (menuChoice == 2) {
        // Delete a student by name
        std::string nameToDelete;
        std::cout << "Enter the name of the student to delete: ";
        std::cin.ignore();
        std::getline(std::cin, nameToDelete);

        bool studentDeleted = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)["name"] == nameToDelete) {
                students.erase(it);
                std::cout << "Student deleted successfully!" << std::endl;
                studentDeleted = true;
                break;
            }
        }

        if (!studentDeleted) {
            std::cout << "Student not found!" << std::endl;
        }
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)["name"] == name) {
            students.erase(it);
            std::cout << "Student deleted successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Student not found!" << std::endl;
}

int main() {
    std::ifstream inFile("students.json");
    json students;

    if (inFile.is_open()) {
        inFile >> students;
    } else {
        students = json::array();
    }

    inFile.close();

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Delete Student" << std::endl;
        std::cout << "Enter your choice (1 or 2): ";
        std::cin >> choice;

        if (choice == 1) {
            addStudent(students);
            std::cout << "Student added successfully!" << std::endl;
            break;
        } else if (choice == 2) {
            deleteStudent(students);
            std::cout << "Student delete successfully!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::ofstream outFile("students.json");
    outFile << students.dump(4);
    outFile.close();

    
    return 0;
}
