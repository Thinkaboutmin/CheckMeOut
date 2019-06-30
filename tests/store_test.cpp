#include "test_fixtures.h"
#include "../src/StoreInventory.h"
#include <fstream>
#include <string>

TEST(BancoDeDados, item_cadastrado) {
	const char * database = ".tempDatabase.db";
	std::ofstream file;
	file.open(database);

	item banana = item(
			"Banana",
			12.25,
			0
			);

	file << std::fixed;
	file << std::setprecision(2);
	file << banana.getName() + " " + std::to_string(banana.getPrice()) + " " + std::to_string(banana.getSKU()) + "\n";

	file.close();
	
	StoreInventory inventory = StoreInventory(database);
	item unknown = inventory.lookup(0.00);

	std::remove(database);
	
	EXPECT_EQ(banana.getName(), unknown.getName());
	EXPECT_EQ(banana.getPrice(), unknown.getPrice());
	EXPECT_EQ(banana.getSKU(), unknown.getSKU());
}

TEST(BancoDeDados, item_nao_cadastrado) {
	const char * database = ".tempDatabase.db";
	std::ofstream file;
	file.open(database);

	item banana = item(
			"Banana",
			12.25,
			0
			);

	file << std::fixed;
	file << std::setprecision(2);
	file << banana.getName() + " " + std::to_string(banana.getPrice()) + " " + std::to_string(banana.getSKU()) + "\n";

	file.close();
	
	StoreInventory inventory = StoreInventory(database);
	item unknown = inventory.lookup(banana.getSKU()+ 1);
	
	std::remove(database);

	item unknownItem = item();

	EXPECT_EQ(unknownItem.getName(), unknown.getName());
	EXPECT_EQ(unknownItem.getPrice(), unknown.getPrice());
	EXPECT_EQ(unknownItem.getSKU(), unknown.getSKU());
}
