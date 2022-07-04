#!/bin/bash

# docker pull ubuntu:16.04
docker build -t ubuntu -f Dockerfile .
docker images
