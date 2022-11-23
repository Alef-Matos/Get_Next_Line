# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almatos <almatos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 10:20:21 by almatos           #+#    #+#              #
#    Updated: 2022/11/23 09:26:27 by almatos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gna.a

CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=n
CC = @cc
RM = @rm -f
AR = @ar -rcs
MSN = @echo "Congratulations ✔︎"

SOURCES	= get_next_line.c get_next_line_utils.c
OBJECTS	= $(SOURCES:.c=.o)

SOURCES_B	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJECTS_B	= $(SOURCES:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(AR) $(NAME) $(OBJECTS)
			@echo " "
			$(MSN)
			@echo " "

bonus:		$(NAME) $(OBJECTS_B)
			$(AR) $(NAME) $(OBJECTS_B)

clean:
			$(RM) $(OBJECTS)
			@echo " "
			$(MSN)
			@echo " "
			
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re