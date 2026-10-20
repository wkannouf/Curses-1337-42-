# USER_DOC.md

## User Documentation

This document explains how to use and manage the Inception infrastructure.

## Services

The main services provided by the project are:

- **NGINX**: the main entry point of the website. It handles HTTPS connections on port 443.
- **WordPress + PHP-FPM**: runs the WordPress website and processes PHP requests.
- **MariaDB**: stores the WordPress database.

All services run in separate Docker containers and communicate through a Docker network.

## Start and Stop the Project

To build and start the infrastructure:

```bash
make
```

or:

```bash
make up
```

To stop and remove the containers:

```bash
make down
```

To remove containers, images, and volumes:

```bash
make fclean
```

To rebuild the images and recreate the containers:

```bash
make re
```

`make re` rebuilds the Docker images and recreates the containers while preserving the WordPress website files and MariaDB database stored under `/home/wkannouf/data/`. `make fclean` removes the Docker volume resources, but does not delete these host directories or their contents; `make re` therefore does not reset the project data.

## Access the Website

Make sure the project domain is configured in `/etc/hosts`:

```text
127.0.0.1 <login>.42.fr
```

Then open the website in a browser:

```text
https://<login>.42.fr
```

## WordPress Administration Panel

The WordPress administration panel is available at:

```text
https://<login>.42.fr/wp-admin
```

Log in using the WordPress administrator credentials configured for the project.

## Credentials

Project configuration and credentials are defined outside the Dockerfiles.

The environment configuration is located in:

```text
srcs/.env
```

This file contains values used by services such as MariaDB and WordPress.

Credentials should not be hardcoded inside Dockerfiles or application configuration committed to a public repository.

If credentials need to be changed, update the appropriate configuration values and recreate the containers when necessary.

## Check the Services

To display the current status of the containers:

```bash
make ps
```

Running services should normally appear with a status similar to:

```text
Up
```

To follow the logs of the services:

```bash
make logs
```

You can also check a specific container:

```bash
docker logs nginx
docker logs wordpress
docker logs mariadb
```

To list all running containers:

```bash
docker ps
```

If NGINX, WordPress, and MariaDB are running and the website is accessible through HTTPS, the main infrastructure is working correctly.
