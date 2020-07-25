#include "../Common/Control/Control.hpp"
#include "../Common/EventEngine/EventEngine.hpp"
#include "../Common/Graphics/Graphics.hpp"
#include "../controls/BorderDrawer/BorderDrawer.hpp"
#include "../controls/Button/Button.hpp"
#include "../controls/CheckBox/CheckBox.hpp"
#include "../controls/CheckList/CheckList.hpp"
#include "../controls/ComboBox/ComboBox.hpp"
#include "../controls/Panel/Panel.hpp"
#include "../controls/MessageAlert/MessageAlert.hpp"
#include "../controls/DoubleBorderDrawer/DoubleBorderDrawer.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    BorderDrawer *dbd = new DoubleBorderDrawer;
    BorderDrawer* sbd = new SingleBorderDrawer;

    Panel panel(0, 0, dbd, Color::White, Color::Black, 0);
    // Label l(0, 15, 10, dbd, Color::Cyan, Color::Black, "test label");
    // Label ll(10, 10, 10, 10, dbd, Color::Cyan, Color::Black, "test label");
    Button b(5, 5, 10, dbd, Color::Cyan, Color::Black, "test Button");
    Button c(10, 10, 10, dbd, Color::Cyan, Color::Black, "test Button2");
    // std::cout << "printing" << std::endl;
    MessageAlert ma(0,0,15,sbd,dbd,Color::Cyan, Color::Black,"message","OK","CANCEL",&b);
    panel.addControl(&b);
    panel.addControl(&c);
    // panel.addControl(&l);
    // panel.addControl(&ma);
    // panel.addControl(&ll);

    // cout << "panel.getWidth() -> " << panel.getWidth() << endl;
    // cout << "panel.getHeight() -> " << panel.getHeight() << endl;  
    EventEngine engine;
    engine.run(panel);
    
    return 0;
}
