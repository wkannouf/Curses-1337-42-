COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

up:
	mkdir -p /home/wkannouf/data/mariadb
	mkdir -p /home/wkannouf/data/wordpress
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down --remove-orphans

logs:
	$(COMPOSE) logs -f

fclean:
	$(COMPOSE) down --volumes --rmi all --remove-orphans

re: fclean all

ps:
	$(COMPOSE) ps

.PHONY: all up down logs fclean re ps
