NAME=game

all: $(NAME)

$(NAME):
	gcc main.cpp GameTile.cpp GameTile.h GameWorld.cpp GameWorld.h GameEntity.h Player.cpp Player.h GameEntity.cpp sfml-system sfml-window sfml-graphics -o $(NAME)

clean: rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re