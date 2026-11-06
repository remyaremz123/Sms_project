#include "Student.h"
#include "StudentEntry.h"
#include "StudentManager.h"

#include <iostream>

void findStudent(const StudentManager& manager)
{
	if (manager.isEmpty())
	{
		std::cout << "No students in the list.\n";
		return;
	}

	int studentId;
	if (!readInteger("Enter student ID: ", studentId))
	{
		return;
	}

	const Student* student = manager.findStudentById(studentId);
	if (student == nullptr)
	{
		std::cout << "Student not found.\n";
		return;
	}

	std::cout << "Student name: " << student->getName() << '\n';
	student->display();
}

void displayTopStudent(const StudentManager& manager)
{
	const Student* student = manager.findTopStudent();
	if (student == nullptr)
	{
		std::cout << "No students in the list.\n";
		return;
	}

	std::cout << "Top student:\n";
	student->display();
}

void displayMenu()
{
	std::cout << "\nStudent Manager\n"
		<< "1. Add student\n"
		<< "2. Display all students\n"
		<< "3. Find student by ID\n"
		<< "4. Calculate average marks\n"
		<< "5. Find top student\n"
		<< "0. Exit\n";
}

int main()
{
	StudentManager manager;
	bool running = true;

	while (running)
	{
		displayMenu();
		int choice;
		if (!readInteger("Choose an option: ", choice))
		{
			break;
		}

		switch (choice)
		{
		case 1:
			addStudent(manager);
			break;
		case 2:
			manager.displayStudents();
			break;
		case 3:
			findStudent(manager);
			break;
		case 4:
			if (manager.isEmpty())
			{
				std::cout << "No students in the list.\n";
			}
			else
			{
				std::cout << "Average marks: "
					<< manager.calculateAverageMarks() << '\n';
			}
			break;
		case 5:
			displayTopStudent(manager);
			break;
		case 0:
			running = false;
			break;
		default:
			std::cout << "Choose a menu option from 0 to 5.\n";
		}
	}

	std::cout << "Goodbye.\n";
	return 0;
}