/*
 *          SIAM HOSSAIN
 *          24-56637-1
 */
                                            // Book CLASS                       
 class Book {
    private String isbn, bookTitle, authorName;
    private double price;
    private int availableQuantity;

    public Book() {}
    public Book(String isbn, String bookTitle, String authorName, double price, int availableQuantity) {
        this.isbn = isbn;
        this.bookTitle = bookTitle;
        this.authorName = authorName;
        this.price = price;
        this.availableQuantity = availableQuantity;
    }

    // Setters and Getters
    public void setIsbn(String isbn) { this.isbn = isbn; }
    public void setBookTitle(String bookTitle) { this.bookTitle = bookTitle; }
    public void setAuthorName(String authorName) { this.authorName = authorName; }
    public void setPrice(double price) { this.price = price; }
    public void setAvailableQuantity(int availableQuantity) { this.availableQuantity = availableQuantity; }
    public String getIsbn() { return isbn; }
    public String getBookTitle() { return bookTitle; }
    public String getAuthorName() { return authorName; }
    public double getPrice() { return price; }
    public int getAvailableQuantity() { return availableQuantity; }


    public void addQuantity(int amount) {
        if(amount > 0) availableQuantity += amount;
        else System.out.println("Invalid Amount");
    }

    public void sellQuantity(int amount) {
        if(amount > 0 && amount <= availableQuantity) availableQuantity -= amount;
        else System.out.println("Invalid Amount");
    }

    public void showDetails() {
        System.out.println("ISBN: " + isbn);
        System.out.println("Title: " + bookTitle);
        System.out.println("Author: " + authorName);
        System.out.println("Price: " + price);
        System.out.println("Available: " + availableQuantity);
    }
}
                                            // TextBook CLASS
class TextBook extends Book {
    private int standard;
    
    public TextBook() { super(); }
    
    public TextBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, int standard) {
        super(isbn, bookTitle, authorName, price, availableQuantity);
        this.standard = standard;
    }
    
    public void setStandard(int standard) { this.standard = standard; }
    public int getStandard() { return standard; }
    
    @Override
    public void showDetails() {
        super.showDetails();
        System.out.println("Standard: " + standard);
    }
}
                                            // StoryBook CLASS
class StoryBook extends Book {
    private String category;
    
    public StoryBook() { super(); }
    
    public StoryBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, String category) {
        super(isbn, bookTitle, authorName, price, availableQuantity);
        this.category = category;
    }
    
    public void setCategory(String category) { this.category = category; }
    public String getCategory() { return category; }
    
    @Override
    public void showDetails() {
        super.showDetails();
        System.out.println("Category: " + category);
    }
}   
                                        // BookShop CLASS
class BookShop {
    private String name;
    private Book[] books;
    private int totalBooks;
    
    public BookShop() { books = new Book[100]; }
    public BookShop(String name) {
        this.name = name;
        books = new Book[100];
    }
    
    public void setName(String name) { this.name = name; }
    public String getName() { return name; }
    
    public boolean insertBook(Book book) {
        if(totalBooks < 100) {
            books[totalBooks++] = book;
            return true;
        }
        return false;
    }
    
    public boolean removeBook(Book book) {
        for(int i = 0; i < totalBooks; i++) {
            if(books[i].equals(book)) {
                books[i] = books[--totalBooks];
                return true;
            }
        }
        return false;
    }
    
    public void showAllBooks() {
        for(int i = 0; i < totalBooks; i++) {
            books[i].showDetails();
            System.out.println();
        }
    }
    
    public Book searchBook(String isbn) {
        for(int i = 0; i < totalBooks; i++) {
            if(books[i].getIsbn().equals(isbn)) {
                return books[i];
            }
        }
        return null;
    }
}

public class Start {
    public static void main(String[] args) {
        BookShop shop = new BookShop("My BookShop");
                                                            //pre input
        Book b1 = new Book("123", "Java Programming", "John Doe", 299.99, 10);
        TextBook t1 = new TextBook("456", "Math TextBook", "Jane Smith", 199.99, 5, 10);
        StoryBook s1 = new StoryBook("789", "The Adventure", "Bob Wilson", 149.99, 8, "Adventure");
        
        // Inserting Books
        shop.insertBook(b1);
        shop.insertBook(t1);
        shop.insertBook(s1);
        
        System.out.println("All Books:");
        // Showing All Books
        shop.showAllBooks();
        
        // searching book liner
        Book foundBook = shop.searchBook("456");
        if(foundBook != null) {
            System.out.println("\nFound Book:");
            foundBook.showDetails();
        }
        // quantity changes
        b1.addQuantity(5);
        t1.sellQuantity(2);
        
        System.out.println("\nAfter quantity changes:");
        shop.showAllBooks();
    }
}