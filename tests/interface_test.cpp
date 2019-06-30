#include "test_fixtures.h"
#include <streambuf>
#include <iostream>

namespace InterfaceCommon {
	double tax = 0.0;
	std::stringstream buffer;
	std::streambuf *sbuf = std::cout.rdbuf();
}

TEST(InterfaceEmCompra, caixa_ordem_vazia) {
	std::cout.rdbuf(InterfaceCommon::buffer.rdbuf());

	cashierView cashView = cashierView();

	order cart = order(InterfaceCommon::tax);

	cashView.displayRunningTotal(order(InterfaceCommon::tax));

	std::string divisor = "================\n";
	std::string cashierTitle = "CASHIER'S SCREEN\n";
	std::stringstream precision;
	precision << std::fixed;
	precision << std::setprecision(2);
	precision << cart.getSubtotal();
	std::string subTotal = "SUBTOTAL: $" + precision.str() + "\n";
	precision.clear();
	//std::string taxes = "TAXES: $" + std::to_string(cart.getTax()) + "\n";
	//std::string separator = "----------------";
	//std::string total = "TOTAL: $" + std::to_string(cart.getTotal()) + "\n";
	
	std::string screen = divisor + cashierTitle + subTotal + divisor;
	InterfaceCommon::buffer << std::setprecision(2) << InterfaceCommon::sbuf;
	std::string returnedScreen = InterfaceCommon::buffer.str();

	std::cout.rdbuf(InterfaceCommon::sbuf);

	// Clean buffer
	InterfaceCommon::buffer.str(std::string());

	EXPECT_EQ(screen, returnedScreen);
}

TEST(InterfaceEmCompra, caixa_com_item) {	
	double tax = 0.7;
	order cart = order(tax);
	item banana = item(
			"Banana",
			12.25,
			0
			);
	cart.addItem(banana);

	cashierView cashView = cashierView();

	std::cout.rdbuf(InterfaceCommon::buffer.rdbuf());
	cashView.displayRunningTotal(cart);

	std::string divisor = "================\n";
	std::string cashierTitle = "CASHIER'S SCREEN\n";

	std::stringstream precision;
	precision << std::fixed;
	precision << std::setprecision(2);
	precision << banana.getPrice();
	std::string cashierProducts =  banana.getName() + " $" + precision.str() + "\n";
	precision.str(std::string());

	precision << cart.getSubtotal();
	std::string subTotal = "SUBTOTAL: $" + precision.str() + "\n";
	precision.clear();
	
	std::string screen = divisor + cashierTitle + cashierProducts + subTotal + divisor;
	InterfaceCommon::buffer << std::setprecision(2) << InterfaceCommon::sbuf;
	std::string returnedScreen = InterfaceCommon::buffer.str();

	std::cout.rdbuf(InterfaceCommon::sbuf);
	InterfaceCommon::buffer.str(std::string());

	EXPECT_EQ(screen, returnedScreen);
}

TEST(InterfaceFinal, caixa_ordem_vazia) {
	std::cout.rdbuf(InterfaceCommon::buffer.rdbuf());

	cashierView cashView = cashierView();

	order cart = order(InterfaceCommon::tax);

	cashView.displayFinalReceipt(cart);

	std::string divisor = "================\n";
	std::string cashierTitle = "CASHIER'S SCREEN\n";
	std::stringstream precision;
	precision << std::fixed;
	precision << std::setprecision(2);
	precision << cart.getSubtotal();
	std::string subTotal = "SUBTOTAL: $" + precision.str() + "\n";
	precision.str(std::string());

	precision << cart.getTax();
	std::string taxes = "TAXES: $" + precision.str() + "\n";
	precision.str(std::string());

	std::string separator = "----------------\n";

	precision << cart.getTotal();
	std::string total = "TOTAL: $" + precision.str() + "\n";
	precision.clear();
	
	std::string screen = divisor + cashierTitle  + subTotal + taxes + separator + total + divisor;
	InterfaceCommon::buffer << std::setprecision(2) << InterfaceCommon::sbuf;
	std::string returnedScreen = InterfaceCommon::buffer.str();

	std::cout.rdbuf(InterfaceCommon::sbuf);
	InterfaceCommon::buffer.str(std::string());

	// Clean our junk so no leakage. The planet is thankful as well.

	EXPECT_EQ(screen, returnedScreen);
}

TEST(InterfaceFinal, caixa_com_item) {	
	std::cout.rdbuf(InterfaceCommon::buffer.rdbuf());

	cashierView cashView = cashierView();

	order cart = order(InterfaceCommon::tax);
	item banana =item(
			"Banana",
			12.25,
			0
			);
	cart.addItem(banana);

	cashView.displayFinalReceipt(cart);

	std::string divisor = "================\n";
	std::string cashierTitle = "CASHIER'S SCREEN\n";
	std::stringstream precision;
	precision << std::fixed;
	precision << std::setprecision(2);
	precision << banana.getPrice();
	std::string products = banana.getName() +  " $" + precision.str() + "\n";
	precision.str(std::string());

	precision << cart.getSubtotal();
	std::string subTotal = "SUBTOTAL: $" + precision.str() + "\n";
	precision.str(std::string());

	precision << cart.getTax();
	std::string taxes = "TAXES: $" + precision.str() + "\n";
	precision.str(std::string());

	std::string separator = "----------------\n";

	precision << cart.getTotal();
	std::string total = "TOTAL: $" + precision.str() + "\n";
	precision.clear();
	
	std::string screen = divisor + cashierTitle + products + subTotal + taxes + separator + total + divisor;
	InterfaceCommon::buffer << std::setprecision(2) << InterfaceCommon::sbuf;
	std::string returnedScreen = InterfaceCommon::buffer.str();

	std::cout.rdbuf(InterfaceCommon::sbuf);
	InterfaceCommon::buffer.str(std::string());

	// Clean our junk so no leakage. The planet is thankful as well.

	EXPECT_EQ(screen, returnedScreen);
}
