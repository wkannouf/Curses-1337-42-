# Developer documentation

## Prerequisites

Use a Debian virtual machine with Docker Engine and the Docker Compose plugin. Configure Docker's `data-root` as `/home/wkannouf/data/docker`; Docker named volumes will then persist under `/home/wkannouf/data/docker/volumes` without bind mounts.

Copy `srcs/.env.example` to `srcs/.env`; it defines `DOMAIN_NAME`, `MYSQL_DATABASE`, `MYSQL_USER`, `WP_ADMIN_USER`, `WP_ADMIN_EMAIL`, `WP_USER`, and `WP_USER_EMAIL`. Create the ignored secret files `secrets/db_password.txt`, `secrets/db_root_password.txt`, `secrets/wp_admin_password.txt`, and `secrets/wp_user_password.txt`, then protect them with `chmod 600 secrets/*.txt`.

## Build and run

Run `make` from the repository root. It runs Docker Compose with `srcs/docker-compose.yml`, builds the images, and starts the stack. Use `make build` to build without starting services, `make ps` to inspect status, and `make logs` to follow logs.

## Managing data

`db_data` is mounted at `/var/lib/mysql` for MariaDB. `wordpress_data` is mounted at `/var/www/html` for WordPress and NGINX. `make clean` preserves both volumes. `make fclean` removes only this Compose project's volumes, after which a new `make` performs a fresh initialization.

## Validation

Use `docker compose -f srcs/docker-compose.yml config` after creating local configuration files. Test TLS with `curl -kI https://wkannouf.42.fr`; plain HTTP on port 80 must not be reachable. Reboot the virtual machine, run `make`, and verify that the WordPress content and MariaDB data remain present.
