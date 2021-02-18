#include "File.h"
#include "Content.h"
#include "FileSystem.h"
#include "Image.h"
#include "MusicFile.h"
#include <utility> 
#include <vector> 
#include <string> 

using namespace std;

int main(){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);                  //memory leak test
	File f; 

	File textFile("textFile", 3.2, ".txt");
	File exeFile("exeFile", 712, ".exe");
	File cppFile("cppFile", 3, ".cpp");
	File cppFile2("cppFile", 9, ".cpp");

	pair <int, int> pair1;
	pair1.first = 1920;
	pair1.second = 1080;

	pair <int, int> pair2;
	pair2.first = 1280;
	pair2.second = 720;

	Image imgFilePng("imageFilePng", 312.2, ".png", "Ivan's Phone", pair1);
	Image imgFileJpg("imageFileJpg", 180.99, ".jpg", "Pesho's Phone", pair2);

	MusicFile musicFileMp3("musicFileMp3", 13, ".mp3", "Azis", "Avtomontior", 1999);
	MusicFile musicFileFlac("musicFileFlac", 11.1, ".flac", "Death", "The Philosopher", 1991);

	Folder smallFolder;
	smallFolder.setName("smallFolder");
	smallFolder.addFile(&textFile);
	smallFolder.addFile(&imgFilePng);

	Folder bigFolder;
	bigFolder.setName("bigFolder");
	bigFolder.addFile(&musicFileMp3);
	bigFolder.addFolder(&smallFolder);

	Folder lastFolder;
	lastFolder.setName("lastFolder");
	lastFolder.addFile(&cppFile);
	lastFolder.addFile(&cppFile2);

	Folder mainFolder;
	mainFolder.setName("mainFolder");
	mainFolder.addFile(&exeFile);
	mainFolder.addFile(&imgFileJpg);
	mainFolder.addFile(&musicFileFlac);
	mainFolder.addFolder(&bigFolder);
	mainFolder.addFolder(&lastFolder);
	mainFolder.addFile(&cppFile2);

	FileSystem fs(&mainFolder);
	
	fs.print();

	vector<File*> result = fs.getFileByName("cppFile");
	for(int i = 0; i < result.size(); i++){
		result[i]->print();
		cout << endl;
	}
	if(result.size() == 0){
		cout << "No files with that name found" << endl;
	}
	cout << endl;

	File hFile("hFile", 2, ".h");
	File jsonFile("jsonFile", 2.222, ".json");
	fs.createFile(&hFile, "mainFolder/bigFolder/smallFolder");
	textFile.setName("hFile");
	textFile.setExtension(".h");
	textFile.setName("textFile");

	fs.createFile(&jsonFile, "mainFolder/lastFolder");
	try{
		fs.createFile(&hFile, "mainFolder/bigFolder/azisFolder");
	} catch(const std::exception& exc){
		cout << exc.what() << endl;
	}
	
	result = fs.getFileByName("hFile");
	for(int i = 0; i < result.size(); i++){
		result[i]->print();
		cout << endl;
	}
	if(result.size() == 0){
		cout << "No files with that name found" << endl;
	}
	cout << endl;
	
	fs.print();
	system("pause");
	return 0;
}