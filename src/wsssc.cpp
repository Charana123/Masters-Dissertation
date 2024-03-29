#include "sssc.hpp"

template <typename U, typename V>
function<U(V)> functionWrapper(map<U, V> m){
    return [&](U u) -> V{
        if(m.find(u) != m.end()){
            return m[u];
        }
        else{
            throw exception();
        }
    };
}

void Cover::get(function<int(int)>* eid, function<int(int)>* eff){
    *eid = functionWrapper<int, int>(this->eid_m);
    *eff = functionWrapper<int, int>(this->eff_m);
}

void Cover::run(HyperEdge* he){
    float lev_t = ceil(log2f(this->b(he->vertices)/this->c(he->vertices)));
    for(int v : he->vertices){
        this->eid_m[v] = he->i;
        this->eff_m[v] = lev_t;
    }
}

SSSCOutput* sssc(SSSCInput* sssci){

    Cover cover1(sssci->b, sssci->c);
    for(HyperEdge he; (he = sssci->stream->get_next_hyperedge(he)) != nullptr; ){
        cover1.run(he);
    }
    function<int(int)> *eid = new function<int(int)>();
    function<int(int)> *eff = new function<int(int)>();
    cover.get(eid, eff);
    return new EdgeCoverOutput{.cover_certificate=eid};
}












