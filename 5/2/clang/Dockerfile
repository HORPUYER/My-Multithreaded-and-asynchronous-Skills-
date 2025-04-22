FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
    clang \
    vim \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN clang++ -std=c++14 -o main taskclang.cpp

CMD ["./main"]