#pragma once
#include <iostream> 
#include <string>
#include <utility>
#include <vector>

using namespace std;


class Course;

class Student{
	private:
	string name;
	int FN;
	vector<Course> coursesTaken;
	vector<pair<Course, double>> courseGrades;
	public:
	Student();

	Student(const string& _name, int _FN, const vector<Course>& _coursesTaken, const vector<pair<Course, double>>& _courseGrades);

	Student(const Student& other);

	Student& operator=(const Student& other);

	~Student();

	void setName(const string& _name);
	string getName() const;
	void setFN(int _FN);
	int getFN() const;
	void setCoursesTaken(const vector<Course>& _coursesTaken);
	vector<Course> getCoursesTaken() const;
	void setCourseGrades(const vector<pair<Course, double>>& _courseGrades);
	vector<pair<Course, double>> getCourseGrades() const;
	void print() const;
};