#include <iostream>
#include "fastfm.h"

using namespace std;

using namespace fastfm;

int main(int argc, char** argv) {

    cout << endl << "[ii] Little test" << endl;

    const int l = 2;    

    static const int size = 4;
    double* tmp_array = new double[size];
    double tmp = 4;

    Model* m = new Model();
    m->add_parameter(&tmp);
    m->add_parameter(tmp_array, size);

    Data* d = new Data();
    d->add_prediction(size, tmp_array);

    delete d;
    delete m;
    delete[] tmp_array;

    cout << endl << "successfully completed :)" << endl;
    return 0;
}
