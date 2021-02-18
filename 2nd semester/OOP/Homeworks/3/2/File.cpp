#include <iostream> 
#include <string>
#include <chrono>
#include <ctime> 
#include "File.h"

using namespace std;

File::File(){
	time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
	string tempDate = ctime(&time);
	tempDate.erase(tempDate.length() - 1);
	this->setDate(tempDate); //sets current date
	this->setSizeInMB(0);
	this->folder = nullptr;
}

File::File(const string& _name, double _sizeInMB, const string& _extension){
	this->folder = nullptr;
	this->setName(_name);
	time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
	string tempDate = ctime(&time);
	tempDate.erase(tempDate.length() - 1);
	this->setDate(tempDate); //sets current date
	this->setSizeInMB(_sizeInMB);
	this->setExtension(_extension);
}

File::File(const File& other){
	this->setName(other.getName());
	this->setDate(other.getDate());
	this->setSizeInMB(other.getSizeInMB());
	this->setExtension(other.getExtension());
}

File& File::operator=(const File& other){
	if(this == &other){
		return *this;
	}

	this->setName(other.getName());
	this->setDate(other.getDate());
	this->setSizeInMB(other.getSizeInMB());
	this->setExtension(other.getExtension());

	return *this;
}

File::~File(){

}

void File::setName(const string& _name){  //checks if there's a file with the same name and extension
	if(this->folder == nullptr){
		this->name = _name;
	} else{
		if(this->folder->getFileInCurrentFolderByName(_name).size() == 0){
			this->name = _name;
			return;
		}
		vector<File*> files = this->folder->getFileInCurrentFolderByName(_name);
		for(int i = 0; i < files.size(); i++){
			string newName = _name;
			if(newName.append(this->getExtension()) == files[i]->getName().append(files[i]->getExtension())){
				cout << "There already is a file with that name and extension" << endl;
				return;
			}
		}
		this->name = _name;
	}
}

string File::getName() const{
	return this->name;
}

void File::setDate(const string& _date){
	this->date = _date;
}

string File::getDate() const{
	return this->date;
}

void File::setSizeInMB(double _sizeInMB){
	this->sizeInMB = _sizeInMB;
}

double File::getSizeInMB() const{
	return this->sizeInMB;
}

void File::setFolder(Folder* _folder){  //checks if there's a file with the same name and extension in the folder, which is being set
	if(_folder->getFileInCurrentFolderByName(this->getName()).size() == 0){
		this->folder = _folder;
		return;
	} 
	vector<File*> files = _folder->getFileInCurrentFolderByName(this->getName());
	for(int i = 0; i < files.size(); i++){
		if(this->getName().append(this->getExtension()) == files[i]->getName().append(files[i]->getExtension())){
			cout << "There already is a file with that name and extension" << endl;
			return;
		}
	}
	this->folder = _folder;
}

Folder* File::getFolder() const{
	return this->folder;
}

void File::setExtension(const string& _extension){  //checks if there's a file with the same name and extension
	if(this->folder == nullptr){
		this->extension = _extension;
	} else{
		if(this->folder->getFileInCurrentFolderByName(this->getName()).size() == 0){
			this->extension = _extension;
			return;
		}
		vector<File*> files = this->folder->getFileInCurrentFolderByName(this->getName());
		for(int i = 0; i < files.size(); i++){
			string nexExtension = _extension;
			if(this->getName().append(nexExtension) == files[i]->getName().append(files[i]->getExtension())){
				cout << "There already is a file with that name and extension" << endl;
				return;
			}
		}
		this->extension = _extension;
	}
}

string File::getExtension() const{
	return this->extension;
}

void File::print() const{
	cout << "file: " << this->getName() << this->getExtension() << ", created on " << this->getDate() << ", size on disk: " << this->getSizeInMB() << "MB";
}
