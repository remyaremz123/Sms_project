#include "StudentEntry.h"
#include "StudentManager.h"
#include "mocks/MockStudentManager.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sstream>
#include <string>

using ::testing::Return;
using ::testing::StrictMock;
using ::testing::Truly;

TEST(StudentEntryMockTests, AddsValidStudentWhenManagerAccepts)
{
	StrictMock<MockStudentManager> manager;
	std::istringstream input("12\nMina Lee\n88.5\n");
	std::ostringstream output;

	EXPECT_CALL(manager, addStudent(Truly([](const Student& student) {
		return student.getStudentId() == 12
			&& student.getName() == "Mina Lee"
			&& student.getMarks() == 88.5;
	}))).Times(1).WillOnce(Return(true));

	addStudent(manager, input, output);

	EXPECT_NE(output.str().find("Student added.\n"), std::string::npos);
}

TEST(StudentEntryMockTests, ReportsDuplicateMessageWhenManagerRejects)
{
	StrictMock<MockStudentManager> manager;
	std::istringstream input("12\nMina Lee\n88.5\n");
	std::ostringstream output;

	EXPECT_CALL(manager, addStudent(::testing::_))
		.Times(1)
		.WillOnce(Return(false));

	addStudent(manager, input, output);

	EXPECT_NE(output.str().find(
		"A student with that ID already exists.\n"), std::string::npos);
}

TEST(StudentEntryMockTests, DoesNotCallManagerForNonPositiveId)
{
	StrictMock<MockStudentManager> manager;
	std::istringstream input("0\n");
	std::ostringstream output;

	EXPECT_CALL(manager, addStudent(::testing::_)).Times(0);

	addStudent(manager, input, output);

	EXPECT_NE(output.str().find("Student ID must be positive.\n"),
		std::string::npos);
}

TEST(StudentEntryMockTests, CallsManagerOnceAfterInvalidMarksAreRetried)
{
	StrictMock<MockStudentManager> manager;
	std::istringstream input("12\nMina Lee\n101\n88.5\n");
	std::ostringstream output;

	EXPECT_CALL(manager, addStudent(Truly([](const Student& student) {
		return student.getStudentId() == 12
			&& student.getName() == "Mina Lee"
			&& student.getMarks() == 88.5;
	}))).Times(1).WillOnce(Return(true));

	addStudent(manager, input, output);

	EXPECT_NE(output.str().find(
		"Enter a valid mark from 0 to 100.\n"), std::string::npos);
}

TEST(StudentEntryMockTests, RejectsDuplicateIdAndKeepsOriginalStudent)
{
	StudentManager manager;
	const Student original(12, "Mina Lee", 88.5);

	ASSERT_TRUE(manager.addStudent(original));
	EXPECT_FALSE(manager.addStudent(Student(12, "Other Name", 40.0)));

	const Student* found = manager.findStudentById(12);
	ASSERT_NE(found, nullptr);
	EXPECT_EQ(found->getName(), "Mina Lee");
	EXPECT_DOUBLE_EQ(found->getMarks(), 88.5);
}