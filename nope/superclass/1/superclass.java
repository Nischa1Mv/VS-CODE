
class a {
    int l, b;

    a() {
        l = 10;
        b = 20;
    }
}

class b extends a {
    int h;

    b() {
        super();
        h = 30;
    }

    int volume() {
        return l * b * h;
    }
}

public class superclass {
    public static void main(String[] args) {
        b B = new b();
        int r = B.volume();
        System.out.println(r);
    }
}
