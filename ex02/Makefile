# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 09:14:13 by sidrissi          #+#    #+#              #
#    Updated: 2025/12/10 13:53:55 by sidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

FILES = A.cpp  Base.cpp  B.cpp  C.cpp  main.cpp
OBJECT = $(FILES:.cpp=.o)
NAME = Identify

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CXXFLAGS) $(OBJECT) -o $(NAME)

%.o: %.cpp A.hpp  Base.hpp  B.hpp  C.hpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all