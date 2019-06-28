#include "test_fixtures.h"
#include <streambuf>
#include <iostream>

namespace InterfaceCommon {
	double tax = 0.0;
	std::stringstream buffer;
	std::streambuf *sbuf = std::cout.rdbuf();
}

TEST(InterfaceCorreta, verifica_interface_caixa_ordem_vazia) {
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
	InterfaceCommon::buffer.clear();

	// Clean our junk so no leakage. The planet is thankful as well.

	EXPECT_EQ(screen, returnedScreen);
}
