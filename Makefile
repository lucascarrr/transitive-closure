CC = g++-13
FLAGS = -std=c++2a

SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/Main
TEST_TARGET = $(BIN_DIR)/Test

MAIN_OBJS = $(BIN_DIR)/Main.o
NODE_OBJS = $(BIN_DIR)/Node.o
NODE_TEST_OBJ = $(BIN_DIR)/NodeTest.o


$(TARGET): $(MAIN_OBJS)
	$(CC) $^ -o $(TARGET) $(FLAGS)

$(TEST_TARGET): $(NODE_OBJS) $(NODE_TEST_OBJ)
	$(CC) $^ -o $(TEST_TARGET) $(FLAGS)

$(MAIN_OBJS): $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/Main.cpp -o $(MAIN_OBJS) $(FLAGS)

$(NODE_OBJS): $(SRC_DIR)/node/Node.cpp $(SRC_DIR)/node/Node.h
	$(CC) -c $(SRC_DIR)/node/Node.cpp -o $(NODE_OBJS) $(FLAGS)

$(NODE_TEST_OBJ): $(SRC_DIR)/tests/NodeTest.cpp $(SRC_DIR)/node/Node.h
	$(CC) -c $(SRC_DIR)/tests/NodeTest.cpp -o $(NODE_TEST_OBJ) $(FLAGS)

clean:
	rm -f $(BIN_DIR)/*.o
	rm -f $(TEST_TARGET)
	rm -f $(TARGET)

main: $(TARGET)
	chmod 700 $(TARGET)
	./$(TARGET)

.PHONY: test
test: $(TEST_TARGET)
	chmod 700 $(TEST_TARGET)
	./$(TEST_TARGET)
