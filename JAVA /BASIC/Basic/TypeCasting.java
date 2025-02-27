package Basic;
public class TypeCasting {
    public static void main(String[] args) {
         //byte -> short -> char -> int -> long -> float -> double  automatic
         int inteeger = 100;
         double decimal = inteeger; // automatic type casting
            System.out.println(decimal);
            
        //double -> float -> long -> int -> char -> short -> byte
        double decimal2 = 100.04;
        int integer2 = (int) decimal2; // manual type casting
            System.out.println(integer2);
        
    }
}