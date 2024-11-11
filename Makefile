# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 02:30:34 by olarseni          #+#    #+#              #
#    Updated: 2024/11/11 03:16:53 by olarseni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 DEFINITIONS                                  #
################################################################################

#==============#
# PROGRAM NAME #
#==============#
NAME		=	merge_sort

#=====================#
# Sources directories #
#=====================#
SDIR		=	srcs
SDIR_LISTS	=	$(SDIR)/list_utils
SDIR_MERGE	=	$(SDIR)/merge_utils

#===============#
# Sources files #
#===============#
SRCS	=	$(shell find $(SDIR) -type f -name '*.c')

#=====================#
# Objects directories #
#=====================#
ODIR	=	objects

#===============#
# Objects files #
#===============#
OBJS	=	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))


#=====================#
# Include directories #
#=====================#
IDIR	=	includes

#=======#
# LIBFT #
#=======#
LDIR	=	libft
LIBFT	=	libft

#==========#
# Compiler #
#==========#
CC	=	cc

#=======#
# FLAGS #
#=======#
CFLAGS	=	-Wall -Wextra -Werror -g
IFLAGS	=	-I$(IDIR) -I$(LDIR)
LFLAGS	=	-L$(LDIR) -lft

################################################################################
#                                  COLORS                                      #
################################################################################
#TODO

################################################################################
#                                   RULES                                      #
################################################################################

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< $(IFLAGS) -o $@

all: $(LIBFT) $(NAME)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(ODIR):
	@mkdir -p $(ODIR)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT)
	@echo "COMPILE $(NAME)"
	$(CC) $(CFLAGS) $^ $(IFLAGS) -o $@ $(LFLAGS)
	@echo "FINISHED!"

$(LIBFT):

.PHONY: all clean fclean re
