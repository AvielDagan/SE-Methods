#include "../BorderDrawer/BorderDrawer.hpp";


class SingleBorderDrawer : public BorderDrawer {
    public:
        SingleBorderDrawer() : BorderDrawer(0xDA, 0xBF, 0xC0, 0xD9, 0xC4, 0xB3) {};
        virtual ~SingleBorderDrawer();
};
