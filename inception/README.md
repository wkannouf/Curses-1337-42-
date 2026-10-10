*This project has been created as part of the 42 curriculum by wkannouf.*

# Inception

## Description

Inception builds a small Docker Compose infrastructure on a virtual machine. It runs NGINX with TLS 1.2/1.3 as the only public entry point, WordPress with PHP-FPM, and MariaDB. WordPress files and database data persist in Docker named volumes.

Docker isolates application services in lightweight containers that share the host kernel; a virtual machine virtualizes a whole operating system. Secrets contain confidential values and are mounted as files, while environment variables carry non-sensitive configuration such as the domain name. Docker networks connect containers privately; host networking would remove that isolation. Docker volumes are managed by Docker and persist independently of containers, whereas bind mounts expose a chosen host directory directly to a container.

## Instructions

1. Configure Docker's `data-root` under `/home/wkannouf/data/docker` on the virtual machine.
2. Copy `srcs/.env.example` to `srcs/.env`, adapt its non-sensitive values, and create the four ignored files in `secrets/`.
3. Add `127.0.0.1 wkannouf.42.fr` to the virtual machine's `/etc/hosts` file.
4. Run `make`.
5. Open `https://wkannouf.42.fr`. A self-signed certificate warning is expected.

Use `make ps` to inspect services, `make logs` to follow logs, `make clean` to stop the stack while preserving data, and `make fclean` to remove this project's persistent volumes.

## Resources

- Docker documentation: https://docs.docker.com/
- Docker Compose documentation: https://docs.docker.com/compose/
- WordPress CLI documentation: https://wp-cli.org/
- NGINX documentation: https://nginx.org/en/docs/

## AI usage

AI was used to explain Docker concepts and to review the configuration. The implementation was checked manually, and the author must be able to explain every Dockerfile, Compose option, script, volume, network, and security choice during the evaluation.
