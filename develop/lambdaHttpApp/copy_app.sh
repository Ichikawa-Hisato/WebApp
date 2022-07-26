#!/bin/bash

source ./common_define.sh

docker cp ./build ${container_name_server}:${work_dir}
docker cp ./build ${container_name_client}:${work_dir}
