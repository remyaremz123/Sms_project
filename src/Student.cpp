#include "Student.h"

#include <iostream>

Student::Student(int studentId, const std::string& name, double marks)
	: studentId(studentId), name(name), marks(marks)
{
}

int Student::getStudentId() const
{
	return studentId;
}

const std::string& Student::getName() const
{
	return name;
}

double Student::getMarks() const
{
	return marks;
}

void Student::display() const
{
	std::cout << "Student ID: " << studentId << '\n';
	std::cout << "Name: " << name << '\n';
	std::cout << "Marks: " << marks << '\n';
}