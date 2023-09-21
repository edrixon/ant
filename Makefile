ant: ant.c
	gcc -o ant ant.c ../client/client.o

clean:
	rm -f ant

install: ant
	cp ant /opt/radio/bin
	chmod 755 /opt/radio/bin/ant
