#pragma one
#include "./Subject.hpp"
#include <iostream>
using namespace std;

Subject::Subject()
{
}
Subject::~Subject()
{
}
void Subject::addObserver(Observer* observer)
{
    if (observer != NULL)
        observers.push_back(observer);
}
void Subject::actions(string text)
{
    for (auto const &value : observers)
    {
        value->notify(text);
    }
}
// not sure if need this method 
void Subject::listenKeyStroke()
{

} //while(1)
