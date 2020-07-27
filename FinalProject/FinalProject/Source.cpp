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
#include "../controls/TextBox/Textbox.hpp"
#include "../controls/NumericBox/NumericBox.hpp"
#include "../controls/RadioBox/RadioBox.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    BorderDrawer *dbd = new DoubleBorderDrawer;
    BorderDrawer *sbd = new SingleBorderDrawer;

    Panel panel(0, 0, dbd, Color::White, Color::Black);
    // Label l(0, 15, 10, dbd, Color::Cyan, Color::Black, "test label");
    // Label ll(10, 10, 10, 10, dbd, Color::Cyan, Color::Black, "test label");
    Button b(5, 5, 10, dbd, Color::Cyan, Color::Black, "test Button", NULL);
    Button c(10, 10, 10, dbd, Color::Cyan, Color::Black, "test Button2", NULL);
    TextBox TB(30, 0, 10, sbd, Color::White, Color::Cyan); // ?
    TextBox TB2(5, 0, 10, sbd, Color::White, Color::Cyan); // ?
    ComboBox CB(40, 10,10, sbd, Color::White, Color::Blue);
    Button plus(55, 11,1, dbd, Color::White, Color::Blue, " +",&CB);
    CheckList chkList(55,15,10,dbd,Color::Cyan, Color::Black, "CheckList");
    chkList.addToList("test1");
    chkList.addToList("test2");
    chkList.addToList("test3");

    RadioBox rdb(25,15,10,dbd,Color::Cyan, Color::Black, "RadioBox");
    rdb.addToList("1");
    rdb.addToList("2");
    rdb.addToList("3");

    // CheckBox chkbox(10, 25, 10, dbd, Color::Cyan, Color::Black, "test Button2", NULL);

	CB.addToList("Tal");
	CB.addToList("Tomer");
	CB.addToList("Aviel");
    CB.addToList("Itay");
    // std::cout << "printing" << std::endl;
    MessageAlert ma(0, 0, 20, sbd, dbd, Color::Cyan, Color::Black, "message", "OK", "CANCEL", &b);
    // NumericBox nb(0, 0, 100, 0, dbd, Color::Cyan, Color::Black);
    // CheckList cl(60, 10, 20, dbd, Color::Orange, Color::White);
    // cl.addToList("avielllll");
    // cl.addToList("itayyyyyy");
    // cl.addToList("tomerrrrrr");
    // cl.addToList("talllllllll");
    // panel.addControl(&c);
    // panel.addControl(&b);
    panel.addControl(&ma);
    panel.addControl(&TB);
    panel.addControl(&TB2);
    panel.addControl(&plus);
    panel.addControl(&CB);
    panel.addControl(&chkList);
    panel.addControl(&rdb);
    // panel.addControl(&nb);
    // panel.addControl(&cl);
    // panel.addControl(&ll);

    // cout << "panel.getWidth() -> " << panel.getWidth() << endl;
    // cout << "panel.getHeight() -> " << panel.getHeight() << endl;
    EventEngine engine;
    engine.run(panel);

    return 0;
}
