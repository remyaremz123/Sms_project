#include "StudentEntry.h"
#include "mocks/MockStudentManager.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sstream>

using ::testing::Return;
using ::testing::Truly;

TEST(StudentEntryTests, ReportsSuccessfulAdd)
{
	MockStudentManager manager;
	std::istringstream input("12\nMina Lee\n88.5\n");
	std::ostringstream output;

	EXPECT_CALL(manager, addStudent(Truly([](const Student& student) {
		return student.getStudentId() == 12
			&& student.getName() == "Mina Lee"
			&& student.getMarks() == 88.5;
	}))).WillOnce(Return(true));

	addStudent(manager, input, output);

	EXPECT_NE(output.str().find("Student added.\n"), std::string::npos);
}

TEST(StudentEntryTests, ReportsDuplicateIdWhenAddFails)
{
	MockStudentManager manager;
	std::istringstream input("12\nMina Lee\n88.5\n");
	std::ostringstream output;

	EXPECT_CALL(manager, addStudent(::testing::_)).WillOnce(Return(false));

	addStudent(manager, input, output);

	EXPECT_NE(output.str().find(
		"A student with that ID already exists.\n"), std::string::npos);
}