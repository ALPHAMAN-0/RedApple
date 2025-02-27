package Basic;
public class Strings {
    public static void main(String[] args) {
        String name = "john weick";
        String name2 = "willston";
        System.out.println(name.toUpperCase());   // uppercase
        System.out.println(name.toLowerCase());   // lowercase

        System.out.println(name.length());          // length of string
        
        System.out.println(name.charAt(0));        // get character at index 0
        
        System.out.println(name.indexOf("w"));    // get index of character 'w'

        System.out.println(name.concat(name2));    // concatenate two strings

    }
}
