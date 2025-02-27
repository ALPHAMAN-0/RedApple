package OOP;
// how to create a class in java
class Pen{
    String color;
    String type; 
    
    public void write(){
        System.out.println("Writing...");
    }

    public void PrintColor(){
        System.out.println("Pen color: " + this.color);
    }

    public void PrintType(){
        System.out.println("Pen type: " + this.type);   //this object variable and method access help to access the object variable and method
    }

}

// how to use constructor in java
class Student{
    String name;
    int age;

    Student(){
        System.out.println("Student object created");   // default constructor
    }

    Student(String name, int age){     // parameterized constructor
        this.name = name;
        this.age = age;
    }

    public void printDetails(){
        System.out.println("Name: " + this.name + " Age: " + this.age);
    }
}

//How to copy one object to another object
class Employee{
    String name;
    int age;

    Employee() {
        // default constructor
    }
    public void PrintInfo(){
        System.out.println("Name: " + this.name + " Age: " + this.age);
    }
    Employee(Employee s2){
        this.name = s2.name;
        this.age = s2.age;
    }

}
public class BluePrint {
    public static void main(String[] args){
        
        Pen pen1 = new Pen();
        pen1.color = "Red";
        pen1.type = "gel";
        pen1.write();

        pen1.PrintColor();
        pen1.PrintType();
            
        Student student1 = new Student("Rohan",20);
        student1.printDetails();

        Employee e1 = new Employee();
        e1.name = "Rohan";
        e1.age = 20;

        Employee e2 = new Employee(e1);
        e2.PrintInfo();   

    }
}
