FROM ubuntu:latest

RUN apt-get update && apt-get install -y gcc g++ cmake ninja-build
