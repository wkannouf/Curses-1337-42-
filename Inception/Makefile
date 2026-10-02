COMPOSE = docker-compose -f srcs/docker-compose.yml

all:
	$(COMPOSE) up -d --build

build:
	$(COMPOSE) build

up:
	$(COMPOSE) up -d

down:
	$(COMPOSE) down

restart:
	$(COMPOSE) restart

clean:
	$(COMPOSE) down

fclean:
	$(COMPOSE) down -v

re:
	$(COMPOSE) down -v
	$(COMPOSE) up -d --build
