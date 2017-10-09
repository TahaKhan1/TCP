#include <iostream>
#include "TcpController.h"
#include <fstream>
using namespace std;

TcpController::TcpController() {}

TcpController::TcpController(string &filename) {
	ifstream image(filename, ios::binary | ios::ate);
	if (image.is_open())
		cout << "File is opened" << endl;
	buffer = new char[image.tellg()];
	image.seekg(0, image.beg);
	image.read(buffer, strlen(buffer));

}

TcpController::~TcpController() {

	delete[] buffer;
}

void TcpController::control() {
	
}