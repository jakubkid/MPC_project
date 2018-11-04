#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;
    typedef struct MPCsolution_s
    {
        double steering;
        double acc;
        vector<double>  mpcX;
        vector<double>  mpcY;
    } MPCsolution_t;
class MPC
{
public:

    MPC();

    virtual ~MPC();

    // Solve the model given an initial state and polynomial coefficients.
    // Return the first actuations.
    MPCsolution_t Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);

    double getLf();
};

#endif /* MPC_H */
