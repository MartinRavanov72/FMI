#pragma once
#include <iostream> 
#include <string>
#include "File.h"

using namespace std;


class MusicFile: public File{
	private:
	string nameOfArtist;
	string songName;
	int year;
	public:
	MusicFile();

	MusicFile(const string& _name, double _sizeInMB, const string& _extension, const string& _nameOfArtist, const string& _songName, int _year);

	MusicFile(const MusicFile& other);

	MusicFile& operator=(const MusicFile& other);

	~MusicFile();

	void setNameOfArtist(const string& _nameOfArtist);
	string getNameOfArtist() const;
	void setSongName(const string& _songName);
	string getSongName() const;
	void setYear(int _year);
	int getYear() const;
	void print() const override;
};
