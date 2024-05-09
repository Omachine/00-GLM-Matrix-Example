#include <iostream>
#include <string>
#include <fstream>

int main() {
	using namespace std;

	/*ifstream file("teste.exe");
	if (file.is_open()) {
		string msg;
		while (getline(file, msg, '|')) {
			cout << msg << endl;
		}
		file.close();
	}*/

	/*ifstream shader_file("shader.vert");
	if (shader_file.is_open()) {
		string line;
		while (getline(shader_file, line)) cout << line << endl;
		shader_file.close();
	}*/


	streampos start, end;

	ifstream shader_file("shader.vert");
	if (shader_file.is_open()) {
		start = shader_file.tellg();
		shader_file.seekg(0, ios::end);
		end = shader_file.tellg();

		int file_size = end - start;

		char* shader = new char[file_size];
		delete[] shader;
		shader_file.close();
	}

	return 0;
}


