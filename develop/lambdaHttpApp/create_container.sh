#!/bin/bash

source ./common_define.sh

docker run -it -d --network ${network_name} --ip ${ip_address_server} --name ${container_name_server} image_ubuntu
docker run -it -d --network ${network_name} --ip ${ip_address_client} --name ${container_name_client} image_ubuntu
docker ps
