#include "naive.hpp"
#include <string>
#include <chrono>

using namespace std;
float p = 1.05;

void summarise(string name, std::function<vector<int>*()> func){
    auto t1 = chrono::high_resolution_clock::now();
    vector<int>* sol = func();
    auto t2 = chrono::high_resolution_clock::now();
    cout << "===========" << endl;
    cout << name << endl;
    cout << "===========" << endl;
    cout << "time: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " ms" << endl;
    cout << "Solution size: " << sol->size() << endl;
}

int main(){

	vector<string> files = {"test", "chess", "retail", "pumsb", "kosarak", "webdocs"};
    for(string filename : files){
        SetCoverInput* sci = read_sci("../dataset/FIMI/" + filename + ".dat");
        summarise(filename + ".dat", [&]() -> vector<int>*{
            return naive(sci);
        });
    }
}
