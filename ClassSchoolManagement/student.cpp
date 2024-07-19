#include "student.hpp"

Student::Student(const std::string& name, int age, const std::string& grade)
    : name(name), age(age), grade(grade) {}

nlohmann::json Student::toJson() const {
    return nlohmann::json{{"name", name}, {"age", age}, {"grade", grade}};
}
