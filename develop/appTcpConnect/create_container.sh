#!/bin/bash

source ./common_define.sh

docker run -it -d --network ${network_name} --ip ${ip_address_proxy} --name ${container_name_proxy} ubuntu
docker run -it -d --network ${network_name} --ip ${ip_address_skeleton} --name ${container_name_skeleton} ubuntu
docker ps
