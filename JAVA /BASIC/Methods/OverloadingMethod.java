package Methods;

public class OverloadingMethod {
    static int plusMethod(int x, int y){
        return x + y;
    }

    static double plusMethod(double x, double y){
        return x + y;
    }

    public static void main(String[] args){
        int myInt = plusMethod(8, 5);
        double myDouble = plusMethod(4.3, 6.26);
        System.out.println("int: " + myInt);
        System.out.println("double: " + myDouble);
    }
}
