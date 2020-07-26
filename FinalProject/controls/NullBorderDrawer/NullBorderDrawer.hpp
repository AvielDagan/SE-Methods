#include "../BorderDrawer/BorderDrawer.hpp"

class NullBorderDrawer : public BorderDrawer {
    public:
        NullBorderDrawer();
        virtual ~NullBorderDrawer();
};