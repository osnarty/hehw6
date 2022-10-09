
// this must assume file 1 is already made so it can copy contents over to file2
// this makes file 2 and copys file1 over to it.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// ex. ./mycopier myfile1.txt myfile2.txt

#define FILE_NAME "/home/debian/cpe422/hw6"

int main(int argc, char* argv[])
{
	//this checks for the cmd to have 3 arguments, mycopier,file1,file2
	if(argc!=3)
	{
		cout << endl;
		cout << "to use is mycopier,file1name,file2name" << endl;
		cout << "e.g. myCopier file1.txt file2.txt" << endl;
		return 2;
	}

	cout << endl;
	cout << "starting mycopier" << endl;
	
	// Save name of the two files
	string cmd1(argv[1]);
	string cmd2(argv[2]);

	fstream fs1;
	fstream fs2;

	string path(FILE_NAME);

	// makes the path and name of the argument into variable pathname1/pathname2
	string pathname1 = path + "/" + cmd1;
	string pathname2 = path + "/" + cmd2;

	// file 1 is reading and file 2 is writing
	fs1.open((pathname1).c_str(), fstream::in);
	fs2.open((pathname2).c_str(), fstream::out);

	cout << endl;
	cout << "reading file: " << pathname1 << endl;
	cout << "writing file: " << pathname2 << endl;
	cout << endl;

	string line;

	cout << "copying files: " << endl;

	// copy contents from file1 to file2
	while(getline(fs1,line)) fs2 << line << endl;

	cout << "done." << endl << endl;

	// Close both files
	fs1.close();
	fs2.close();

	cout << "mycopier is finished" << endl << endl;

	return 0;

}