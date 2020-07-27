#pragma one

#include <vector>
#include "../Observer/Observer.hpp"
#include <string>
#include <memory>

using namespace std;

class Subject{
    private:
        vector<Observer*> observers;
    public:
        void addObserver(Observer* observe);
        void actions(string text);
        void listenKeyStroke();
        Subject();
        virtual ~Subject() = 0;
        
};