#include "StudentManager.h"

#include <gtest/gtest.h>

TEST(StudentManagerTests, StartsEmpty)
{
	const StudentManager manager;

	EXPECT_TRUE(manager.isEmpty());
	EXPECT_DOUBLE_EQ(manager.calculateAverageMarks(), 0.0);
	EXPECT_EQ(manager.findStudentById(1), nullptr);
	EXPECT_EQ(manager.findTopStudent(), nullptr);
}

TEST(StudentManagerTests, AddsStudentAndFindsItById)
{
	StudentManager manager;
	ASSERT_TRUE(manager.addStudent(Student(12, "Mina Lee", 88.5)));

	const Student* found = manager.findStudentById(12);
	ASSERT_NE(found, nullptr);
	EXPECT_EQ(found->getName(), "Mina Lee");
	EXPECT_DOUBLE_EQ(found->getMarks(), 88.5);
}

TEST(StudentManagerTests, RejectsDuplicateStudentIds)
{
	StudentManager manager;
	ASSERT_TRUE(manager.addStudent(Student(12, "Mina Lee", 88.5)));

	EXPECT_FALSE(manager.addStudent(Student(12, "Different Name", 40.0)));
	EXPECT_EQ(manager.findStudentById(12)->getName(), "Mina Lee");
}

TEST(StudentManagerTests, ReturnsNullptrForMissingId)
{
	StudentManager manager;
	ASSERT_TRUE(manager.addStudent(Student(12, "Mina Lee", 88.5)));

	EXPECT_EQ(manager.findStudentById(99), nullptr);
}

TEST(StudentManagerTests, CalculatesAverageMarks)
{
	StudentManager manager;
	ASSERT_TRUE(manager.addStudent(Student(1, "A", 60.0)));
	ASSERT_TRUE(manager.addStudent(Student(2, "B", 80.0)));
	ASSERT_TRUE(manager.addStudent(Student(3, "C", 100.0)));

	EXPECT_DOUBLE_EQ(manager.calculateAverageMarks(), 80.0);
}

TEST(StudentManagerTests, FindsTopStudent)
{
	StudentManager manager;
	ASSERT_TRUE(manager.addStudent(Student(1, "A", 70.0)));
	ASSERT_TRUE(manager.addStudent(Student(2, "B", 95.0)));
	ASSERT_TRUE(manager.addStudent(Student(3, "C", 80.0)));

	const Student* topStudent = manager.findTopStudent();
	ASSERT_NE(topStudent, nullptr);
	EXPECT_EQ(topStudent->getStudentId(), 2);
}