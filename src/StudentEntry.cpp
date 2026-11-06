#include "StudentEntry.h"

#include <cmath>
#include <iostream>
#include <sstream>

namespace
{
bool readMarks(std::istream& input, std::ostream& output, double& marks)
{
	while (true)
	{
		output << "Marks (0-100): ";
		std::string line;
		if (!std::getline(input, line))
		{
			return false;
		}

		std::istringstream valueInput(line);
		char extraCharacter;
		if (valueInput >> marks && std::isfinite(marks)
			&& !(valueInput >> extraCharacter))
		{
			if (marks >= 0.0 && marks <= 100.0)
			{
				return true;
			}
		}

		output << "Enter a valid mark from 0 to 100.\n";
	}
}
}

bool readInteger(const std::string& prompt, int& value)
{
	return readInteger(prompt, value, std::cin, std::cout);
}

bool readInteger(const std::string& prompt, int& value,
	std::istream& input, std::ostream& output)
{
	while (true)
	{
		output << prompt;
		std::string line;
		if (!std::getline(input, line))
		{
			return false;
		}

		std::istringstream valueInput(line);
		char extraCharacter;
		if (valueInput >> value && !(valueInput >> extraCharacter))
		{
			return true;
		}

		output << "Please enter a whole number.\n";
	}
}

void addStudent(IStudentManager& manager)
{
	addStudent(manager, std::cin, std::cout);
}

void addStudent(IStudentManager& manager,
	std::istream& input, std::ostream& output)
{
	int studentId;
	if (!readInteger("Student ID: ", studentId, input, output))
	{
		return;
	}
	if (studentId <= 0)
	{
		output << "Student ID must be positive.\n";
		return;
	}

	output << "Student name: ";
	std::string name;
	if (!std::getline(input, name))
	{
		return;
	}
	if (name.find_first_not_of(" \t") == std::string::npos)
	{
		output << "Student name cannot be empty.\n";
		return;
	}

	double marks;
	if (!readMarks(input, output, marks))
	{
		return;
	}

	const Student student(studentId, name, marks);
	if (manager.addStudent(student))
	{
		output << "Student added.\n";
	}
	else
	{
		output << "A student with that ID already exists.\n";
	}
}