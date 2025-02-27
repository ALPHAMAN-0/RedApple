package DataType;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NonPrimitiveType {
    public static void main(String[] args) {
        // String - most common non-primitive type
        String name = "John Doe";
        
        // Array
        int[] numbers = {1, 2, 3, 4, 5};
        
        // Class
        Student student = new Student("Alice", 20);
        
        // Interface
        List<String> list = new ArrayList<>();
        
        // Print examples
        System.out.println("String: " + name);
        System.out.println("Array: " + Arrays.toString(numbers));
        System.out.println("Class object: " + student);
        
        // Add items to list
        list.add("Item 1");
        list.add("Item 2");
        System.out.println("List: " + list);
    }
}

class Student {
    String name;
    int age;
    
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    @Override
    public String toString() {
        return "Student{name='" + name + "', age=" + age + "}";
    }
}
