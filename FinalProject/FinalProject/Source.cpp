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
    Button b(5, 5, 10, dbd, Color::Cyan, Color::Black, "", NULL);
    TextBox tb(30, 0, 10, sbd, Color::White, Color::Cyan);
    ComboBox cb(40, 8,10, sbd, Color::White, Color::Blue);
    Button plus(55, 9,1, dbd, Color::White, Color::Blue, " +",&cb);
    CheckList chkList(45,15,10,dbd,Color::Cyan, Color::Black, "CheckList");
    RadioBox rdb(10,15,10,dbd,Color::Cyan, Color::Black, "RadioBox");
    MessageAlert ma(0, 0, 20, sbd, dbd, Color::Cyan, Color::Black, "message", "OK", "CANCEL", &b);
    NumericBox nb(25, 26, 100, -100, dbd, Color::Cyan, Color::Black);

    chkList.addToList("test1");
    chkList.addToList("test2");
    chkList.addToList("test3");

    rdb.addToList("1");
    rdb.addToList("2");
    rdb.addToList("3");

	cb.addToList("Tal");
	cb.addToList("Tomer");
	cb.addToList("Aviel");
    cb.addToList("Itay");
   
    panel.addControl(&ma);
    panel.addControl(&tb);
    panel.addControl(&plus);
    panel.addControl(&cb);
    panel.addControl(&chkList);
    panel.addControl(&rdb);
    panel.addControl(&nb);

    EventEngine engine;
    engine.run(panel);

    return 0;
}
