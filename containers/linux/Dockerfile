ARG BASE_IMAGE=ubuntu
ARG IMAGE_VERSION=latest

FROM ${BASE_IMAGE}:${IMAGE_VERSION}

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y build-essential cmake && apt-get clean

VOLUME /root/env
WORKDIR /root/env

