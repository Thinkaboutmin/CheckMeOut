EXECUTABLE=CheckMeOut
CXX=g++

all: main.o order.o item.o registerController.o StoreInventory.o \
	cashierView.o customerView.o keypadController.o
	$(CXX) main.o order.o item.o registerController.o StoreInventory.o \
	cashierView.o customerView.o keypadController.o \
	-o $(EXECUTABLE)

main.o: main.cpp item.h order.h
	@$(CXX) -c main.cpp

order.o: order.h order.cpp
	@$(CXX) -c order.cpp

item.o: item.h item.cpp IItem.h
	@$(CXX) -c item.cpp

registerController.o: StoreInventory.o cashierView.o order.o item.o \
	item.o registerController.h registerController.cpp
	@$(CXX) -c registerController.cpp

keypadController.o: customerView.o order.o keypadController.h keypadController.cpp
	@$(CXX) -c keypadController.cpp

StoreInventory.o: StoreInventory.h StoreInventory.cpp
	@$(CXX) -c StoreInventory.cpp

cashierView.o: cashierView.h cashierView.cpp
	@$(CXX) -c cashierView.cpp

customerView.o: customerView.h customerView.cpp
	@$(CXX) -c customerView.cpp

clean:
	rm -f *.o *.gch $(EXECUTABLE)