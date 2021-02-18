#include "MusicFile.h"

MusicFile::MusicFile() : File(){}

MusicFile::MusicFile(const string & _name, double _sizeInMB, const string & _extension, const string & _nameOfArtist, const string & _songName, int _year) : File(_name, _sizeInMB, _extension){
	if(_extension != ".mp3" && _extension != ".flac"){
		this->extension = "";
		throw invalid_argument("Invalid extenstion!");
	}
	this->setNameOfArtist(_nameOfArtist);
	this->setSongName(_songName);
	this->setYear(_year);
	this->setName(this->getNameOfArtist() + " - " + this->getSongName());
}

MusicFile::MusicFile(const MusicFile & other) : File(other){
	this->setNameOfArtist(other.getNameOfArtist());
	this->setSongName(other.getSongName());
	this->setYear(other.getYear());
}

MusicFile & MusicFile::operator=(const MusicFile & other){
	if(this == &other){
		return *this;
	}

	File::operator =(other);

	this->setNameOfArtist(other.getNameOfArtist());
	this->setSongName(other.getSongName());
	this->setYear(other.getYear());

	return *this;
}

MusicFile::~MusicFile(){}

void MusicFile::setNameOfArtist(const string & _nameOfArtist){
	this->nameOfArtist = _nameOfArtist;
}

string MusicFile::getNameOfArtist() const{
	return this->nameOfArtist;
}

void MusicFile::setSongName(const string & _songName){
	this->songName = _songName;
}

string MusicFile::getSongName() const{
	return this->songName;
}

void MusicFile::setYear(int _year){
	this->year = _year;
}

int MusicFile::getYear() const{
	return this->year;
}

void MusicFile::print() const{
	File::print();
	cout << ". The song is from year " << this->getYear();
}
