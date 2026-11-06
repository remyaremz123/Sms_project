#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
	Student(int studentId, const std::string& name, double marks);

	int getStudentId() const;
	const std::string& getName() const;
	double getMarks() const;
	void display() const;

private:
	int studentId;
	std::string name;
	double marks;
};

#endif