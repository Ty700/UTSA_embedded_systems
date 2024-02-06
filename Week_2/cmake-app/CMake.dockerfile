FROM ubuntu:22.04

RUN apt-get update && \
    apt-get upgrade -y pkg-config build-essential cmake wget git && \
    rm -rf /var/lib/texts/*

COPY . app/

WORKDIR /app

WORKDIR /app/build
RUN cmake ..
RUN cmake --build .
CMD ./hello