CC = gcc
CFLAGS = -Wall -Isrc -Isrc/hardware

SRC = src
BUILD = build

SOURCES = $(shell find $(SRC) -name '*.c')
SRC_DIRS = $(shell find $(SRC) -mindepth 1 -type d)

OBJECTS = $(patsubst $(SRC)/%.c,$(BUILD)/%.c.o,$(SOURCES))
OBJ_DIRS = $(patsubst $(SRC)/%,$(BUILD)/%,$(SRC_DIRS))

MAIN = Simulator

.PHONY: all compile link run clean

all: compile link clean

$(BUILD)/%.c.o: $(SRC)/%.c | $(BUILD)
	@echo "   - $< => $@"
	$(CC) $(CFLAGS) -o $@ -c $<

compile: $(SOURCES)
	@echo "-- Compiling"

link: $(OBJECTS)
	@echo "-- Linking $(MAIN)"
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJECTS)

run: compile link
	@echo "-- Running ./$(MAIN)"
	./$(MAIN)

clean:
	@echo "-- Cleaning"
	@rm -rf $(BUILD) $(OBJ_DIRS)

$(BUILD):
	@mkdir -p $(BUILD) $(OBJ_DIRS)

