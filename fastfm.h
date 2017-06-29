//
// Created by ibayer on 21.02.17.
//

#ifndef FASTFM_FASTFM_H
#define FASTFM_FASTFM_H

#include <memory>

namespace fastfm {
//    TODO add enumerate for split.

/*! \brief This class contains all settings needed to train a model.
*
*  Detailed description starts here.
*/
class Settings {
public:
    Settings();
    ~Settings();
    class Impl;
private:
    // non copyable
    Settings(const Settings&);
	Settings& operator=(const Settings&);

    friend class Internal;
    Impl* mImpl;
};

/*! \brief This class contains all model parameter.
*
*  Detailed description starts here.
*/
class Model {
public:
    Model();
    ~Model();

    // A row major matrix is expected.
    void add_parameter(double* data, int rank, int n_features, int order);
    void add_parameter(double* data, int n_features);
    void add_parameter(double* intercept);
    class Impl;
private:
    // non copyable
    Model(const Model&);
	Model& operator=(const Model&);

    friend class Internal;
    Impl* mImpl;
};


/*! \brief This class contains all data needed to train a model.
*
*  Detailed description starts here.
*/
class Data {
public:
    Data();
    ~Data();
    // TODO should use all const, requires changing SpMat to SpConstMat everywhere.
    // A column major sparse matrix is expected.
    void add_design_matrix(int n_samples, int n_features, int nnz,
                           int* outer_ptr, int* inter_ptr, double* data);
    void add_target(const int n_samples, double* data);
    void add_prediction(const int n_samples, double* data);
    class Impl;
private:
    // non copyable
    Data(const Data&);
	Data& operator=(const Data&);

    friend class Internal;
    Impl* mImpl;
};


//! Fits a model using the specified settings and data.
/*!
  \param s the settings that specifiy how the model should be trained.
  \param m the initial model parameter.
  \param d the data required for the selected settings.
  \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
  TODO add link to the regression tests.
*/
void fit(Settings* s, Model* m, Data* d );

//! Make predictions with a trained model for the given data.
/*!
  \param s the settings that specifiy how the predictions should be made.
  \param m the model parameter.
  \param d the data required to make the predictions.
  \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
  TODO add link to the regression tests.
  TODO can we make the Model argument const?
*/
void predict(Model* m, Data* d);
}
#endif //FASTFM_FASTFM_H
