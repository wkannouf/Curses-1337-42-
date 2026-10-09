# User documentation

## Services

The stack provides a WordPress website through NGINX over HTTPS, with MariaDB as its database.

## Start and stop

Run `make` in the repository root to build and start the stack. Run `make clean` to stop it without removing website or database data. Run `make fclean` only when a complete reset is wanted.

## Access

Open `https://wkannouf.42.fr` in a browser. The WordPress administration panel is at `https://wkannouf.42.fr/wp-admin`.

## Credentials

The local `srcs/.env` file contains non-sensitive configuration. Passwords are stored in the ignored files under `secrets/`. Do not commit either of them. The administrator username must not include `admin` or `Admin`.

## Health checks

Run `make ps` to view container status and `make logs` to follow service logs. The website should only be accessible through HTTPS on port 443.
