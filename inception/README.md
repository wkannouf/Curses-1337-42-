*This project has been created as part of the 42 curriculum by wkannouf.*

# Inception

## Description

Inception is a system administration and DevOps project where I build a small web infrastructure using Docker. The main goal is to understand how containers work, how different services communicate, and how to manage networking, persistent data, environment variables, and security.

The project mainly includes NGINX, WordPress with PHP-FPM, and MariaDB. Each service runs in its own container and is built from a custom Dockerfile. NGINX acts as the only entry point and handles HTTPS connections with TLS, while WordPress communicates with MariaDB through a Docker network. Docker volumes are used to keep important data persistent even if containers are removed or recreated.

Docker Compose is used to manage the services, and a Makefile provides simple commands to build, start, stop, and clean the infrastructure.

### Project Design

The project is split into separate Docker containers, with each container running one main service.

- **NGINX** is the only entry point and handles HTTPS connections on port 443 using TLS.
- **WordPress** runs with PHP-FPM and communicates with NGINX using FastCGI.
- **MariaDB** runs in its own container and stores the WordPress database.
- All services communicate through a dedicated Docker network.
- Docker named volumes are used to keep WordPress files and MariaDB data persistent.
- Docker Compose is used to manage the services, networks, and volumes.
- A Makefile is used to simplify common commands such as build, start, stop, and clean.

The project also includes custom Dockerfiles, configuration files, setup scripts, environment files, and the Docker Compose configuration.

### Virtual Machines vs Docker

A virtual machine runs a full operating system with its own kernel, so it usually uses more resources and takes longer to start.

Docker containers share the host kernel and isolate applications using Linux features such as namespaces and cgroups. This makes them lighter and faster than virtual machines.

### Secrets vs Environment Variables

Environment variables are a simple way to pass configuration values to containers, but sensitive values may be visible in the container configuration.

Secrets are more suitable for passwords and other sensitive information because they are kept separate from the image and normal application configuration.

Passwords and credentials should not be hardcoded in Dockerfiles or committed to the repository.

### Docker Network vs Host Network

A Docker network gives containers an isolated network where they can communicate using service names such as `wordpress:9000` and `mariadb:3306`.

With host networking, the container uses the host network directly, which reduces network isolation.

This project uses a dedicated Docker network so the services can communicate internally while NGINX remains the only external entry point.

### Docker Volumes vs Bind Mounts

Docker volumes are managed by Docker and are mainly used for persistent data that should remain available even if containers are removed or recreated.

Bind mounts directly connect a directory or file from the host system to a path inside the container.

This project uses Docker named volumes for WordPress files and MariaDB data to keep them persistent.

## Instructions

### Requirements

Before running the project, make sure you have:

- Docker
- Docker Compose
- Make
- Git

### Installation

Clone the repository:

```bash
git clone https://github.com/wkannouf/Curses-1337-42-
cd Curses-1337-42-/inception
```

### Build and Run

To build the Docker images and start the infrastructure:

```bash
make
```

Or:

```bash
make up
```

The project will start the NGINX, WordPress, and MariaDB containers using Docker Compose.

### Access the Website

Make sure the project domain is configured in `/etc/hosts`, for example:

```text
127.0.0.1 wkannouf.42.fr
```

Then open:

```text
https://wkannouf.42.fr
```

### Useful Commands

To display the current status of the containers:

```bash
make ps
```

To follow the logs of the services:

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

Clean and rebuild the project when needed:

```bash
make re
```

`make re` rebuilds the Docker images and recreates the containers while preserving the WordPress website files and MariaDB database stored under `/home/wkannouf/data/`. `make fclean` removes the Docker volume resources, but does not delete these host directories or their contents; `make re` therefore does not reset the project data.

## Resources

The main reference used for this project was the official Docker documentation:

- Docker Documentation: https://docs.docker.com/

## AI usage

I also used AI as a learning and review tool. It was mainly used to get clearer explanations of Docker concepts, understand parts of the project in more detail, and review my code or configuration for possible mistakes.

AI was not used to replace the implementation of the project, but to help me better understand the technologies and verify my work.
