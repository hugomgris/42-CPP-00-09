# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 13:48:05 by hmunoz-g          #+#    #+#              #
#    Updated: 2025/02/27 09:44:17 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-    COLOURS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR   = \033[0;39m
YELLOW      = \033[0;93m
CYAN        = \033[0;96m
GREEN       = \033[0;92m
BLUE        = \033[0;94m
RED         = \033[0;91m

# -=-=-=-=-    NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

NAME        := formMaze

# -=-=-=-=-    FLAG -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

CPP          = c++
FLAGS       = -Werror -Wall -Wextra -std=c++98 -pedantic -g -fsanitize=address
DEPFLAGS    = -MMD -MP

# -=-=-=-=-    PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RM          = rm -fr
OBJ_DIR     = .obj
DEP_DIR     = .dep

# -=-=-=-=-    FILES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC         := main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp 

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEPS        = $(addprefix $(DEP_DIR)/, $(SRC:.cpp=.d))

# -=-=-=-=-    TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: directories $(NAME)

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

-include $(DEPS)

$(OBJ_DIR)/%.o: %.cpp 
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CPP) $(FLAGS) $(DEPFLAGS) -c $< -o $@ -MF $(DEP_DIR)/$*.d

$(NAME): $(OBJS) Makefile
	@echo "$(GREEN)Linking $(NAME)!$(DEF_COLOR)"
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
	@echo "$(RED)Have I talk to you about the difference between Maze and Labyrinth?$(DEF_COLOR)"

clean:
	@$(RM) $(OBJ_DIR) $(DEP_DIR)
	@echo "$(RED)Cleaned object files and dependencies$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re directories