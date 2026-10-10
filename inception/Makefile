COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

build:
	$(COMPOSE) build

up:
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down --remove-orphans

restart:
	$(COMPOSE) restart

clean:
	$(COMPOSE) down --volumes --remove-orphans

logs:
	$(COMPOSE) logs -f

fclean: clean
	docker system prune -af

re: fclean all

ps:
	$(COMPOSE) ps

.PHONY: all build up down restart clean logs fclean re ps

