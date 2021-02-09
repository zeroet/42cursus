#!/bin/bash

# ssl - authentication
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=FR/ST=Paris/L=Paris/O=42Paris/OU=Yun/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

#nginx
sed -i "s|autoindex on;|${AUTO};|g" ${TODIR}/default
cp -rp /tmp/default /etc/nginx/sites-available/

#wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./tmp/wp-config.php /var/www/html/wordpress

#DB
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql
echo "CREATE USER IF NOT EXISTS 'seyun'@'localhost' IDENTIFIED BY 'seyun';" | mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'seyun'@'localhost' WITH GRANT OPTION;" | mysql
echo "flush privileges;" | mysql

#phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp /tmp/config.inc.php /var/www/html/phpmyadmin/

service php7.3-fpm start
service mysql restart
nginx -g 'daemon off;'

bash
