#include "greedy.hpp"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
float p = 1.05;

void summarise(string name, std::function<vector<unsigned long>*()> func){
    auto t1 = chrono::high_resolution_clock::now();
    vector<unsigned long>* sol = func();
    auto t2 = chrono::high_resolution_clock::now();
    cout << "===========" << endl;
    cout << name << endl;
    cout << "===========" << endl;
    cout << "time: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " ms" << endl;
    cout << "solution size: " << sol->size() << endl;
    cout << endl;
}

int main(int argc, char** argv){
	string filename = string(argv[1]);

	/* vector<string> files = {"test", "chess", "retail", "pumsb", "kosarak", "webdocs"}; */
	/* vector<string> files = {"chess"}; */
	/* for(string filename : files){ */
		/* SetCoverInput* sci = read_sci("../dataset/FIMI/" + filename + ".dat"); */
		SetCoverInput* sci = read_sci(filename);
		/* summarise(filename  + ".dat", [&]() -> vector<unsigned long>*{ */
		/* 	return greedy(sci, 3); */
		/* }); */
		summarise(filename  + ".dat", [&]() -> vector<unsigned long>*{
			return greedy(sci);
		});
	/* } */
}







