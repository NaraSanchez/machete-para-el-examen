public class MainInventario {

    public static void main(String[] args) {

        // Crear el primer producto
        Producto productoUno = new Producto();
        productoUno.nombre = "Teclado mecánico";
        productoUno.codigo = "P-001";
        productoUno.precio = 45000.0;
        productoUno.stock = 12;

        // Crear el segundo producto
        Producto productoDos = new Producto();
        productoDos.nombre = "Mouse inalámbrico";
        productoDos.codigo = "P-002";
        productoDos.precio = 25000.0;
        productoDos.stock = 20;

        // Crear el tercer producto
        Producto productoTres = new Producto();
        productoTres.nombre = "Monitor 24 pulgadas";
        productoTres.codigo = "P-003";
        productoTres.precio = 180000.0;
        productoTres.stock = 8;

        // Mostrar ficha del productoUno
        productoUno.mostrarFicha();

        // Vender unidades
        productoUno.venderUnidades(3);

        // Intentar vender más unidades de las disponibles
        productoUno.venderUnidades(50);

        // Reponer stock
        productoUno.reponerStock(20);

        // Actualizar precio
        productoUno.actualizarPrecio(39900.0);

        // Comprobar que cada objeto tiene su propio stock
        System.out.println();
        System.out.println("=== Verificación de objetos independientes ===");
        System.out.println("Stock de productoUno: " + productoUno.stock);
        System.out.println("Stock de productoDos: " + productoDos.stock);
        System.out.println("Stock de productoTres: " + productoTres.stock);

        // Demostración de aliasing
        Producto copia = productoUno;

        copia.stock = 29;

        System.out.println();
        System.out.println("Stock de productoUno tras modificar copia: "
                + productoUno.stock
                + " (mismo objeto en el Heap)");
    }
}
