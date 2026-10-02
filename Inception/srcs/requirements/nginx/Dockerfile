FROM debian:12

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/wkannouf.42.fr.key \
    -out /etc/nginx/ssl/wkannouf.42.fr.crt \
    -subj "/C=MA/ST=Beni-Mellal-Khenifra/L=Khouribga/O=42/CN=wkannouf.42.fr"

COPY conf/default.conf /etc/nginx/sites-available/default

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
