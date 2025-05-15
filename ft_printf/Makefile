NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
MK = mkdir -p


SRC = ./src
OBJDIR = ./obj
INCLUDE = ./include

HEADER = $(INCLUDE)/ft_printf.h

SRCS = $(SRC)/ft_printf.c \
	$(SRC)/ft_putchar.c \
	$(SRC)/ft_putstr.c \
	$(SRC)/ft_putnbr.c \
	$(SRC)/ft_puthex.c \

OBJS = $(SRCS:$(SRC)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating archive $(NAME)..."
	@$(AR) $(NAME) $(OBJS)
	@echo "Done creating $(NAME)."

$(OBJDIR)/%.o: $(SRC)/%.c $(HEADER)
	@$(MK) $(@D)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo "Created!"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)
	@echo "Done cleaning"

fclean:
	@echo "Cleaning all files..."
	@$(RM) $(NAME) $(OBJS)
	@echo "Done cleaning all."

re: fclean all

.PHONY: all clean fclean re