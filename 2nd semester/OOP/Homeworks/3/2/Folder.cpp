#include "Folder.h"
#include "File.h"
#include <chrono>
#include <ctime> 

Folder::Folder(){
	time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
	string tempDate = ctime(&time);
	tempDate.erase(tempDate.length() - 1);
	this->setDate(tempDate); //sets the current date
	this->folder = nullptr;
}

Folder::Folder(const string & _name, const vector<Content*>& _contnent){
	this->folder = nullptr;
	this->setName(_name);
	time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
	string tempDate = ctime(&time);
	tempDate.erase(tempDate.length() - 1);
	this->setDate(tempDate); //sets the current date
	this->setContent(_contnent);
}

Folder::Folder(const Folder & other){
	this->setName(other.getName());
	this->setDate(other.getDate());
	this->setContent(other.getContent());
}

Folder & Folder::operator=(const Folder & other){
	if(this == &other){
		return *this;
	}

	this->setName(other.getName());
	this->setDate(other.getDate());
	this->setContent(other.getContent());

	return *this;
}

 Folder::~Folder(){

}

void Folder::setName(const string & _name){ //checks if there's a folder with the same name in its location
	if(this->folder == nullptr){
		this->name = _name;
	} else{
		if(this->folder->getFolderInCurrentFolderByName(_name) == nullptr){
			this->name = _name;
			return;
		}
		cout << "There already is a folder with that name" << endl;
		return;
	}
}

string Folder::getName() const{
	return this->name;
}

void Folder::setDate(const string & _date){
	this->date = _date;
}

string Folder::getDate() const{
	return this->date;
}

void Folder::setContent(const vector<Content*>& _content){
	this->content = _content;
}

vector<Content*> Folder::getContent() const{
	return this->content;
}

void Folder::setFolder(Folder* _folder){  //checks if the folder which is being set contains a folder with the same name
	if(_folder->getFolderInCurrentFolderByName(this->getName()) == nullptr){
		this->folder = _folder;
		return;
	}
	cout << "There already is a folder with that name" << endl;
	return;
}

Folder* Folder::getFolder() const{
	return this->folder;
}

void Folder::addFolder(Folder * _element){ //add folder, only if there isn't one with the same name
	int length = this->getContent().size();
	for(int i = 0; i < length; i++){
		Folder* folderP = dynamic_cast<Folder*>(this->getContent()[i]);
		if(folderP != NULL){
			if(_element->getName() == folderP->getName()){
				cout << "There already is a folder with that name" << endl;
				return;
			}
		}
	}

	_element->setFolder(this);
	this->content.push_back(_element);
}

void Folder::addFile(File * _element){ //add file, only if there isn't one with the same name and extension
	int length = this->getContent().size();
	for(int i = 0; i < length; i++){
		File* fileP = dynamic_cast<File*>(this->getContent()[i]);
		if(fileP != NULL){
			if(_element->getName().append(_element->getExtension()) == fileP->getName().append(fileP->getExtension())){
				cout << "There already is a file with that name and extension" << endl;
				return;
			}
		}
	}

	_element->setFolder(this);
	this->content.push_back(_element);
}

vector<File*> Folder::getFileByName(const string& _name) const{ //returns all the files in the folder and all of its content with this name
	int length = this->getContent().size();
	vector<File*> result;
	return this->getFileByName(_name, result);
}

vector<File*> Folder::getFileByName(const string& _name, vector<File*>& result) const{  //helper, to execute recursion
	int length = this->getContent().size();
	for(int i = 0; i < length; i++){
		File* fileP = dynamic_cast<File*>(this->getContent()[i]);
		if(fileP != NULL){
			if(_name == fileP->getName()){
				result.push_back(fileP);
			}
		} else{
			Folder* folderP = dynamic_cast<Folder*>(this->getContent()[i]);
			folderP->getFileByName(_name, result);
		}
	}

	return result;
}

Folder* Folder::getFolderInCurrentFolderByName(const string& _name) const{ //returns folder(or nullptr) with this name, but only in the current folder
	int length = this->getContent().size();
	for(int i = 0; i < length; i++){
		Folder* folderP = dynamic_cast<Folder*>(this->getContent()[i]);
		if(folderP != NULL){
			if(_name == folderP->getName()){
				return folderP;
			}
		}
	}

	return nullptr;
}

vector<File*> Folder::getFileInCurrentFolderByName(const string& _name) const{  //returns all the files with this name, but only in the current folder
	int length = this->getContent().size();
	vector<File*> result;
	return this->getFileInCurrentFolderByName(_name, result);
}

vector<File*> Folder::getFileInCurrentFolderByName(const string& _name, vector<File*>& result) const{ //helper, to execute recursion
	int length = this->getContent().size();
	for(int i = 0; i < length; i++){
		File* fileP = dynamic_cast<File*>(this->getContent()[i]);
		if(fileP != NULL){
			if(_name == fileP->getName()){
				result.push_back(fileP);
			}
		}
	}

	return result;
}

void Folder::createFile(File* file, const string& path){ //creates file, only if the given path is valid
	int pos = 0;
	string location = path;
	vector<string> tokens;
	while((pos = location.find("/")) != string::npos){  // split the string
		tokens.push_back(location.substr(0, pos));
		location.erase(0, pos + 1);
	}
	tokens.push_back(location);

	if(tokens.size() == 1){ //bottom of recursion
		this->addFile(file);
		return;
	}
	if(this->getFolderInCurrentFolderByName(tokens[1]) == nullptr){ //there isn't a folder with the given name in the current folder
		throw invalid_argument("Invalid path!");
	} else{
		string remainingLocation;
		for(int j = 1; j < tokens.size(); j++){ // continue with relative path
			if(j == tokens.size() - 1){
				remainingLocation.append(tokens[j]);
			} else{
				remainingLocation.append(tokens[j]).append("/");
			}
		}
		this->getFolderInCurrentFolderByName(tokens[1])->createFile(file, remainingLocation); //resume with recursion
	}
}

void Folder::print() const{ //prints all of the folder's content
	this->print(1);
	cout << endl;
}

void Folder::print(int tabs) const{ //helper, to execute the recursion with the valid tabs
	int length = this->content.size();
	cout << "folder: " << this->getName() << ", created on " << this->getDate() << endl;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < tabs; j++){
			cout << '\t';
		}
		Folder* folderP = dynamic_cast<Folder*>(this->content[i]);
		if(folderP != NULL){
			folderP->print(tabs + 1);
		} else{
			this->content[i]->print();
			cout << endl << endl;
		}
	}
}
