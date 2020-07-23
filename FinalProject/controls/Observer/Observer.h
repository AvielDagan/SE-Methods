#pragma once

class Observer
{
private:
    
public:
    virtual void notify(int keyCode);
    Observer();
    ~Observer();
};
