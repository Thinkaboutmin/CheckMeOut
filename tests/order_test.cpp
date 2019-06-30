#include "test_fixtures.h"

#include <vector>

namespace Common {
	double tax = 0.7;
	order itemOrderTax = order(tax);

	item banana = item(
			"banana",
			12.25,
			0
			);
}

TEST(Taxa, ordinaria) {
	// Testa se a taxa passada permanece igual.
	EXPECT_EQ(Common::itemOrderTax.getTax(), Common::tax);
}

TEST(Taxa, negativa) {
	double tax = -0.7;
	order itemOrder = order(tax);

	// Espera que o valor não seja negativo, pois taxa
	// não pode ser negativa.
	EXPECT_NE(itemOrder.getTax(), tax);
}


TEST(TotalTaxa, sem_produtos) {
	// O total, sem produtos, deve ser 0.
	EXPECT_EQ(Common::itemOrderTax.getTotal(), 0);
}

TEST(TotalTaxa, com_produto) {
	order itemOrder = order(Common::tax);

	item banana = item(
			"banana",
			12.25,
			0
			);
	itemOrder.addItem(banana);

	// Calcula a diferença da taxa.
	double expectedTotal = banana.getPrice() * (1 + Common::tax);
	// Compara com o resultado vindo da taxa.
	EXPECT_EQ(itemOrder.getTotal(), expectedTotal);
}

TEST(SubtotalTaxa, sem_produto) {
	// Resultado deve ser 0 do subtotal quando estamos sem produtos.
	EXPECT_EQ(Common::itemOrderTax.getSubtotal(), 0);
}

TEST(SubtotalTaxa, com_produto) {
	order itemOrder = order(Common::tax);

	itemOrder.addItem(Common::banana);

	// Testa se o resultado vai ser o mesmo preço da banana.
	EXPECT_EQ(itemOrder.getSubtotal(), Common::banana.getPrice());
}

TEST(Pedido, verifica_produto) {
	order itemOrder = order(Common::tax);


	itemOrder.addItem(Common::banana);
	std::vector<item> items = itemOrder.getItems();
	item unknown = items.front();
	
	// Os registros dos produtos devem ser iguais
	// aqueles passados.
	EXPECT_EQ(unknown.getName(), Common::banana.getName());
	EXPECT_EQ(unknown.getPrice(), Common::banana.getPrice());
	EXPECT_EQ(unknown.getSKU(), Common::banana.getSKU());
}

TEST(PagarPedido, sem_produto) {
	order itemOrder = order(Common::tax);

	double paidPrice = 10.0;

	double totalPaid = itemOrder.balance(paidPrice);

	EXPECT_EQ(0, totalPaid);
}

TEST(PagarPedido, com_produto) {
	order itemOrder = order(Common::tax);

	itemOrder.addItem(Common::banana);
	double pricePaid = Common::banana.getPrice() + 10;

	double totalPaid = itemOrder.balance(pricePaid);

	EXPECT_EQ(10, totalPaid);
}

