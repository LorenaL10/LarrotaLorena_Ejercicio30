evolve_100.png: evolve_100.dat plot.py
	python plot.py
 
evolve_100.dat : evolve.x
	./evolve.x 100 > evolve_100.dat

evolve.x : evolve.cpp
	c++ evolve.cpp -o evolve.x

clean:
	rm evolve.x *.dat