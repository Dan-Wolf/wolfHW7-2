#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Usage is: control_GPIO gpio_number state" << endl;
		cout << "gpio number: GPIO number to control" << endl;
		cout << "state: hi or low" << endl;
		return 0;
	}
	
	string gpio_number = argv[1];
	ostringstream s;
	s << "gpio" << gpio_number;
	string name = string(s.str());
	string dir = argv[2];
	
	string path = "/sys/class/gpio/" + name;
	ofstream fs;
	fs.open((path+"/direction").c_str());
	fs<< "out";
	fs.close();

	if (dir == "hi") {
		fs.open((path+"/value").c_str());
		fs << 1;
		fs.close();
	}
	else if (dir == "low") {
		fs.open((path+"/value").c_str());
		fs << 0;
		fs.close();
	}
	else {
		cout << "Invalid Command!" << endl;
	}

	return 0;
}
