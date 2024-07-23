/*Managment Student hpp*/
#ifndef MNGTSTUDENT_HPP
#define MNGTSTUDENT_HPP

#include "nlohmann/json.hpp"
#include "student.hpp"


using json = nlohmann::json;

class MgntStudent {
private:
    json students;

public:
    void addStudent();
    void deleteStudent();
};


#endif
