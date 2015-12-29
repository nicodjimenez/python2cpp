#include <iostream>
#include <string>

#include "objlist.pb.h"

using namespace std;
using std::string; 

int parse(const string& x) {
    tutorial::ObjectList objList;
    objList.ParseFromString(x);
    int objCt = objList.object_size();
    for (int i = 0; i < objCt;  i++){
        const tutorial::Object& x = objList.object(i);
        std::cout << x.name() << std::endl;
    }
    return objCt;
}
