#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	// check args count
	if(argc != 2)
	{
		cout << "This program requires exactly one arguement:\n";
		cout << "	$ ./<exe-name> <file-name>\n";
		return 1;
	}

	// if file exists, call "tail <file-name>"
	ifstream in_file(argv[1]);
	if(in_file)
	{
		string tail_str = "tail ";
		tail_str = tail_str.append(argv[1]);
		system(tail_str.c_str());
		cout << "\n";
	}
	else
	{
		cout << "File not found. Please enter a valid filename.\n";
		return 1;
	}
}