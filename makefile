app: main.cpp
	g++ main.cpp `wx-config --cxxflags --libs`  -o app.out

clean: 
	rm app.out
