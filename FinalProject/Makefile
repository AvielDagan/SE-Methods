CXX = g++
CPPFLAGS = -std=c++1z -static -g
OBJS += controls/BorderDrawer/BorderDrawer.o controls/DoubleBorderDrawer/DoubleBorderDrawer.o controls/NullBorderDrawer/NullBorderDrawer.o controls/SingleBorderDrawer/SingleBorderDrawer.o Common/Control/Control.o Common/EventEngine/EventEngine.o Common/Graphics/Graphics.o controls/Button/Button.o controls/CheckBox/CheckBox.o controls/CheckList/CheckList.o controls/Label/Label.o controls/MessageAlert/MessageAlert.o controls/Observer/Observer.o controls/Panel/Panel.o controls/Subject/Subject.o Controls/ComboBox/ComboBox.o Controls/NumericBox/NumericBox.o Controls/RadioBox/RadioBox.o Controls/TextBox/TextBox.o FinalProject/Source.o 
%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe



