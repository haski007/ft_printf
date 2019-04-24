# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/10 12:32:00 by pdemian           #+#    #+#              #
#    Updated: 2019/03/10 12:32:04 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CCFLAGS = -O3

INCL = includes/

ODIR = obj/
SDIR = src
INCS = includes/ft_printf.h
SRC =	types_a.c types_b.c x_type.c manage.c\
		ft_printf.c parsing.c

vpath %.c src/

OBJS = $(addprefix $(ODIR),$(SRC:.c=.o))

LIB_O = ft_memset.o ft_bzero.o ft_memcpy.o ft_strlen.o ft_memchr.o ft_memcmp.o ft_strcpy.o ft_strdup.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strchr.o\
		ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_isdigit.o ft_atoi.o ft_isascii.o ft_isalpha.o ft_isalnum.o ft_tolower.o ft_isprint.o\
		ft_toupper.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o\
		ft_strjoin.o ft_strsub.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putchar_fd.o ft_putendl.o ft_putnbr.o ft_putnbr_fd.o ft_putstr_fd.o\
		ft_putendl_fd.o ft_memccpy.o ft_strlcat.o ft_memmove.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_numlen.o ft_swap.o ft_sqrt.o\
		ft_free_arr.o ft_foreach.o ft_power.o itoa_base.o floatoa.o ft_strndup.o ft_strrew.o ft_u_itoa.o u_itoa_base.o ft_del.o

LO = $(addprefix libft/.obj/,$(LIB_O))

MAKE = make

all: $(NAME)

$(NAME): $(ODIR) $(OBJS)
	@ar -rcT $(NAME) $(OBJS) $(LO)
	@ranlib $(NAME)
	@echo \\033[32m======[Compiled]========\\033[0m

$(ODIR): FORCE
	@mkdir -p $(ODIR)
	make -C libft

$(ODIR)%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I $(INCL) -o $@ -c $<

clean:
	make clean -C libft/
	@rm -rf $(OBJS) $(ODIR)
	@echo \\033[34m======[Cleaned]=========\\033[0m

fclean: clean
	make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re FORCE

#NAME :=		ft_printf
#
#SRCDIR :=	src/
#INCDIR :=	includes/
#LIBDIR :=	libft/
#OBJDIR :=	.obj/
#
#CC :=		clang
#CFLAGS :=	-Wall -Wextra -Werror
#IFLAGS :=	-I $(INCDIR)
#LFLAGS :=	-lft -L $(LIBDIR)
#
#LIB :=		$(LIBDIR)libft.a
#INC :=		ft_printf
#SRC :=		ft_printf main parsing types_a types_b x_type manage
#
#INCS :=		$(addprefix $(INCDIR), $(addsuffix .h, $(INC)))
#SRCS :=		$(addprefix $(SRCDIR), $(addsuffix .c, $(SRC)))
#OBJS :=		$(addprefix $(OBJDIR), $(SRCS:%.c=%.o))
#
#all: $(NAME)
#
#$(NAME):	$(LIB) $(OBJDIR) $(OBJS)
#	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
#$(LIB):
#	@ make -C $(LIBDIR) libft.a
#
#$(OBJDIR):
#	mkdir -p $(OBJDIR)$(SRCDIR)
#$(OBJDIR)%.o:		%.c $(INCS)
#	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
#
#mclean:
#	rm -rf $(OBJDIR)
#mfclean: mclean
#	rm -rf $(NAME)
#mre: mfclean all
#
#clean: mclean
#	make clean -C $(LIBDIR)
#fclean: clean mfclean
#	make fclean -C $(LIBDIR)
#re: fclean all
#
#.PHONY: $(LIB) all clean fclean re
#