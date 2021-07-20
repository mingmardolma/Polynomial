#include "PolyNode.hpp"

PolyNode::PolyNode(double coeff, int pow)
{
    setCoeff(coeff);
    setPow(pow);
}
double PolyNode::getCoeff() const
{
    return coeff;
}
int PolyNode::getPow() const
{
    return pow;
}
void PolyNode::setCoeff(double coeff)
{
    this->coeff = coeff;
} 
void PolyNode::setPow(int pow)
{
    this->pow = pow;
}