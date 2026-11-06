#ifndef I_STUDENT_MANAGER_H
#define I_STUDENT_MANAGER_H

#include "Student.h"

class IStudentManager
{
public:
	virtual ~IStudentManager() = default;
	virtual bool addStudent(const Student& student) = 0;
};

#endif