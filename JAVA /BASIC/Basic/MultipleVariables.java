package Basic;
public class MultipleVariables {
    public static void main(String[] args){
        int x;
        int y;    // this error show beacuse y variable use memory but not use
        int j;
        x = y = j = 10;
        System.out.println("x: " + x);
    }
}
