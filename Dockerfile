FROM ubuntu:22.04

ENV CONTAINER_DIR=/os
WORKDIR ${CONTAINER_DIR}

ENV GIT_SSL_NO_VERIFY=1

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y upgrade && \
    apt-get --no-install-recommends -y install \
        build-essential \
        git \
    && apt-get clean

RUN git clone https://github.com/DaveGamble/cJSON.git /cJSON \
    && cd /cJSON \
    && make \
    && make install

COPY . ${CONTAINER_DIR}

VOLUME ${CONTAINER_DIR} 

CMD ["-m", "512"]