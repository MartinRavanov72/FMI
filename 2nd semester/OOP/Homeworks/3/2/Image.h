#pragma once
#include <iostream> 
#include <string>
#include "File.h"

using namespace std;


class Image : public File{
	private:
	string nameOfDevice;
	pair<int, int> resolution;
	public:
	Image();

	Image(const string& _name, double _sizeInMB, const string& _extension, const string& _nameOfDevice, const pair<int, int>& _resolution);

	Image(const Image& other);

	Image& operator=(const Image& other);

	~Image();

	void setNameOfDevice(const string& _nameOfDevice);
	string getNameOfDevice() const;
	void setResolution(const pair<int, int>& _resolution);
	pair<int, int> getResolution() const;
	void print() const override;
};
