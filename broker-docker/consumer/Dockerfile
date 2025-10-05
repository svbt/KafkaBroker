FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y \
    g++ cmake make librdkafka-dev libboost-all-dev nlohmann-json3-dev git \
    && rm -rf /var/lib/apt/lists/*

# Build cppkafka manually (Debian doesn't have a package either, but building works cleanly)
WORKDIR /tmp
RUN git clone https://github.com/mfontanini/cppkafka.git && \
    cd cppkafka && mkdir build && cd build && \
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr && \
    make -j$(nproc) && make install

WORKDIR /app
COPY . .
RUN cmake -B build -S . && cmake --build build

CMD ["./build/consumer"]
