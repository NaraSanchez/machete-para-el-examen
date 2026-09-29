public class MainBiblioteca {

    public static void main(String[] args) {

        // Constructor de conveniencia
        Libro libro1 = new Libro(
            "Clean Code",
            "Robert C. Martin",
            "9780132350884"
        );

        // Constructor canónico
        Libro libro2 = new Libro(
            "Efectivo con Java",
            "Ana Restrepo",
            "9781234567897",
            3,
            22000.0
        );

        // Constructor canónico
        Libro libro3 = new Libro(
            "Cien Años de Soledad",
            "Gabriel García Márquez",
            "9780307474728",
            2,
            18500.0
        );

        /*
         * new Libro();
         *
         * No compila porque al declarar nuestros propios
         * constructores, el constructor vacío que Java
         * creaba automáticamente deja de existir.
         */

        // ----------------------------------------
        // PRUEBA DE TÍTULO INVÁLIDO
        // ----------------------------------------

        Libro libroInvalido = new Libro(
            "",
            "Autor de prueba",
            "ISBN-000",
            1,
            15000.0
        );

        System.out.println(
            "Título guardado: " + libroInvalido.getTitulo()
        );

        // ----------------------------------------
        // PRUEBA DE PRECIO INVÁLIDO
        // ----------------------------------------

        boolean aceptado = libro1.setPrecioReposicion(-100.0);

        System.out.println(
            "¿Se aceptó el precio -100.0? "
            + aceptado
            + " (se mantiene el precio anterior)"
        );

        System.out.println(
            "Precio actual: $" + libro1.getPrecioReposicion()
        );

        // ----------------------------------------
        // MOSTRAR FICHAS
        // ----------------------------------------

        libro1.mostrarFicha();
        libro2.mostrarFicha();
        libro3.mostrarFicha();

        // ----------------------------------------
        // PRESTAR
        // ----------------------------------------

        System.out.println("--- Prueba de préstamos ---");

        boolean prestamo1 = libro1.prestar();

        System.out.println(
            "Resultado del préstamo: " + prestamo1
        );

        // Intentamos prestar otra vez sin copias
        boolean prestamo2 = libro1.prestar();

        System.out.println(
            "Resultado del segundo préstamo: " + prestamo2
        );

        // ----------------------------------------
        // DEVOLVER
        // ----------------------------------------

        libro1.devolver();

        // ----------------------------------------
        // CAMBIAR PRECIO CORRECTAMENTE
        // ----------------------------------------

        double precioAnterior = libro1.getPrecioReposicion();

        boolean cambioPrecio =
            libro1.setPrecioReposicion(18000.0);

        if (cambioPrecio) {

            System.out.println(
                "Precio de reposición actualizado de \"" +
                libro1.getTitulo() +
                "\": $" +
                precioAnterior +
                " -> $" +
                libro1.getPrecioReposicion()
            );
        }
    }
}
