#!/bin/bash

source ./common_define.sh

docker cp ./build/http_server ${container_name_server}:${work_dir}
docker cp ./build/http_client ${container_name_client}:${work_dir}
