Main: Main.o Tienda.o Producto.o Cliente.o Venta.o DetalleVenta.o
	g++ -o Main Main.o Tienda.o Producto.o Cliente.o Venta.o DetalleVenta.o
Main.o: main.cpp tienda.h producto.h cliente.h detalleVenta.h licor.h venta.h
	g++ -c main.cpp
Tienda.o: tienda.cpp tienda.h
	g++ -c tienda.cpp
Producto.o: producto.cpp producto.h
	g++ -c producto.cpp
Cliente.o: cliente.cpp cliente.h
	g++ -c cliente.cpp
Venta.o: venta.cpp venta.h
	g++ -c venta.cpp
DetalleVenta.o: detalleVenta.cpp detalleVenta.h
	g++ -c detalleVenta.cpp
clean:
	rm -f Main Main.o Tienda.o Producto.o