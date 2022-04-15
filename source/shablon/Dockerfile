FROM ubuntu:latest
COPY shablon.cpp /Shablon.cpp
RUN apt-get update && apt-get -y install \
	g++ \
	nano
RUN g++ -o test Shablon.cpp
CMD ["./test"]
