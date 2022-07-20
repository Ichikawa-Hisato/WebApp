#!/bin/bash

source ./common_define.sh

docker run -it -d --network ${network_name} --ip ${ip_address_proxy} --name ${container_name_proxy} image_ubuntu
docker run -it -d --network ${network_name} --ip ${ip_address_skeleton} --name ${container_name_skeleton} image_ubuntu
docker ps
