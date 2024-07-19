#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <nlohmann/json.hpp>

class Student {
public:
    Student(const std::string& name, int age, const std::string& grade);

    nlohmann::json toJson() const;

private:
    std::string name;
    int age;
    std::string grade;
};

#endif
