FROM ubuntu:22.04

ENV CONTAINER_DIR=/os
WORKDIR ${CONTAINER_DIR}

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y upgrade && \
    apt-get --no-install-recommends -y install \
        build-essential \
    && apt-get clean


COPY . ${CONTAINER_DIR}

VOLUME ${CONTAINER_DIR}

CMD ["-m", "512"]