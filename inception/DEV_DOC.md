# DEV_DOC.md

## Developer Documentation

This document explains how to set up, build, run, and manage the Inception project from a developer point of view.

## Environment Setup

### Prerequisites

Before starting, make sure the following tools are installed:

- Docker
- Docker Compose
- Make
- Git

Clone the repository and move into the project directory:

```bash
git clone https://github.com/wkannouf/Curses-1337-42-
cd Curses-1337-42-/inception
```

### Configuration

The main Docker Compose file is located at:

```text
srcs/docker-compose.yml
```

The environment configuration is stored in:

```text
srcs/.env
```

This file contains values used by services such as MariaDB and WordPress.

Sensitive values should not be hardcoded inside Dockerfiles.

If secrets are used, they should be stored outside the Docker images and outside the public repository.

## Build and Launch the Project

The Makefile is used to simplify project management.

To build the images and start all services:

```bash
make
```

or:

```bash
make up
```

This command creates the required host directories, builds the Docker images, creates the containers, networks, and volumes, and starts the infrastructure in detached mode.

The project can also be started directly with Docker Compose:

```bash
docker compose -f srcs/docker-compose.yml up --build -d
```

## Manage Containers

Check the status of the services:

```bash
make ps
```

or:

```bash
docker compose -f srcs/docker-compose.yml ps
```

Follow the logs:

```bash
make logs
```

Stop and remove the containers:

```bash
make down
```

Remove containers, volumes, images, and orphan containers:

```bash
make fclean
```

Rebuild the images and recreate the containers:

```bash
make re
```

`make re` rebuilds the Docker images and recreates the containers while preserving the WordPress website files and MariaDB database stored under `/home/wkannouf/data/`. `make fclean` removes the Docker volume resources, but does not delete these host directories or their contents; `make re` therefore does not reset the project data.

List running containers:

```bash
docker ps
```

Inspect a specific container:

```bash
docker inspect <container_name>
```

Open a shell inside a running container:

```bash
docker exec -it <container_name> bash
```

## Manage Volumes

List Docker volumes:

```bash
docker volume ls
```

Inspect a specific volume:

```bash
docker volume inspect <volume_name>
```

The main persistent volumes are used for:

- WordPress files
- MariaDB database data

Removing a container does not automatically remove its persistent volume.

Using:

```bash
make fclean
```

removes the project volumes as well.

## Persistent Data

The project stores persistent data on the host under:

```text
/home/wkannouf/data/
```

The main directories are:

```text
/home/wkannouf/data/wordpress
/home/wkannouf/data/mariadb
/home/wkannouf/data/portainer
```

These directories are used by Docker volumes and are mounted into the corresponding containers.

For example:

```text
WordPress:
host -> /home/wkannouf/data/wordpress
container -> /var/www/html
```

```text
MariaDB:
host -> /home/wkannouf/data/mariadb
container -> /var/lib/mysql
```

This allows important data to remain available even if the containers are stopped, removed, or recreated.

The containers themselves are temporary, while the persistent data is stored separately through Docker volumes.
