COMPOSE_FILE := srcs/docker-compose.yml

up:
	sudo docker compose -f $(COMPOSE_FILE) up -d

down:
	sudo docker compose -f $(COMPOSE_FILE) down

delete:
	sudo docker compose -f $(COMPOSE_FILE) down
	sudo docker rmi nginx-image wordpress-image mariadb-image || true
