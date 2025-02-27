import javax.swing.*;
import java.awt.*;

public class NewWindow extends JFrame {
    private ImageIcon bgImage;
    private JLabel imageLabel;

    public NewWindow() {
        setTitle("New Window");
        setSize(400, 300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        
        JPanel panel = new JPanel();
        panel.setLayout(null); 
        panel.setBackground(new Color(200, 230, 200));
        
        JLabel label = new JLabel("Mam 2 Marks");
        label.setBounds(80, 20, 250, 30);
        label.setFont(new Font("Arial", Font.BOLD, 20));
        label.setForeground(Color.BLUE);
        
        // Add image
        bgImage = new ImageIcon("./Cry.png"); 
        Image scaledImg = bgImage.getImage().getScaledInstance(200, 200, Image.SCALE_SMOOTH);
        imageLabel = new JLabel(new ImageIcon(scaledImg));
        imageLabel.setBounds(100, 60, 200, 200);
        
        panel.add(label);
        panel.add(imageLabel);
        add(panel);
    }
}