# Compiler
CC			  = g++

# Directory and files
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

# All files
ABILITY_FILES = $(SOURCE_FOLDER)/Ability/Ability.cpp
ACTION_FILES  = $(SOURCE_FOLDER)/Action/Action.cpp
# ARRAYUTIL_FILES  = 
CARD_FILES  = $(SOURCE_FOLDER)/Card/Card.cpp
COMBO_FILES  = $(SOURCE_FOLDER)/Combo/Combo.cpp $(SOURCE_FOLDER)/Combo/SearchCombo.cpp 
DECK_FILES  = $(SOURCE_FOLDER)/Deck/Deck.cpp
GAME_FILES  = $(SOURCE_FOLDER)/Game/Game.cpp
INVENTORYHOLDER_FILES  = $(SOURCE_FOLDER)/InventoryHolder/InventoryHolder.cpp
IO_FILES  = $(SOURCE_FOLDER)/IO/IO.cpp
PLAYER_FILES  = $(SOURCE_FOLDER)/Player/Player.cpp
POINT_FILES  = $(SOURCE_FOLDER)/Point/Point.cpp
TABLE_FILES  = $(SOURCE_FOLDER)/Table/Table.cpp
MAIN_FILES    = $(SOURCE_FOLDER)/main.cpp

CPP_FILES := $(MAIN_FILES) $(TABLE_FILES) $(POINT_FILES) $(PLAYER_FILES) $(IO_FILES) $(INVENTORYHOLDER_FILES) $(GAME_FILES) $(DECK_FILES) $(COMBO_FILES) $(CARD_FILES) $(ACTION_FILES) $(ABILITY_FILES)

# All

# Flags
WARNING_CFLAG = -Wall -Wextra -Werror

run :
	build
	@$(OUTPUT_FOLDER)/WOI.exe

build :
	$(CC) $(CPP_FILES) -o $(OUTPUT_FOLDER)/WOI $(WARNING_CFLAG)
	