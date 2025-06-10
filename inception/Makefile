COMPOSE_FILE := srcs/docker-compose.yml

up:
	sudo docker compose -f $(COMPOSE_FILE) up -d

down:
	sudo docker compose -f $(COMPOSE_FILE) down

delete:
	sudo docker compose -f $(COMPOSE_FILE) down
	sudo docker rmi nginx-image wordpress-image mariadb-image || true

re:
	sudo docker compose -f $(COMPOSE_FILE) down
	sudo docker rmi nginx-image wordpress-image mariadb-image || true
	sudo docker compose -f $(COMPOSE_FILE) up -d

delete_all:
	sudo docker compose -f $(COMPOSE_FILE) down
	sudo docker rmi nginx-image wordpress-image mariadb-image || true
	sudo rm -rf /home/user4/data/mariadb/*
	sudo rm -rf /home/user4/data/wordpress/*
	mkdir -p /home/user4/data/mariadb /home/user4/data/wordpress

re_all:
	sudo docker compose -f $(COMPOSE_FILE) down
	sudo docker rmi nginx-image wordpress-image mariadb-image || true
	sudo rm -rf /home/user4/data/mariadb/*
	sudo rm -rf /home/user4/data/wordpress/*
	mkdir -p /home/user4/data/mariadb /home/user4/data/wordpress
	sudo docker compose -f $(COMPOSE_FILE) up -d

