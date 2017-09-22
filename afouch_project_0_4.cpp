#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	// check for arguements
	if(argc != 4)
	{
		cout << "This program requires exactly three arguments:\n";
		cout << "	$ ./<exe-name> <file-name> <start-line-num> <end-line-num>\n";
		return 1;
	}

	// convert args to int
	int in_start = atoi(argv[2]);
	int in_end = atoi(argv[3]);
	
	// check if line number args are integers
	istringstream s1(argv[2]);
	istringstream s2(argv[3]);
	int x, y;
	if(!(s1 >> x))
	{
			cerr << "Invalid line number: " << argv[2] << "\n";
			return 1;
	}
	else if(!(s2 >> y))
	{
			cerr << "Invalid line number: " << argv[3] << "\n";
			return 1;
	}

	// if file exists, print lines in_start --> in_end
	ifstream in_file(argv[1]);
	string out_str;
	if(in_file)
	{
		int curr_line = 0;
		while(getline(in_file, out_str) && curr_line <= in_end)
		{
			if(curr_line >= in_start)
				cout << out_str << "\n";
			curr_line++;
		}
		
		if(curr_line < in_end)
			cout << "Reached the end of file in " << curr_line << " lines\n";
	}
	else
	{
		cout << "File not found. Please enter a valid filename.\n";
		return 1;
	}
}