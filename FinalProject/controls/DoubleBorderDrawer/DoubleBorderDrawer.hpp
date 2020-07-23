#include "../BorderDrawer/BorderDrawer.hpp";

class DoubleBorderDrawer : public BorderDrawer {
    public:
        DoubleBorderDrawer() : BorderDrawer(0xC9, 0xBB, 0xC8, 0xBC, 0xCD, 0xBA) {};
        virtual ~DoubleBorderDrawer();
};