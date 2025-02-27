import java.util.ArrayList;

public class Start {

    static class Book {
        private String isbn;
        private String bookTitle;
        private String authorName;
        private double price;
        private int availableQuantity;
    
        public Book() {
        }
    
        public Book(String isbn, String bookTitle, String authorName, double price, int availableQuantity) {
            this.isbn = isbn;
            this.bookTitle = bookTitle;
            this.authorName = authorName;
            this.price = price;
            this.availableQuantity = availableQuantity;
        }
    
        public void setIsbn(String isbn) {
            this.isbn = isbn;
        }
        public void setBookTitle(String bookTitle) {
            this.bookTitle = bookTitle;
        }
        public void setAuthorName(String authorName) {
            this.authorName = authorName;
        }
    
        public void setPrice(double price) {
            this.price = price;
        }
    
        public void setAvailableQuantity(int availableQuantity) {
            this.availableQuantity = availableQuantity;
        }
    
        public String getIsbn() {
            return isbn;
        }
        public String getBookTitle() {
            return bookTitle;
        }
        public String getAuthorName() {
            return authorName;
        }
        public double getPrice() {
            return price;
        }
    
        public int getAvailableQuantity() {
            return availableQuantity;
        }
    
        public void addQuantity(int amount) {
            if (amount > 0) {
                availableQuantity += amount;
            } else {
                System.out.println("Invalid Amount");
            }
        }
    
        public void sellQuantity(int amount) {
            if (amount > 0 && amount <= availableQuantity) {
                availableQuantity -= amount;
            } else {
                System.out.println("Invalid Amount");
            }
        }
    
        public void showDetails() {
            System.out.println("ISBN: " + isbn);
            System.out.println("Book Title: " + bookTitle);
            System.out.println("Author Name: " + authorName);
            System.out.println("Price: " + price);
            System.out.println("Available Quantity: " + availableQuantity);
        }
    }
    
    static class TextBook extends Book {
        private int standard;
    
        public TextBook() {
        }
    
        public TextBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, int standard) {
            super(isbn, bookTitle, authorName, price, availableQuantity);
            this.standard = standard;
        }
    
        public void setStandard(int standard) {
            this.standard = standard;
        }
    
        public int getStandard() {
            return standard;
        }
    
        @Override
        public void showDetails() {
            super.showDetails();
            System.out.println("Standard: " + standard);
        }
    }
    static class StoryBook extends Book {
        private String category;
    
        public StoryBook() {
        }
    
        public StoryBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, String category) {
            super(isbn, bookTitle, authorName, price, availableQuantity);
            this.category = category;
        }
    
        public void setCategory(String category) {
            this.category = category;
        }
    
        public String getCategory() {
            return category;
        }
    
        @Override
        public void showDetails() {
            super.showDetails();
            System.out.println("Category: " + category);
        }
    }
static class BookShop {
    private String name;
    private ArrayList<Book> books;

    public BookShop(String name) {
        this.name = name;
        this.books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void showAllBooks() {
        for (Book book : books) {
            book.showDetails();
            System.out.println();
        }
    }

    public Book findBookByISBN(String isbn) {
        for (Book book : books) {
            if (book.getIsbn().equals(isbn)) {
                return book;
            }
        }
        return null;
    }
}

public static void main(String[] args) {
    BookShop shop = new BookShop("My Book Shop");

        Book book1 = new Book("123", "Java Programming", "Author A", 500.0, 10);
        TextBook book2 = new TextBook("456", "Advanced Java", "Author B", 600.0, 5, 12);
        StoryBook book3 = new StoryBook("789", "Fairy Tales", "Author C", 300.0, 8, "Fantasy");

        shop.addBook(book1);
        shop.addBook(book2);
        shop.addBook(book3);

        shop.showAllBooks();

        Book foundBook = shop.findBookByISBN("123");
        if (foundBook != null) {
            System.out.println("Book found:");
            foundBook.showDetails();
        } else {
            System.out.println("Book not found.");
        }
    }
}