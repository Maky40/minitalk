# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 11:53:32 by mnie              #+#    #+#              #
#    Updated: 2024/02/18 14:17:15 by mnie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS1 = main_server.c minitalk_utils.c
SRCS2 = main_client.c
SRCS1_BONUS = main_server_bonus.c minitalk_utils_bonus.c
SRCS2_BONUS = main_client_bonus.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJS1_BONUS = $(SRCS1_BONUS:.c=.o)
OBJS2_BONUS = $(SRCS2_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra -g
CC = cc $(FLAGS)

LIBFT = libft/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	cd libft && make

$(SERVER): $(OBJS1)
	$(CC) $(OBJS1) $(LIBFT) -o $@

$(CLIENT): $(OBJS2)
	$(CC) $(OBJS2) $(LIBFT) -o $@

$(SERVER_BONUS): $(OBJS1_BONUS)
	$(CC) $(OBJS1_BONUS) $(LIBFT) -o $@

$(CLIENT_BONUS): $(OBJS2_BONUS)
	$(CC) $(OBJS2_BONUS) $(LIBFT) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS1) $(OBJS2) $(OBJS1_BONUS) $(OBJS2_BONUS)
	cd libft && make clean

fclean: clean
	cd libft && make fclean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus

