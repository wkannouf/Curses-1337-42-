COMPOSE = docker compose -f srcs/docker-compose.yml

all: up

up:
	mkdir -p /home/wkannouf/data/mariadb
	mkdir -p /home/wkannouf/data/wordpress
	mkdir -p /home/wkannouf/data/portainer
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down --remove-orphans

<<<<<<< HEAD
logs:
	$(COMPOSE) logs -f

fclean:
	$(COMPOSE) down --volumes --rmi all --remove-orphans
=======
restart:
	$(COMPOSE) restart

clean:
	$(COMPOSE) down --volumes --remove-orphans

logs:
	$(COMPOSE) logs -f

fclean: clean
	docker system prune -af
>>>>>>> 69bdf28045a6b27ae988b57706be1a33bdbca9da

re: fclean all

ps:
	$(COMPOSE) ps

<<<<<<< HEAD
.PHONY: all up down logs fclean re ps
=======
.PHONY: all build up down restart clean logs fclean re ps

>>>>>>> 69bdf28045a6b27ae988b57706be1a33bdbca9da
