#ifndef POLY_NODE_H_
#define POLY_NODE_H_
class PolyNode { 
public: 
    PolyNode(double coeff, int pow); 
    double getCoeff() const; 
    int getPow() const; 
    void setCoeff(double coeff);
    void setPow(int pow);

private: 
   double coeff; 
   int pow; 
};
#endif
