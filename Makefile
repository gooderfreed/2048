NAME = 2048.a
NAMEBIN = 2048

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libmx

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.cpp=%.o)))

CC = g++
CFLAGS = -lGL -lglut -lGLU
AR = ar
AFLAGS = rcs
MAKE = make -C

MKDIR = mkdir -p
RM = rm -rf

all: $(NAMEBIN) clean

$(NAMEBIN): $(OBJ_FILES)
	@$(CC) $^ -o $@ $(CFLAGS)

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	@$(CC) -c $< -o $@ $(CFLAGS) 

$(OBJ_DIR):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(LIB_FILES)

uninstall:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAMEBIN)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall

