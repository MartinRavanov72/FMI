#pragma once
#include <iostream> 
#include <string>
#include "Content.h"
#include <vector>

using namespace std;


class File;

class Folder : public Content{
	private:
	string name;
	string date;
	vector<Content*> content;
	Folder* folder = nullptr;

	vector<File*> getFileByName(const string& _name, vector<File*>& result) const;
	vector<File*> getFileInCurrentFolderByName(const string& _name, vector<File*>& result) const;

	void print(int tabs) const;
	public:
	Folder();

	Folder(const string& _name, const vector<Content*>& _contnent);

	Folder(const Folder& other);

	Folder& operator=(const Folder& other);

	~Folder();

	void setName(const string& _name);
	string getName() const;
	void setDate(const string& _date);
	string getDate() const;
	void setContent(const vector<Content*>& _content);
	vector<Content*> getContent() const;
	void setFolder(Folder* _folder);
	Folder* getFolder() const;

	void addFolder(Folder* _element);
	void addFile(File* _element);
	vector<File*> getFileByName(const string& _name) const;
	Folder* getFolderInCurrentFolderByName(const string& location) const;
	vector<File*> getFileInCurrentFolderByName(const string& _name) const;
	void createFile(File* file, const string& location);
	void print() const override;
};