/*
 *               SIAM HOSSAIN
 *              ID 24-56637-1
 */
class Book{
    private String isbn;
    private String bookTitle;
    private String authorName;
    private double price;
    private int availableQuantity;

    Book(){
        //default constructor
    }
    Book(String isbn, String bookTitle, String authorName, double price, int availableQuantity){
        this.isbn = isbn;
        this.bookTitle = bookTitle;
        this.authorName = authorName;
        this.price = price;
        this.availableQuantity = availableQuantity;
    }

    public void setIsbn(String isbn){
        this.isbn = isbn;
    }
    public void setBookTitle(String bookTitle){
        this.bookTitle = bookTitle;
    }
    public void setAuthorName(String authorName){
        this.authorName = authorName;
    }
    public void setPrice(double price){
        this.price = price;
    }
    public void setAvailableQuantity(int availableQuantity){
        this.availableQuantity = availableQuantity;
    }

    public String getIsbn(){
        return isbn;
    }
    public String getBookTitle(){
        return bookTitle;
    }
    public String getAuthorName(){
        return authorName;
    }
    public double getPrice(){
        return price;
    }
    public int getAvailableQuantity(){
        return availableQuantity;
    }

    public void addQuantity(int amount){
        if(amount>0){
            availableQuantity += amount;
        }
        else{
            System.out.println("Invalid amount");
        }
    }

    public void sellQuantity(int amount){
        if(amount>0 && amount<=availableQuantity){
            availableQuantity -= amount;
        }
        else{
            System.out.println("Invalid amount");
        }
    }

    void showDetails(){
        System.out.println("ISBN: "+isbn);
        System.out.println("Book Title: "+bookTitle);
        System.out.println("Author Name: "+authorName);
        System.out.println("Price: "+price);
        System.out.println("Available Quantity: "+availableQuantity);
    }
}
//Child Class StoryBook
class StoryBook extends Book{
    private String category;
    StoryBook(){
        //default constructor
    }
    StoryBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, String category){
        super(isbn, bookTitle, authorName, price, availableQuantity);
        this.category = category;
    }

    public void setCategory(String category){
        this.category = category;
    }
    public String getCategory(){
        return category;
    }
}

//Child Class TextBook
class TextBook extends Book{
    private int standard;
    TextBook(){
        //default constructor
    }
    TextBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, int standard){
        super(isbn, bookTitle, authorName, price, availableQuantity);
        this.standard = standard;
    }

    public void setStandard(int standard){
        this.standard = standard;
    }
    public int getStandard(){
        return standard;
    }
}

public class Start {
    public static void main(String[] args){
        Book b1 = new Book("1234", "Java", "Mr. X", 100.0, 5);
        b1.showDetails();
        b1.addQuantity(5);
        b1.showDetails();
        b1.sellQuantity(3);
        b1.showDetails();

        System.out.println("Available Quantity: "+b1.getAvailableQuantity());
        System.out.println("Book Title: "+b1.getBookTitle());
        System.out.println("Author Name: "+b1.getAuthorName());
        System.out.println("Price: "+b1.getPrice());
        System.out.println("ISBN: "+b1.getIsbn());
        System.out.println();

        StoryBook sb1 = new StoryBook("1234", "Java", "Mr. X", 100.0, 5, "Horror");
        sb1.showDetails();
        sb1.addQuantity(5);
        sb1.showDetails();
        sb1.sellQuantity(3);
        sb1.showDetails();
        System.out.println("Available Quantity: "+sb1.getAvailableQuantity());
        System.out.println("Book Title: "+sb1.getBookTitle());
        System.out.println("Author Name: "+sb1.getAuthorName());
        System.out.println("Price: "+sb1.getPrice());
        System.out.println("ISBN: "+sb1.getIsbn());
        System.out.println("Category: "+sb1.getCategory());
        System.out.println();

        TextBook tb1 = new TextBook("1234", "Java", "Mr. X", 100.0, 5, 10);
        tb1.showDetails();
        tb1.addQuantity(5);
        tb1.showDetails();
        tb1.sellQuantity(3);
        tb1.showDetails();
        System.out.println("Available Quantity: "+tb1.getAvailableQuantity());
        System.out.println("Book Title: "+tb1.getBookTitle());
        System.out.println("Author Name: "+tb1.getAuthorName());
        System.out.println("Price: "+tb1.getPrice());
        System.out.println("ISBN: "+tb1.getIsbn());
        System.out.println("Standard: "+tb1.getStandard());
    }  
}
