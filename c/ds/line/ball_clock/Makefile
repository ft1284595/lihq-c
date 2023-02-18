all:ball_clock

ball_clock:main.o sqstack.o squeue.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o ball_clock
