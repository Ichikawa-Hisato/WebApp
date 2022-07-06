#!/bin/bash

source ./common_define.sh

docker cp ./build/Receiver ${container_name_proxy}:${work_dir}
docker cp ./build/Sender ${container_name_skeleton}:${work_dir}
