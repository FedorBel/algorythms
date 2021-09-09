Create shared lib to load in python script

```
g++ -c -fPIC knights_tour.cpp -o knights_tour.o -O3
g++ -shared -Wl,-soname,libknights_tour.so -o libknights_tour.so knights_tour.o
```

Run Knights tour visualization

`python3 gui.py`