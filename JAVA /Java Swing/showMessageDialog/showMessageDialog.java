import javax.swing.*;
public class showMessageDialog {
    public static void main(String[] args) {
      ImageIcon img = new ImageIcon("Bank.jpg");
     // Display a simple message dialog
     JOptionPane.showMessageDialog(null, "Hello, World!");
    // Information Message
     JOptionPane.showMessageDialog(null, "This is an information message.", "Information", JOptionPane.INFORMATION_MESSAGE,img);

     // Warning Message
     JOptionPane.showMessageDialog(null, "This is a warning message.", "Warning", JOptionPane.WARNING_MESSAGE);

     // Error Message
     JOptionPane.showMessageDialog(null, "This is an error message.", "Error", JOptionPane.ERROR_MESSAGE);

     // Plain Message
     JOptionPane.showMessageDialog(null, "This is a plain message.", "Plain", JOptionPane.PLAIN_MESSAGE);
     //question message
      JOptionPane.showMessageDialog(null, "This is a question message.", "Question", JOptionPane.QUESTION_MESSAGE);
    }
}
