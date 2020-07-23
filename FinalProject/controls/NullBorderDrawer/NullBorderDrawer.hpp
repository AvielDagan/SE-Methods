#include "../BorderDrawer/BorderDrawer.hpp";

class NullBorderDrawer : public BorderDrawer {
    public:
        NullBorderDrawer() : BorderDrawer(0x20, 0x20, 0x20, 0x20, 0x20, 0x20) {} ;
        virtual ~NullBorderDrawer();
};