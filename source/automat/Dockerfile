FROM ubuntu:latest
COPY automat.cpp /Automat.cpp
RUN apt-get update && apt-get -y install \
	g++ \
	nano
RUN g++ -o test Automat.cpp
CMD ["./test"]
