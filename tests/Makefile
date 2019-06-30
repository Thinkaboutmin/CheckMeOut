EXECUTABLE=TestsCheckMeOut
CXX=g++

all: main.o item.o order.o cashierView.o interface_test.o  \
	order_test.o store_inventory.o store_test.o
	@$(CXX) main.o order.o item.o cashierView.o interface_test.o \
		order_test.o store_test.o store_inventory.o \
		-lgtest -o $(EXECUTABLE) 

main.o: test_fixtures.h test_fixtures.cpp
	@$(CXX) -lgtest -c test_fixtures.cpp -o main.o

order.o: ../src/order.h ../src/order.cpp
	@$(CXX) -c ../src/order.cpp

item.o: ../src/item.h ../src/item.cpp ../src/IItem.h
	@$(CXX) -c ../src/item.cpp

cashierView.o: ../src/cashierView.h ../src/cashierView.cpp
	@$(CXX) -c ../src/cashierView.cpp

interface_test.o: interface_test.cpp
	@$(CXX) -c interface_test.cpp

order_test.o: order_test.cpp
	@$(CXX) -c order_test.cpp

store_inventory.o: ../src/StoreInventory.cpp ../src/StoreInventory.h
	@$(CXX) -c ../src/StoreInventory.cpp -o store_inventory.o

store_test.o: store_test.cpp
	@$(CXX) -c store_test.cpp

clear:
	rm -f *.o *.gch $(EXECUTABLE)
