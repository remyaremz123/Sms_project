#ifndef MOCK_STUDENT_MANAGER_H
#define MOCK_STUDENT_MANAGER_H

#include "IStudentManager.h"

#include <gmock/gmock.h>

class MockStudentManager : public IStudentManager
{
public:
	MOCK_METHOD(bool, addStudent, (const Student& student), (override));
};

#endif