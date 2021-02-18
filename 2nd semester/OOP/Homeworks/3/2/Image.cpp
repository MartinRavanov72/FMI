#include "Image.h"

Image::Image() : File(){}

Image::Image(const string& _name, double _sizeInMB, const string& _extension, const string & _nameOfDevice, const pair<int, int>& _resolution) : File(_name, _sizeInMB, _extension){
	if(_extension != ".jpg" && _extension != ".png"){
		this->extension = "";
		throw invalid_argument("Invalid extenstion!");
	}

	this->setNameOfDevice(_nameOfDevice);;
	this->setResolution(_resolution);
}

Image::Image(const Image & other) : File(other){
	this->setNameOfDevice(other.getNameOfDevice());;
	this->setResolution(other.getResolution());
}

Image& Image::operator=(const Image & other){
	if(this == &other){
		return *this;
	}

	File::operator =(other);

	this->setNameOfDevice(other.getNameOfDevice());;
	this->setResolution(other.getResolution());

	return *this;
}

Image::~Image(){}

void Image::setNameOfDevice(const string & _nameOfDevice){
	this->nameOfDevice = _nameOfDevice;
}

string Image::getNameOfDevice() const{
	return this->nameOfDevice;
}

void Image::setResolution(const pair<int, int>& _resolution){
	this->resolution = _resolution;
}

pair<int, int> Image::getResolution() const{
	return this->resolution;
}

void Image::print() const{
	File::print();
	cout << ". Resolution: " << this->getResolution().first << ":" << this->getResolution().second;
}
