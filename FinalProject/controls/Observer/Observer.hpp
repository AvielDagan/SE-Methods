#pragma once
#include <string>
using namespace std;

class Observer
{
public:
    virtual void notify(string text){};
    Observer();
    ~Observer();
};
