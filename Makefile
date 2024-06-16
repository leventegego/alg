
.PRECIOUS: bin/%.exe

bin/%.exe: src/%.cpp
	g++ $< -g -Wall -o $@

clean:
	-rm bin/*

run : bin/$(TARGET).exe
	$< < io/in > io/out


