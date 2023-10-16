class Rectangulo {
    int base;
    int altura;

    // Constructor default
    public Rectangulo() {
        base = 3;
        altura = 3;
    }

    public Rectangulo(int base, int altura) {
        this.base = base;
        this.altura = altura;
    }

    public int area() {
        return this.base * this.altura;
    }

    public int perimetro() {
        return 2 * (this.base + this.altura);
    }

    public void imprimir() {
        System.out.println("Base: " + this.base);
        System.out.println("Altura: " + this.altura);
        System.out.println("Area: " + this.area());
        System.out.println("Perimetro: " + this.perimetro());
    }

    public void figurita(){
         for (int i = 0; i < this.altura; i++) {
            for (int j = 0; j < this.base; j++) {
                if (i == 0 || i == this.altura - 1 || j == 0 || j == this.base - 1) {
                    System.out.print(" * ");
                } else {
                    System.out.print("   ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Rectangulo r1 = new Rectangulo();
        Rectangulo r2 = new Rectangulo(5, 7);
        System.out.println("Rectangulo 1");
        r1.imprimir();
        System.out.println("Rectangulo 2");
        r2.imprimir();
        System.out.println("Dibujo Rectangulo 1");
        r1.figurita();
        System.out.println("Dibujo Rectangulo 2");
        r2.figurita();
    }
}