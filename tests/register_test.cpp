#include "test_fixtures.h"
#include "../src/registerController.h"
#include <fstream>
#include <streambuf>
#include <iostream>
#include <string>

namespace CommandsCommon {
	std::stringstream buffer;

	std::streambuf * bkBuff = std::cout.rdbuf();
}

TEST(RegistroDeComando, adicionar_produto_registrado) {
	// Prepare database
	const char * database = ".tempDatabase.db";
	item caqui = item(
			"Caqui",
			13,
			0
			);
	std::ofstream file = std::ofstream();
	file.open(database);
	file << std::fixed;
	file << std::setprecision(2);
	file << caqui.getName() + " " + std::to_string(caqui.getPrice()) + " " + std::to_string(caqui.getSKU());
	file.close();

	StoreInventory  inventory = StoreInventory(database);
	order cart = order(0.7);
	registerController registerCommand = registerController(&inventory, &cart);

	// Change buffers
	std::istringstream command("buy 1000");
	std::streambuf * backup = std::cin.rdbuf();

	std::cin.rdbuf(command.rdbuf());
	std::cout.rdbuf(CommandsCommon::buffer.rdbuf());
	
	registerCommand.processOrder();

	std::string content = CommandsCommon::buffer.str();

	content.substr(0, 
			// TODO: not functional

}
