abstract class shape {
    abstract double area();
}

class rectangle extends shape {
    double l = 12.5, b = 2.5;

    double area() {
        return l * b;
    }
}

class triangle extends shape {
    double b = 4.2, h = 6.5;

    double area() {
        return 0.5 * b * h;
    }
}

class square extends shape {
    double s = 6.5;

    double area() {
        return 4 * s;
    }
}

class shapedemo {
    public static void main(String[] args) {
        rectangle r1 = new rectangle();
        triangle t1 = new triangle();
        square s1 = new square();
        System.out.println("The area of rectangle is: " + r1.area());
        System.out.println("The area of triangle is: " + t1.area());
        System.out.println("The area of square is: " + s1.area());
    }
}
// Output:
// The area of rectangle is: 31.25
// The area of triangle is: 13.65 The
// area of square is: 26.0