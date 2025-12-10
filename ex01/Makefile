# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 09:14:13 by sidrissi          #+#    #+#              #
#    Updated: 2025/12/10 13:30:50 by sidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

FILES = main.cpp Serializer.cpp Data.cpp
OBJECT = $(FILES:.cpp=.o)
NAME = Serialization

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CXXFLAGS) $(OBJECT) -o $(NAME)

%.o: %.cpp Serializer.hpp Data.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all