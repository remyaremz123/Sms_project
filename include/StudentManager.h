#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "IStudentManager.h"

#include <vector>

class StudentManager : public IStudentManager
{
public:
	bool addStudent(const Student& student) override;
	void displayStudents() const;
	const Student* findStudentById(int studentId) const;
	double calculateAverageMarks() const;
	const Student* findTopStudent() const;
	bool isEmpty() const;

private:
	std::vector<Student> students;
};

#endif