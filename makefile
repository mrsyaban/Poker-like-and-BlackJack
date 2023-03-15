# Compiler
CC			  = gcc

# Directory and files
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin
CPP_FILES     = $(wildcard $(SOURCE_FOLDER)/*.cpp)

# Flags
WARNING_CFLAG = -Wall -Wextra -Werror

run :
	build
	./$(OUTPUT_FOLDER)/WOI

build :
	$(CC) $(CPP_FILES) -o $(OUTPUT_FOLDER)/WOI $(WARNING_CFLAG)
	