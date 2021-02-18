#pragma once
#include <iostream> 
#include <string>
#include "Content.h"
#include "Folder.h"

using namespace std;

 
class File : public Content{
	private:
	string name;
	string date;
	double sizeInMB;
	Folder* folder = nullptr;
	protected:
	string extension;
	public:
	File();

	File(const string& _name, double _sizeInMB, const string& _extension);

	File(const File& other);

	File& operator=(const File& other);

	~File();

	void setName(const string& _name);
	string getName() const;
	void setDate(const string& _date);
	string getDate() const;
	void setSizeInMB(double _sizeInMB);
	double getSizeInMB() const;
	void setFolder(Folder* _folder);
	Folder* getFolder() const;
	void setExtension(const string& _extension);
	string getExtension() const;

	void print() const override;
};