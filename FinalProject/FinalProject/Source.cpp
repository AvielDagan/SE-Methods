#include "../Common/Control/Control.hpp"
#include "../Common/EventEngine/EventEngine.hpp"
#include "../Common/Graphics/Graphics.hpp"
#include "../controls/BorderDrawer/BorderDrawer.hpp"
#include "../controls/Button/Button.hpp"
#include "../controls/CheckBox/CheckBox.hpp"
#include "../controls/CheckList/CheckList.hpp"
#include "../controls/ComboBox/ComboBox.hpp"
#include "../controls/DoubleBorderDrawer/DoubleBorderDrawer.hpp"
#include "../controls/Panel/Panel.hpp"
// #include "../controls/SingleBorderDrawer/SingleBorderDrawer.hpp"

int main(int argc, char const *argv[])
{

    BorderDrawer* dbd = new DoubleBorderDrawer;
    // BorderDrawer* sbd = new SingleBorderDrawer;
    Panel panel(0,0,20,20,dbd,Color::Cyan, Color::Black,1);
    Label l(5,5,5,5,dbd, Color::Cyan, Color::Black,"test label");
    Button b(10,10,5,5,dbd, Color::Cyan, Color::Black,"test Button");
    EventEngine engine;
    panel.addControl(&b);
    panel.addControl(&l);
    engine.run(panel);
    return 0;
}
