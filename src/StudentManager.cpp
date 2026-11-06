#include "StudentManager.h"

#include <iostream>

bool StudentManager::addStudent(const Student& student)
{
	if (findStudentById(student.getStudentId()) != nullptr)
	{
		return false;
	}

	students.push_back(student);
	return true;
}

void StudentManager::displayStudents() const
{
	if (isEmpty())
	{
		std::cout << "No students in the list.\n";
		return;
	}

	for (const Student& student : students)
	{
		student.display();
		std::cout << '\n';
	}
}

const Student* StudentManager::findStudentById(int studentId) const
{
	for (const Student& student : students)
	{
		if (student.getStudentId() == studentId)
		{
			return &student;
		}
	}

	return nullptr;
}

double StudentManager::calculateAverageMarks() const
{
	if (isEmpty())
	{
		return 0.0;
	}

	long double totalMarks = 0.0;
	for (const Student& student : students)
	{
		totalMarks += student.getMarks();
	}

	return static_cast<double>(totalMarks / students.size());
}

const Student* StudentManager::findTopStudent() const
{
	if (isEmpty())
	{
		return nullptr;
	}

	const Student* topStudent = &students.front();
	for (const Student& student : students)
	{
		if (student.getMarks() > topStudent->getMarks())
		{
			topStudent = &student;
		}
	}

	return topStudent;
}

bool StudentManager::isEmpty() const
{
	return students.empty();
}