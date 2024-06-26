#ifndef MODEL_ISOTROPIC_H
#define MODEL_ISOTROPIC_H

#include "eigen3/Eigen/Core"

#include "Model/Model.H"

namespace Model
{
class Isotropic : public Model<2>
{
public:

    virtual Set::Scalar  W(Set::Matrix gradu)
    {
        Set::Scalar ret = 0.0;

        //
        // TODO: calculate strain energy density as a function of
        //       displacement gradient (gradu=beta)
        //       (See PS 4 Problem 2)
        //
        // The constants lambda and mu are available in this class
        // and are set to a value of 1
        //
        // The "ij"th component of gradu is
        //   gradu(i,j)
        // 
	for (int i = 0 ; i < 2 ; i++)
	    for (int j = 0 ; j < 2 ; j++)
		ret += 0.5*mu*(gradu(i,j) * gradu(j,i) + gradu(i,j) * gradu(i,j)) + 0.5*lambda*gradu(i,i)*gradu(j,j);

        return ret;
    }
    virtual Set::Matrix  DW(Set::Matrix gradu)
    {
        Set::Matrix ret = Set::Matrix::Zero();

        //
        // TODO: calculate the first derivative of strain energy
        //       (which is stress) as a function of gradu
        //       (See PS 4 Problem 2)
        //
        // Consistency will be checked in main.cpp using a numerical
        // derivative test
        //
	for (int i = 0 ; i < 2 ; i++)
	{
	    for (int j = 0 ; j < 2 ; j++)
	    {
		ret(i,j) = mu*(gradu(i,j) + gradu(j,i));

		for (int p = 0 ; p < 2 ; p++)
		{
		    ret(i,j) += lambda*(i == j)*gradu(p,p);
		}
	    }
	}

        return ret;
    }
    virtual Set::Tensor4 DDW(Set::Matrix gradu)
    {
        Set::Tensor4 ret = Set::Tensor4::Zero();

        //
        // TODO: calculate the second derivative of strain energy
        //       (which is the elastic modulus tensor) as a function
        //       of gradu.
        //       (See PS 4 Problem 2)
        //
        // Note that "ret" is a "Tensor4" type which is a 4th order tensor.
        //
        // You can get the "ijkl"th component of ret with
        //     ret(i,j,k,l)
        //
	for (int i = 0 ; i < 2 ; i++)
	    for (int j = 0 ; j < 2 ; j++)
		for (int k = 0 ; k < 2 ; k++)
		    for (int l = 0 ; l < 2 ; l++)
		        ret(i,j,k,l) += mu*((j == k)*(i == l) + (i == k)*(j == l)) + lambda*(i == j)*(k == l);

        return ret;
    }
private:
    double mu = 1.0, lambda = 1.0;
};
}
#endif
