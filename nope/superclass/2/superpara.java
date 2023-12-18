

class a {
    int l, b;

    a(int u, int v) {
        l = u;
        b = v;
    }

}

class b extends a {
    int h;

    b(int u, int v, int w) {
        super(u, v);
        h = w;
    }
    int volume(){
        return l*b*h;
    }
}

public class superpara {
    public static void main(String[] args) {
        b obj = new b (20,30,40);
        int r=obj.volume();
        System.out.println("volume = "+ r);
    }
}
