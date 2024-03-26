#ifndef ELEMENT_Q4_H
#define ELEMENT_Q4_H

#include "Element.H"

namespace Element
{
template<class MODEL>
class Q4 : public Element<2,4,4,MODEL>
{
public:
    using Element<2,4,4,MODEL>::Element;

    std::array<double,4> eta(Set::Vector Y) override
    {
        std::array<double,4> ret;

        // TODO - copy from previous
	ret[0] =  0.25*(Y(0) - 1.0)*(Y(1) - 1.0);
	ret[1] = -0.25*(Y(0) + 1.0)*(Y(1) - 1.0);
	ret[2] =  0.25*(Y(0) + 1.0)*(Y(1) + 1.0);
	ret[3] = -0.25*(Y(0) - 1.0)*(Y(1) + 1.0);

        return ret;
    }

    std::array<Set::Vector,4> Deta(Set::Vector Y) override
    {
        std::array<Eigen::Vector2d,4> ret;
	
        // TODO - copy from previous
	ret[0] = Set::Vector (  0.25*(Y(1) - 1.0) ,  0.25*(Y(0) - 1.0) );
	ret[1] = Set::Vector ( -0.25*(Y(1) - 1.0) , -0.25*(Y(0) + 1.0) );
	ret[2] = Set::Vector (  0.25*(Y(1) + 1.0) ,  0.25*(Y(0) + 1.0) );
	ret[3] = Set::Vector ( -0.25*(Y(1) + 1.0) , -0.25*(Y(0) - 1.0) );

        return ret;
    }

public:
    virtual const std::array<Set::Vector,4> & getY0() {return Y0;}
    virtual const std::array<Set::Vector,4> & getQp() {return Qp;}
    virtual const std::array<double,4> & getQw() {return Qw;}
    virtual const double getArea() {
        // TODO - copy from previous
	return 4.0;
    }

private:
    //
    // Hard-coded values common to all elements
    //

    const std::array<Set::Vector,4> Y0 = {
        Set::Vector(-1.0,-1.0),
        Set::Vector(1.0,-1.0),
        Set::Vector(1.0,1.0),
        Set::Vector(-1.0,1.0)
    };

    const std::array<Set::Vector,4> Qp = {
        // TODO - copy from previous
	Set::Vector( 1.0/sqrt(3.0), 1.0/sqrt(3.0)),
        Set::Vector( 1.0/sqrt(3.0),-1.0/sqrt(3.0)),
        Set::Vector(-1.0/sqrt(3.0), 1.0/sqrt(3.0)),
        Set::Vector(-1.0/sqrt(3.0),-1.0/sqrt(3.0))
    };

    const std::array<double,4> Qw = {
        // TODO - copy from previous
	1.0, 
	1.0, 
	1.0, 
	1.0
    };


public:
    
    static const int vtkid = 5;
};

}
#endif
