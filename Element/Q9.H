#ifndef ELEMENT_Q9_H
#define ELEMENT_Q9_H

#include "Element.H"

namespace Element
{
template<class MODEL>
class Q9 : public Element<2,9,9,MODEL>
{
public:
    using Element<2,9,9,MODEL>::Element;

    std::array<double,9> eta(Set::Vector Y) override
    {
        std::array<double,9> ret;

        // TODO - copy from previous
	ret[0] = 0.25 * (Y(0) - 1.0)*(Y(1) - 1.0)*Y(0)*Y(1);
	ret[1] = 0.50 * (1.0 - Y(0)*Y(0))*(Y(1) - 1.0)*Y(1);
	ret[2] = 0.25 * (Y(0) + 1.0)*(Y(1) - 1.0)*Y(0)*Y(1);
	ret[3] = 0.50 * (1.0 + Y(0))*(1.0 - Y(1)*Y(1))*Y(0);
	ret[4] = 0.25 * (Y(0) + 1.0)*(Y(1) + 1.0)*Y(0)*Y(1);
	ret[5] = 0.50 * (1.0 - Y(0)*Y(0))*(Y(1) + 1.0)*Y(1);
	ret[6] = 0.25 * (Y(0) - 1.0)*(Y(1) + 1.0)*Y(0)*Y(1);
	ret[7] = 0.50 * (Y(0) - 1.0)*(1.0 - Y(1)*Y(1))*Y(0);
	ret[8] = (1.0 - Y(0)*Y(0))*(1.0 - Y(1)*Y(1));

        return ret;
    }

    std::array<Set::Vector,9> Deta(Set::Vector Y) override
    {
        std::array<Eigen::Vector2d,9> ret;

        // TODO - copy from previous
	ret[0] = Set::Vector( 0.25*(2.0*Y(0) - 1.0)*(Y(1) - 1.0)*Y(1) , 0.25*(Y(0) - 1.0)*(2.0*Y(1) - 1.0)*Y(0) );
	ret[1] = Set::Vector( 0.5*(-2.0*Y(0))*(Y(1) - 1.0)*Y(1) 	   , 0.5*(1.0 - Y(0)*Y(0))*(2.0*Y(1) - 1.0) );
 	ret[2] = Set::Vector( 0.25*(2.0*Y(0) + 1.0)*(Y(1) - 1.0)*Y(1) , 0.25*(Y(0) + 1.0)*(2.0*Y(1) - 1.0)*Y(0) );
	ret[3] = Set::Vector( 0.5*(1.0 + 2.0*Y(0))*(1.0 - Y(1)*Y(1))  , 0.5*(1.0 + Y(0))*(-2.0*Y(1))*Y(0) );
	ret[4] = Set::Vector( 0.25*(2.0*Y(0) + 1.0)*(Y(1) + 1.0)*Y(1) , 0.25*(Y(0) + 1.0)*(2.0*Y(1) + 1.0)*Y(0) );
	ret[5] = Set::Vector( 0.5*(-2.0*Y(0))*(Y(1) + 1.0)*Y(1)       , 0.5*(1.0 - Y(0)*Y(0))*(2.0*Y(1) + 1.0) );
	ret[6] = Set::Vector( 0.25*(2.0*Y(0) - 1.0)*(Y(1) + 1.0)*Y(1) , 0.25*(Y(0) - 1.0)*(2.0*Y(1) + 1.0)*Y(0) );
	ret[7] = Set::Vector( 0.5*(2.0*Y(0) - 1.0)*(1.0 - Y(1)*Y(1))  , 0.5*(Y(0) - 1.0)*(-2.0*Y(1))*Y(0) );
	ret[8] = Set::Vector( (-2.0*Y(0))*(1.0 - Y(1)*Y(1))           , (1.0 - Y(0)*Y(0))*(-2.0*Y(1)) );

        return ret;
    }

public:
    virtual const std::array<Set::Vector,9> & getY0() {return Y0;}
    virtual const std::array<Set::Vector,9> & getQp() {return Qp;}
    virtual const std::array<double,9> & getQw() {return Qw;}
    virtual const double getArea() {
        // TODO - copy from previous
	return 4.0;
    }

private:
    //
    // Hard-coded values common to all elements
    //

    const std::array<Set::Vector,9> Y0 = {
        Set::Vector(-1.0,-1.0),
        Set::Vector( 0.0,-1.0),
        Set::Vector( 1.0,-1.0),
        Set::Vector( 1.0, 0.0),
        Set::Vector( 1.0, 1.0),
        Set::Vector( 0.0, 1.0),
        Set::Vector(-1.0, 1.0),
        Set::Vector(-1.0, 0.0),
        Set::Vector( 0.0, 0.0),
    };

    const std::array<Set::Vector,9> Qp = {
        // TODO - copy from previous
 	Set::Vector(0.0,0.0),
	Set::Vector(sqrt(3.0/5.0),0.0),
	Set::Vector(-sqrt(3.0/5.0),0.0),
	Set::Vector(0.0,sqrt(3.0/5.0)),
	Set::Vector(0.0,-sqrt(3.0/5.0)),
	Set::Vector( 1.0/sqrt(3.0/5.0), 1.0/sqrt(3.0/5.0)),
        Set::Vector( 1.0/sqrt(3.0/5.0),-1.0/sqrt(3.0/5.0)),
        Set::Vector(-1.0/sqrt(3.0/5.0), 1.0/sqrt(3.0/5.0)),
        Set::Vector(-1.0/sqrt(3.0/5.0),-1.0/sqrt(3.0/5.0))
    };

    const std::array<double,9> Qw = {
        // TODO - copy from previous
	64.0/81.0,
	40.0/81.0, 40.0/81.0, 40.0/81.0, 40.0/81.0,
	25.0/81.0, 25.0/81.0, 25.0/81.0, 25.0/81.0
    };


public:
    
    static const int vtkid = 28;
};

}
#endif
