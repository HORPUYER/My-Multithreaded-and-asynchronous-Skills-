FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    vim \
    && rm -rf /var/lib/apt/lists/*

COPY . /app
WORKDIR /app

RUN g++ -std=c++17 -o app taskgcc.cpp

CMD ["./app"]