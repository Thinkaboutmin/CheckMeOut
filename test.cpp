#include <gtest/gtest.h>
#include "../src/order.h"
#include "../src/item.h"
#include <vector>

TEST(Order_Tax, Tax_set) {
	double tax = 0.7;
	order itemOrder = order(tax);
	
	EXPECT_EQ(itemOrder.getTax(), tax);
}

TEST(Order_Tax, Tax_set_negative) {
	double tax = -0.7;
	order itemOrder = order(tax);

	EXPECT_NE(itemOrder.getTax(), tax);
}


TEST(Order_Tax, Tax_without_products) {
	double tax = 0.7;
	order itemOrder = order(tax);

	EXPECT_EQ(itemOrder.getTotal(), 0);
}

TEST(Order_Add_Product, Add_a_product_to_the_order) {
	double tax = 0.7;
	order itemOrder = order(tax);

	item banana = item(
			"banana",
			12.25,
			0
			);

	itemOrder.addItem(banana);
	std::vector<item> items = itemOrder.getItems();
	item unknown = items.front();

	EXPECT_EQ(unknown.getName(), banana.getName());
	EXPECT_EQ(unknown.getPrice(), banana.getPrice());
	EXPECT_EQ(unknown.getSKU(), banana.getSKU());
}

TEST(Order, Tax_With_products) {
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
