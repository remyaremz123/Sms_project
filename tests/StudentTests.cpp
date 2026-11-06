#include "Student.h"

#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

TEST(StudentTests, ConstructorAndGettersPreserveValues)
{
	const Student student(12, "Mina Lee", 88.5);

	EXPECT_EQ(student.getStudentId(), 12);
	EXPECT_EQ(student.getName(), "Mina Lee");
	EXPECT_DOUBLE_EQ(student.getMarks(), 88.5);
}

TEST(StudentTests, DisplayWritesAllFields)
{
	const Student student(7, "Ada Lovelace", 91.5);
	std::ostringstream output;
	std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

	student.display();

	std::cout.rdbuf(originalBuffer);
	EXPECT_EQ(output.str(),
		"Student ID: 7\nName: Ada Lovelace\nMarks: 91.5\n");
}