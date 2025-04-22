FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    vim \
    && rm -rf /var/lib/apt/lists/*

COPY . /app
WORKDIR /app

RUN g++ -o hello hello.cpp

EXPOSE 8001
CMD ["./hello"]