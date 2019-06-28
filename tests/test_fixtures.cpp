#include "test_fixtures.h"

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	// Roda todos os testes.
	return RUN_ALL_TESTS();
}
