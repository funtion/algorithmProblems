#include<vector>
#include<iostream>
class t{
public:
    t(){
        throw 1;
    }
};
void test(){
    //std::vector<t> vt;
    //vt.push_back(t());
    //vt.push_back(t());
    t t1;
    t t2;
}
int main(){
    try{
        test();
        std::cout<<"test\n";
    }catch(...){
        std::cout<<"catch\n";
    }

    return 0;
}
