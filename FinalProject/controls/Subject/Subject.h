#pragma one

#include <vector>
#include "../Observer/Observer.h"
#include <memory>

using namespace std;

class Subject{
    private:
        vector<shared_ptr<Observer>> observers;
    public:
        void addObserver(shared_ptr<Observer>);
        void actions(int keyCode);
        void listenKeyStroke();//while(1)
        Subject();
        ~Subject();
        
};