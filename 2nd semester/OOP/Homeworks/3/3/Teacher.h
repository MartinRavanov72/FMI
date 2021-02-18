#pragma once
#include <iostream> 
#include <string>
#include <utility>
#include <vector>

using namespace std;


enum Title{
	honoured, doctor, professor, chief_assistant, associate_professor
};

class Course;

class Teacher{
	private:
	string name;
	Title title;
	vector<Course> courses;
	public:
	Teacher();

	Teacher(const string& _name, const Title _title, const vector<Course>& _courses);

	Teacher(const Teacher& other);

	Teacher& operator=(const Teacher& other);

	~Teacher();

	void setName(const string& _name);
	string getName() const;
	void setTitle(const Title _title);
	Title getTitle() const;
	void setCourses(const vector<Course>& _courses);
	vector<Course> getCourses() const;
	void print() const;
};