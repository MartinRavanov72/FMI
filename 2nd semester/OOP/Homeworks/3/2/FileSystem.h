#pragma once
#include <iostream> 
#include <string>
#include "Folder.h"
#include "Content.h"

using namespace std;


class FileSystem{
	private:
	Folder* mainFolder;
	public:
	FileSystem(){

	}

	FileSystem(Folder* _mainFolder){
		this->setMainFolder(_mainFolder);
	}

	FileSystem(const FileSystem& other){
		this->setMainFolder(other.getMainFolder());
	}

	FileSystem& operator=(const FileSystem& other){
		if(this == &other){
			return *this;
		}

		this->setMainFolder(other.getMainFolder());

		return *this;
	}

	~FileSystem(){

	}

	void setMainFolder(Folder* _mainFolder){
		this->mainFolder = _mainFolder;
	}

	Folder* getMainFolder() const{
		return this->mainFolder;
	}

	vector<File*> getFileByName(const string& _name) const{
		return this->getMainFolder()->getFileByName(_name);
	}

	void createFile(File* file, const string& path){
		int pos = 0;
		string location = path;
		vector<string> tokens;
		while((pos = location.find("/")) != string::npos){  // split the string
			tokens.push_back(location.substr(0, pos));
			location.erase(0, pos + 1);
		}
		tokens.push_back(location);
		if(tokens.size() == 0){
			throw invalid_argument("Invalid path!");
		} else if(tokens[0] != this->mainFolder->getName()){ //starts the function only if the first part of the path is correct
			throw invalid_argument("Invalid path!");
		}
		this->getMainFolder()->createFile(file, path);
	}

	void print() const{
		this->getMainFolder()->print();
	}
};