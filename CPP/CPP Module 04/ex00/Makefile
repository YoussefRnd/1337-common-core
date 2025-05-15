NAME = Animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -fr
MKDIR = mkdir -p

OBJ_DIR = ./obj

HEADERS = $(wildcard ./*.hpp)
SRCS = $(wildcard ./*.cpp)
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(NAME) is ready!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "Cleaning $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(OBJ_DIR)