COMPOSE := docker compose -f srcs/docker-compose.yml

all: up

build:
	$(COMPOSE) build

up:
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down --remove-orphans

restart:
	$(COMPOSE) restart

clean: down

logs:
	$(COMPOSE) logs -f

fclean:
	$(COMPOSE) down --volumes --remove-orphans

re:
	$(MAKE) fclean
	$(MAKE) all

ps:
	$(COMPOSE) ps

.PHONY: all build up down restart clean logs fclean re ps
