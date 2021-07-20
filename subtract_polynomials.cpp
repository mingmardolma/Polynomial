#include <iostream>
#include <list>
#include "PolyNode.cpp"
#include <cmath>

using namespace std;

void sortByPow(list<PolyNode*> &polynomial_);
bool comparePow(const PolyNode* node1, const PolyNode* node2); 
void display(list<PolyNode*> &polynomial); 
list<PolyNode*> subtract(list<PolyNode*>&minuend, list<PolyNode*>&subtrahend);

int main()
{
    list<PolyNode*>polyHead1;  
    polyHead1.push_back(new PolyNode(2, 5));
    polyHead1.push_back(new PolyNode(-1, 0));
    polyHead1.push_back(new PolyNode(0, 3));
    polyHead1.push_back(new PolyNode(5, 2));


    list<PolyNode*>polyHead2;
    polyHead2.push_back(new PolyNode(10, 3));
    polyHead2.push_back(new PolyNode(-4, 2));
    polyHead2.push_back(new PolyNode(1, 5));

    cout << "The first polynomial is: " << endl;
    sortByPow(polyHead1);
    list<PolyNode*> ph1 = polyHead1;
    display(ph1);

    cout << "The second polynomial is: " << endl;
    sortByPow(polyHead2);
    list<PolyNode*> ph2 = polyHead2;
    display(ph2);

    cout << "The difference is: " << endl;
    list<PolyNode*> difference = subtract(polyHead1, polyHead2); 
    sortByPow(difference);
    list<PolyNode*> ph3 = difference;
    display(ph3);
}
void sortByPow(list<PolyNode*> &polynomial_)
{
    polynomial_.sort(comparePow);
}
bool comparePow(const PolyNode* node1, const PolyNode* node2)
{
    return(node1->getPow() > node2->getPow());
}
void display(list<PolyNode*> &polynomial) 
{
    const int full = polynomial.size();
    while(!polynomial.empty())
    {        
        if(polynomial.front()->getPow() == 0)
        {
            if(polynomial.front()->getCoeff() == 0)
            {
            }
            else if(polynomial.front()->getCoeff() != 0)
            {
                if(polynomial.size() == full)
                {
                    cout << polynomial.front()->getCoeff();
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
                else if(polynomial.size() != full && polynomial.front()->getCoeff() > 0)
                {
                    cout << " + " << polynomial.front()->getCoeff();
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
                else if(polynomial.size() != full && polynomial.front()->getCoeff() < 0)
                {
                    cout << " - " << ((polynomial.front()->getCoeff()) + (-2 * polynomial.front()->getCoeff()));
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
            }
            
        } 
        else if(polynomial.front()->getPow() == 1)
        {
            if(polynomial.front()->getCoeff() == 0)
            {
            }
            else if(polynomial.front()->getCoeff() != 0)
            {
                if(polynomial.size() == full)
                {
                    cout << polynomial.front()->getCoeff() << "x";
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
                else if(polynomial.size() != full && polynomial.front()->getCoeff() > 0)
                {
                    cout << " + " << (polynomial.front()->getCoeff()) << "x";
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
                else if(polynomial.size() != full && polynomial.front()->getCoeff() < 0)
                {
                    cout << " - " << ((polynomial.front()->getCoeff()) + (-2 * polynomial.front()->getCoeff())) << "x";
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
            }

        }
        else if(polynomial.front()->getPow() != 0 && polynomial.front()->getPow() !=1)
        {
            if(polynomial.front()->getCoeff() == 0)
            {
                cout << "";
            }
            else if(polynomial.front()->getCoeff() != 0)
            {
                if(polynomial.size() == full)
                {
                    cout << polynomial.front()->getCoeff() << "x^" << polynomial.front()->getPow();
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
                else if(polynomial.size() != full && polynomial.front()->getCoeff() > 0)
                {
                    cout << " + " << (polynomial.front()->getCoeff()) << "x^" << polynomial.front()->getPow();
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                }
                else if(polynomial.size() != full && polynomial.front()->getCoeff() < 0)
                {
                    cout << " - " << ((polynomial.front()->getCoeff()) + (-2 * polynomial.front()->getCoeff())) << "x^" << polynomial.front()->getPow();
                    if (polynomial.size() == 1) 
                    {
                        cout<< endl;
                    }
                } 
            }   
        }
        polynomial.pop_front(); 
    }
}
list<PolyNode*> subtract(list<PolyNode*> &minuend, list<PolyNode*> &subtrahend)
{
    list<PolyNode*> difference; 
    while(!minuend.empty() && !subtrahend.empty())
    {    
        PolyNode* temp = new PolyNode(0, 0); 
        if(minuend.front()->getPow() == subtrahend.front()->getPow())
        {
            temp->setCoeff((minuend.front()->getCoeff()) - (subtrahend.front()->getCoeff()));
            temp->setPow(minuend.front()->getPow());
            difference.push_back(temp);
            minuend.pop_front();
            subtrahend.pop_front();
        }
        else if(minuend.front()->getPow() > subtrahend.front()->getPow())
        {
            difference.push_back(minuend.front());
            minuend.pop_front();
        }
        else if(minuend.front()->getPow() < subtrahend.front()->getPow())
        {
            subtrahend.front()->setCoeff(-1 * subtrahend.front()->getCoeff());
            difference.push_back(subtrahend.front());
            subtrahend.pop_front();
        }
    }
    while(minuend.empty() && !subtrahend.empty())
    {
        subtrahend.front()->setCoeff(-1 * subtrahend.front()->getCoeff());
        difference.push_back(subtrahend.front());
        subtrahend.pop_front();
    }
    while(!minuend.empty() && subtrahend.empty())
    {
        difference.push_back(minuend.front());
        minuend.pop_front();
    }
    return difference;
}