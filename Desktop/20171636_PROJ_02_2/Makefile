CC = g++
TARGET = battleship
SOURCES = main.cpp \
            BattleShipApp.cpp \
            BattleShipMap.cpp \
            Pane.cpp \
            StatPane.cpp \
            InputPane.cpp \
            AutoSelect.cpp
LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
