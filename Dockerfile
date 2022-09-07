FROM alpine:latest

RUN apk update && \
    apk upgrade && \
    apk --update add \
        gcc \
        g++ \
        build-base \
        cmake \
        bash \
        libstdc++ \
        cppcheck && \
        rm -rf /var/cache/apk/*

WORKDIR /src

COPY /src/CMakeLists.txt /src/philosophers.cpp ./

RUN g++ philosophers.cpp -lpthread -o philosophers -Wall

CMD ["./philosophers"]