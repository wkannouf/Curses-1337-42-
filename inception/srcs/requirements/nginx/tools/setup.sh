#!/bin/bash

set -eu

certificate_dir="/etc/nginx/ssl"
certificate="$certificate_dir/wkannouf.42.fr.crt"
private_key="$certificate_dir/wkannouf.42.fr.key"

mkdir -p "$certificate_dir"

if [ ! -s "$certificate" ] || [ ! -s "$private_key" ]; then
    openssl req -x509 -nodes -days 365 \
        -newkey rsa:2048 \
        -keyout "$private_key" \
        -out "$certificate" \
        -subj "/C=MA/ST=Beni-Mellal-Khenifra/L=Khouribga/O=42/CN=wkannouf.42.fr"
fi

exec nginx -g 'daemon off;'
