#pragma once
#include <iostream> 
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"


using namespace std;

class Course{
	private:
	string name;
	string type;
	int code;
	Teacher teacher;
	vector<Student> enrolledStudents;
	public:
	Course();

	Course(const string& _name, const string& _type, int _code, const Teacher& _teacher, const vector<Student>& _enrolledStudents);

	Course(const Course& other);

	Course& operator=(const Course& other);

	~Course();

	void setName(const string& _name);
	string getName() const;
	void setType(const string& _type);
	string getType() const;
	void setCode(int _code);
	int getCode() const;
	void setTeacher(const Teacher& _teacher);
	Teacher getTeacher() const;
	void setEnrolledStudents(const vector<Student>& _enrolledStudents);
	vector<Student> getEnrolledStudents() const;
	void print() const;
};