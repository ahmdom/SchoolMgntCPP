/*New Mgnt Student Class*/
#include "mgntstudent.hpp"
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "student.hpp"

using json = nlohmann::json;

    void MgntStudent::addStudent() {

        std::ifstream inFile("students.json");
        json students;

        if (inFile.is_open()) {
            inFile >> students;
        } else {
            students = json::array();
        }

    inFile.close();

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

        std::ofstream outFile("students.json");
        outFile << students.dump(4);
        outFile.close();
    }

    void MgntStudent::deleteStudent() {
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
                    studentDeleted = true;
                    break;
                }
            }

            if (studentDeleted) {
                std::cout << "Student " << nameToDelete << " deleted successfully." << std::endl;
            } else {
                std::cout << "Student " << nameToDelete << " not found." << std::endl;
            }
        }
    }




