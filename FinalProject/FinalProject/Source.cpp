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
#include "../controls/NumericBox/NumericBox.hpp"
// #include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    BorderDrawer *dbd = new DoubleBorderDrawer;
    BorderDrawer* sbd = new SingleBorderDrawer;

    Panel panel(0, 0, dbd, Color::White, Color::Black, 0);
    // Label l(0, 15, 10, dbd, Color::Cyan, Color::Black, "test label");
    Button b(0, 0, 5, 5, dbd, Color::Cyan, Color::Black, "test Button");
    MessageAlert ma(5,5,15,sbd,dbd,Color::Cyan, Color::Black,"message","OK","CANCEL",&b);
    NumericBox nb(0,0,0,100,dbd, Color::White, Color::Black);
    panel.addControl(&b);
    panel.addControl(&ma); 
    panel.addControl(&nb);
    EventEngine engine;
    engine.run(panel);
    
    return 0;
}
