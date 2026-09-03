FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    bash \
    bc \
    binutils \
    bzip2 \
    cpio \
    file \
    git \
    graphviz \
    python3 \
    unzip \
    wget \
    libncurses-dev \
    rsync \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
