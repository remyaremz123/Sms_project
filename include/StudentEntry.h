#ifndef STUDENT_ENTRY_H
#define STUDENT_ENTRY_H

#include "IStudentManager.h"

#include <iosfwd>
#include <string>

bool readInteger(const std::string& prompt, int& value);
bool readInteger(const std::string& prompt, int& value,
	std::istream& input, std::ostream& output);

void addStudent(IStudentManager& manager);
void addStudent(IStudentManager& manager,
	std::istream& input, std::ostream& output);

#endif