#ifndef SSSC_H_
#define SSSC_H_

#include "ec_utils.hpp"
#include <cmath>

using HyperEdge = Set;

struct SSSCInput
{
    Set* universe;
    Stream* stream;
};

struct SSSCOutput
{
    function<int(int)>* cover_certificate;
};

SSSCOutput* sssc(SSSCInput* eci);

class Cover {
    public:
        Cover()
        void run(HyperEdge* he);
        void get(function<int(int)>* eid, function<int(int)>* eff);
    private:
        map<int, int> eid_m = {};
        map<int, int> eff_m = {};
        function<int(set<int>&)>& b;
        function<int(set<int>&)>& c;
};

#endif
