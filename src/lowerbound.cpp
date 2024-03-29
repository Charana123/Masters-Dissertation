#include "sc_utils.hpp"

int compute_lowerbound(SetCoverInput* sci){
    cout << "computing lowerbound" << endl;

    sort(sci->sets->begin(), sci->sets->end(), [](Set& s1, Set& s2) -> bool{
        return s1.vertices.size() > s2.vertices.size();
    });
    unsigned long i = 0;
    cout << "sci->n: " << sci->n << endl;
    for(unsigned long size = 0; i < sci->sets->size(); i++){
        Set& s = sci->sets->at(i);
        size += s.vertices.size();
        if(size >= sci->n) break;
    }
    return i + 1;
}

int main(int argc, char** argv){
    string filepath = string(argv[1]);
    //vector<string> files = {"test", "chess", "pumsb", "retail", "kosarak"};
    //for(string filename : files) {
        //SetCoverInput* sci = read_sci("../implementations/dataset/FIMI/" + filename + ".dat");
        SetCoverInput* sci = read_sci(filepath);
        /* SetCoverInput* sci = read_sci(filename); */
        int lowerbound = compute_lowerbound(sci);
        cout << "lowerbound: " << lowerbound << endl;
    //}
}

