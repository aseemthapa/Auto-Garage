CXXFLAGS = -std=c++17 -pthread
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
default: prog ./prog

all: axt3178_main.o

prog: axt3178_main.o axt3178_Auto_Part.o axt3178_Tire.o axt3178_Wheel.o axt3178_Battery.o axt3178_Windshield_Wiper.o axt3178_Wheel_Tire_Combo.o axt3178_Frame.o axt3178_Engine.o axt3178_Inventory.o axt3178_dialog.o axt3178_main_window.o axt3178_Order.o *.h
	$(CXX) $(CXXFLAGS) -o prog axt3178_main.o axt3178_Auto_Part.o axt3178_Tire.o axt3178_Wheel.o axt3178_Battery.o axt3178_Windshield_Wiper.o axt3178_Wheel_Tire_Combo.o axt3178_Frame.o axt3178_Engine.o axt3178_Inventory.o axt3178_dialog.o axt3178_main_window.o axt3178_Order.o $(GTKFLAGS)
axt3178_main_window.o: axt3178_main_window.cpp axt3178_main_window.h 
	$(CXX) $(CXXFLAGS) -c axt3178_main_window.cpp $(GTKFLAGS)
axt3178_main.o: axt3178_main.cpp *.h
	$(CXX) $(CXXFLAGS) -c axt3178_main.cpp $(GTKFLAGS)
axt3178_Auto_Part.o: axt3178_Auto_Part.cpp *.h
	$(CXX) $(CXXFLAGS) -c axt3178_Auto_Part.cpp $(GTKFLAGS)
axt3178_Tire.o: axt3178_Tire.cpp axt3178_Tire.h axt3178_Auto_Part.h 
	$(CXX) $(CXXFLAGS) -c axt3178_Tire.cpp $(GTKFLAGS)
axt3178_Wheel.o: axt3178_Wheel.cpp axt3178_Wheel.h axt3178_Auto_Part.h 
	$(CXX) $(CXXFLAGS) -c axt3178_Wheel.cpp $(GTKFLAGS)
axt3178_Battery.o: axt3178_Battery.cpp axt3178_Battery.h axt3178_Auto_Part.h 
	$(CXX) $(CXXFLAGS) -c axt3178_Battery.cpp $(GTKFLAGS)
axt3178_Windshield_Wiper.o: axt3178_Windshield_Wiper.cpp axt3178_Windshield_Wiper.h axt3178_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c axt3178_Windshield_Wiper.cpp $(GTKFLAGS)
axt3178_Wheel_Tire_Combo.o: axt3178_Wheel_Tire_Combo.cpp axt3178_Wheel_Tire_Combo.h axt3178_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c axt3178_Wheel_Tire_Combo.cpp $(GTKFLAGS)
axt3178_Frame.o: axt3178_Frame.cpp axt3178_Frame.h axt3178_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c axt3178_Frame.cpp $(GTKFLAGS)
axt3178_Engine.o: axt3178_Engine.cpp axt3178_Engine.h axt3178_Auto_Part.h
	$(CXX) $(CXXFLAGS) -c axt3178_Engine.cpp $(GTKFLAGS)
axt3178_Inventory.o: axt3178_Inventory.h axt3178_Auto_Part.h axt3178_Inventory.cpp axt3178_Order.h
	$(CXX) $(CXXFLAGS) -c axt3178_Inventory.cpp $(GTKFLAGS)
axt3178_Order.o: axt3178_Order.h axt3178_Order.cpp
	$(CXX) $(CXXFLAGS) -c axt3178_Order.cpp $(GTKFLAGS)
axt3178_dialog.o: axt3178_dialog.h axt3178_dialog.cpp
	$(CXX) $(CXXFLAGS) -c axt3178_dialog.cpp $(GTKFLAGS)

clean:
	rm -f *.o a.out *.h.gch


