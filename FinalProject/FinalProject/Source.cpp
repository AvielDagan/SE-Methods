#include "../Common/Control/Control.hpp"
#include "../Common/EventEngine/EventEngine.hpp"
#include "../Common/Graphics/Graphics.hpp"
#include "../controls/BorderDrawer/BorderDrawer.hpp"
#include "../controls/Button/Button.hpp"
#include "../controls/CheckBox/CheckBox.hpp"
#include "../controls/CheckList/CheckList.hpp"
#include "../controls/ComboBox/ComboBox.hpp"
#include "../Controls/DoubleBorderDrawer/DoubleBorderDrawer.hpp"
#include "../controls/Panel/Panel.hpp"
// #include "../controls/SingleBorderDrawer/SingleBorderDrawer.hpp"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    EventEngine engine;
    DoubleBorderDrawer *dbd = new DoubleBorderDrawer;
    // BorderDrawer* sbd = new SingleBorderDrawer;
    Panel panel(0, 0, dbd, Color::White, Color::Black, 0);
    Label l(0, 15, 10, dbd, Color::Cyan, Color::Black, "test label");
    // Label ll(10, 10, 10, 10, dbd, Color::Cyan, Color::Black, "test label");
    // Button b(10, 10, 5, 5, dbd, Color::Cyan, Color::Black, "test Button");
    // std::cout << "printing" << std::endl;
    
    // panel.addControl(&b);
    panel.addControl(&l);
    // panel.addControl(&ll);

    // cout << "panel.getWidth() -> " << panel.getWidth() << endl;
    // cout << "panel.getHeight() -> " << panel.getHeight() << endl;  
    engine.run(panel);
    
    while(1);

    return 0;
}
